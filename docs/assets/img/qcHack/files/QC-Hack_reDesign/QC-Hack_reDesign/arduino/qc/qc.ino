/*
 * Author: Nicolas H.-P. De Coster
 * 
 * License: CC BY-NC-SA 4.0
 *          https://creativecommons.org/licenses/by-nc-sa/4.0/
 * 
 * Purpose: Arduino sketch for controlling QC (Quick Charge) 
 *          and getting "any" voltage from (compatible) USB chargers.
 * 
 * This sketch performs QC handshake for power negotiation.
 * It controls the D+ and D- pins to achieve the desired voltage 
 * based on the QC protocol.
 * 
 * The sketch was designed for the atTiny12 with very minimalistic hardware,
 * and uses only ~30% of program memory and ~3% of dynamic memory, leaving room
 * for any user project addition (or fits in atTiny212/202) :
 *   - D+ voltages (0.6V and 3.3V) are obtained by a resistor divider
 *    (2.2k and 10k on 3.3v VDD) and input (0.6v from bridge) 
 *    or output (0v and 3.3v) configuration.
 *   - D- voltages are obtained by using DAC output (with automatic reference)
 *     for 0.6V and digital output configuration (for 0v and 3.3v)
 *     Theses voltages could also be obtained by the samed trick as for D+ pin,
 *     then requiring 2 external resistors more (and increasing slightly 
 *     power consumption)
 * 
 * /!\ (I M P O R T A N T) /!\ *
 * -----------------------------
 * Notes:
 * - Set the MAX_LDO_DCV definition to avoid burning your LDO (and more?)!
 *   Your LDO may not be able to withstand the voltage delivered by the USB QC 
 *   (up to 20V!). Better check its maximum value to protect your code. 
 *   And/Or choose a high Vin capable LDO (like LM3480 [max 30V]).
 * - If you don't use an external pot, adjust the TARGET_DCV and other constants.
 * - The design is based on 3.3V VDD to ease D+/D- configuration : 
 *   a 5V configuration would require small adjustments.
 * 
 * Versions:
 * - 1.0 (2023-09-29): Initial version (testing purposes)
 * - 2.0 (2024-03-03): redesigned board with adjustable potentiometer and feedback
 * 
 * Usefull references and documents : 
 * - CHY100 - QC2.0 - Datasheet 
 *   https://www.mouser.com/datasheet/2/328/chiphy_family_datasheet-269468.pdf
 * - CHY103 - QC3.0 - Datasheet 
 *   https://www.mouser.com/datasheet/2/328/CHY103_family_datasheet-770737.pd)
 * - NCP4371 - QC3.0 - Datasheet
 *   https://www.onsemi.com/pdf/datasheet/ncp4371-d.pdf
 * - The first hack that inspired me the idea
 *   https://www.hackster.io/PSoC_Rocks/hacking-qualcomm-quick-charge-qc-2-0-3-0-with-attiny85-b7627d
 * - A more detailed description of QC3.0 and continuous mode
 *   http://blog.deconinck.info/post/2017/08/09/Turning-a-Quick-Charge-3.0-charger-into-a-variable-voltage-power-supply
 */ 

//From https://www.hackster.io/PSoC_Rocks/hacking-qualcomm-quick-charge-qc-2-0-3-0-with-attiny85-b7627d : 
///========================= Algorithm ========================/// 

/*
  First, Connect the D+ pin to a voltage 0.325 to 2 volts and keep the D- floating, then wait at least 2 seconds.

  Two actions happen during this 2 seconds:

  The D+ and D- voltage equal a voltage between 0.325 to 2 volts for 1.25 seconds.
  (because the D+ and D- pins connect together inside the CHY100 at first)

  Then the D+ keeps at a voltage between 0.325 to 2 volts and the D- voltage decrease to zero.
  (because the D+ and D- pins disconnect and a resistor inside the CHY100 discharges the D-)*** CHY100 is a QC 2.0 Protocol interface chip inside Power bank/charger ........ other QC 2.0 chips are probably similar 

  Make D+ above 3.0 V first and then connect the D- to a voltage between 0.325 to 2 volts. The VBUS jumps to 9V.

  While keeping the D- connection with a voltage between 0.325 to 2 volts,make D+  a voltage between 0.325 to 2 volts.
  The VBUS jumps to 12V. (because the D+ and D- voltage are between 2V and 0.325V)

  Disconnect the D+ from a voltage between 0.325 to 2 volts . VBUS jumps to 5V, Because the QC2.0 exits Voltage changing
  mode and VBUS goes to the default value 5V. start from beginning when needing to enter QC2.0 again)
*/
//  ============  IMPORTANT NOTE ================  //

// *** Sequence of making pins HIGH and LOW is important
// *** If D+ falls below 0.325V during transition because of wrong GPIO Switching Sequence
// *** QC 2.0 will exit High Voltage Mode and VBUS will go back to 5 Volts 

//  ==============================================  //
/*
TODO :
 - check loop validity (new target when gap > 0.2V)
 - use feedback even when pot used
 - avoid multi adjustment when over or under range (target unreachable)
 - all code working in dcV made too complicated when no TARGET_DCV? : simplify would require refactor
 - make the code Apple-compatible? (for higher currents)
*/

#include <avr/sleep.h>

//standard QC2.0 are 50 (5V), 90 (9V), 120 (12V) or 200 (20V)
//anny other will work using QC3.0  
//#define TARGET_DCV 120

#define CLASSA 120 //Class A QC is up to 12V
#define CLASSB 200 //Class B QC is up to 20V (so far?)

//select the class you want to use
// Class A : 3.6V-12V
// Class B : 3.6V-20V
#define USE_CLASS CLASSA  //[CLASSA,CLASSB]

//pre-defined LDO max (in dcV)
#define MAX_AZ1117  150
#define MAX_MCP1703 160
#define MAX_MCP1799 450
#define MAX_LM3480  300

//IMPORTANT! Define the maximum input dcV of your LDO (//will be truncated to 255 if >255)
#define MAX_LDO_DCV MAX_LM3480

#define QC_T_HANDSHAKE 2000
#define QC_T_GLICH_V_CHANGE_MS 60
#define QC_CONTINUOUS_PULSE_MS  5
#define DN DAC_PIN
#define DP      2
#define PIN_POT 1   //pin connected to the potentiometer
#define PIN_SENSE   4   //pin for reading actual volage (trhough 1/11 bridge divider)

#if defined(INTERNAL1V024)
  #define REFERENCE INTERNAL1V024
  #define DAC_600MV 150  //~0.6V = 1.024V*150/255 with 1.024V reference
#elif defined(INTERNAL1V1)
  #define REFERENCE INTERNAL1V1
  #define DAC_600MV 139 //~0.6V = 1.1V*139/255 with 1.1V reference
#elif defined(INTERNAL1V5)
  #define REFERENCE INTERNAL1V5
  #define DAC_600MV 102 //~0.6V = 1.5V*102/255 with 1.5V reference
#elif defined(INTERNAL2V048)
  #define REFERENCE INTERNAL2V048
  #define DAC_600MV 75  //~0.6V = 2.048V*75/255 with 2.048V reference
#elif defined(INTERNAL2V5)
  #define REFERENCE INTERNAL2V5
  #define DAC_600MV 61  //~0.6V = 2.5V*61/255 with 2.5V reference
#endif
  
//avoid letting unused pins floating

#define FREE 3

#define CLASSB_OFFSET 16 //to start at 16dcV (1.6V) and end at 192dcV (=3/4*256) + 16dcV (=20.8V)
#define CLASSA_OFFSET 28 //to start at 28dcV (2.8V) and end at 96dcV (=3/4*128) + 28dcV (=12.4V)

#if MAX_LDO_DCV < 205
    #define MAX_DCV MAX_LDO_DCV
#else
    #define MAX_DCV 205
#endif

#if USE_CLASS != CLASSB
  #define MAX_DV CLASSA
#endif

////////////////////////////
// M A I N   P R O G R A M
////////////////////////////

uint8_t targetDcv;

void setup()
{
  //avoid free pins to float (saves power)
  pinMode(FREE, INPUT_PULLUP);
  //set internal DAC reference
  DACReference(REFERENCE);

  // Now Initiating QC Handshake by making D+ 0.6 v keeping D- at Gnd
  Init_QC();

//if potentiometer is used instead of preset target
#ifdef TARGET_DCV
  targetDcv = TARGET_DCV;
#else
  targetDcv = getPotTargetVal(PIN_POT);
#endif

  setQCdcV(targetDcv);
}


void loop()
{

#ifndef TARGET_DCV
  uint8_t midDiff;  //to store half the difference (id dcV) because 2dcV steps
  uint8_t i;        //for loops

  uint8_t currDcv   = getSenseVal(PIN_SENSE);
  targetDcv = getPotTargetVal(PIN_POT);

  if(targetDcv > (currDcv + 1)){
    midDiff = (targetDcv - currDcv) >> 1;
    for(i=0; i < midDiff; i++){
      QCVoltageIncrease02();
    }
  }
  else if(targetDcv < (currDcv - 1)){
    midDiff = (currDcv - targetDcv) >> 1;
    for(i=0; i < midDiff; i++){
      QCVoltageDecrease02();
    }
  }
  delay(QC_T_GLICH_V_CHANGE_MS);

#else
  while(1){}; //wait forever
#endif


  //TODO : check why this sleep doesn't work
  //sleep tight, little tiny
  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_enable();
  sleep_cpu();
}


/////////
// get the 8 bits value from potentimeter on pin,
// in the interval [CLASSB_OFFSET; (3/4)*pot + CLASSB_OFFSET] = ~[16;208] = [1.6V - 20.8V]
/////////
uint8_t getPotTargetVal(uint8_t pin){
  uint16_t val = analogRead(pin);
  val -= (val >> 2);      // *3/4
  val >>= 2;              // reduce 10bits to 8bits value
#if USE_CLASS == CLASSA
  val >>= 1; //128 values are enough, make it 7bits
  val += CLASSA_OFFSET;
#else
  val += CLASSB_OFFSET;  // put an offset for better potentiometer range (not start to 0)
#endif
  if(val > MAX_DCV){val = MAX_DCV;} //avoid going higher than maximum
  return (uint8_t)val;
}

uint8_t getSenseVal(uint8_t pin){
  uint16_t val = analogRead(pin);
  //multiply value by 11(voltage devider)*33(VDD in dcV)/1023(ADC range) ~= *0.355
  //this can be "quite quickly" achieved by *(1+1/2-1/16-1/32+1/64)/4 ~= *0.355
  uint16_t shift = val >> 1;  //shift = (original val)/2
  val += shift; // val is now val*1.5 (1+1/2)
  shift >>= 3 ; // shift = (original val)/16
  val -= shift; // val is now val*1.4375 (1+1/2-1/16)
  shift >>= 1 ; // shift = (original val)/32
  val -= shift; // val is now val*1.40625 (1+1/2-1/16-1/32)
  shift >>= 1 ; // shift = (original val)/64
  val += shift; // val is now val*1.421875 (1+1/2-1/16-1/32+1/64)
  // reduce 10bits to 8bits value : val is now val*0.35546875
  // (instead of 0.35483871 : good approximation)
  val >>= 2;
  return (uint8_t)val;
}


////////
//D+ pin (resistors bridge controlled)
////////
inline void dp0mV(){
  digitalWrite(DP,LOW);
  pinMode(DP,OUTPUT);
}
inline void dp600mV(){
  pinMode(DP,INPUT);
}
inline void dp3300mV(){
  digitalWrite(DP,HIGH); \
  pinMode(DP,OUTPUT);
}

////////
//D- pin (DAC controlled)
////////

//set pin to zero by making it a low output
inline void dm0mV(){
  digitalWrite(DN, LOW);pinMode(DN,OUTPUT);
}

//set pin to zero by writing DAC value
inline void dm600mV(){
  analogWrite(DN, DAC_600MV);
}

//set pin to zero by making it a high output
inline void dm3300mV(){
  digitalWrite(DN, HIGH);pinMode(DN,OUTPUT);
}

void Init_QC()
{
  //make D- pin float
  pinMode(DN, INPUT);
  //write 0.6V on D+
  dp600mV();
  //wait (at least) 2sec
  delay(QC_T_HANDSHAKE);
  // now QC protocol is active
}

void QCVoltageDecrease02(){
  dm600mV();
  delay(QC_CONTINUOUS_PULSE_MS);
  dm3300mV();
  delay(QC_CONTINUOUS_PULSE_MS);
}

void QCVoltageIncrease02(){
  dp3300mV();
  delay(QC_CONTINUOUS_PULSE_MS);
  dp600mV();
  delay(QC_CONTINUOUS_PULSE_MS);
}

void setQCdcV(uint8_t dcV){
  //see CHY100 datasheet (Table 1 - Output Voltage Lookup Table)
  //https://www.mouser.be/datasheet/2/328/chiphy_family_datasheet_269468-3198404.pdf
  
  if(dcV > MAX_DCV){
    dcV = MAX_DCV;
  }
  //5.0V
  if (dcV == 50) {
    dp600mV();
    dm0mV();
  }
  //9.0V
  else if (dcV == 90) {
    dp3300mV();
    dm600mV();
  }
  //12.0V
  else if (dcV == 120) {
    dp600mV();
    dm600mV();
  }
  //20.0V
  else if (dcV == 200) {
    dp3300mV();
    dm3300mV();
  }
  //other (via QC3.0 +-200mV steps)
  else {
    uint8_t dcVNow = 50;

    //speed up rise for dcVs > 120
    if(dcV >= 120){
      dp600mV();
      dm600mV();
      dcVNow = 120;
      delay(QC_T_GLICH_V_CHANGE_MS);
    }

    //enter continuous mode
    dm3300mV();
    delay(QC_T_GLICH_V_CHANGE_MS);


    if(dcV > dcVNow){
      for(;dcVNow < dcV; dcVNow+=2){
        QCVoltageIncrease02();
      }
    }
    else{
      for(;dcVNow > dcV; dcVNow-=2){
        QCVoltageDecrease02();
      }
    }
  }
  delay(QC_T_GLICH_V_CHANGE_MS);
}
