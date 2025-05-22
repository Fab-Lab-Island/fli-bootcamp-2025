# ATtiny 412 Programmer Breakout Board

Þetta er lítið sniðugt bretti sem er hægt að nota til þess að forrita ATtiny 412 áður en hann er lóðaður á bretti.

Það er mjög sniðugt því þá þarf ekki að lóða sérstaklega forritunar-pinna á brettið sem ATtiny kubburinn á að vera á.

## ATtiny412 Breakout bretti
![Breakout board](../assets/img/ATtiny412BreakoutBoard/412BreakoutBoard.jpeg)
///caption
ATtiny412 Breakout Bretti
///

Brettið er ofur einfalt. Það er einn 1uF capacitor, fótspor fyrir ATtiny412 og þrír pinnar.

![Breakout board components](../assets/img/ATtiny412BreakoutBoard/412BreakoutBoardInkscape.jpeg)
///caption
ATtiny412 Breakout Bretti íhlutir
///

## Serial-UPDI 3-pin millistykki

![Serial-UPDI 3-pin millistykki](https://academy.cba.mit.edu/classes/embedded_programming/UPDI/hello.serial-UPDI.3.png)
///caption
Serial-UPDI 3-pin millistykki
///

![Serial-UPDI 3-pin millistykki](https://academy.cba.mit.edu/classes/embedded_programming/UPDI/hello.serial-UPDI.3.jpg)
///caption
Serial-UPDI 3-pin millistykki
///

Hér er hægt að sækja skrárnar sem þarf til að fræsa út millistykkið

[Download Trace .png file](https://academy.cba.mit.edu/classes/embedded_programming/UPDI/hello.serial-UPDI.3.traces.png) 

[Download Cut .png file](https://academy.cba.mit.edu/classes/embedded_programming/UPDI/hello.serial-UPDI.3.interior.png) 

## Forrita ATtiny412

Til þess að forrita ATtiny412 þá þarf að halda kubbnum þétt upp að fótsporunum, (VCC og GND næst þéttinum), svo eru pinnunum þremur tengt í Serial-UPDI 3-pin millistykkið og millistykkið tengt til FTDI-USB snúru. Svo er ATtiny412 kubburinn forritaður í gegnum Arduino IDE.

![Forrita ATtiny412](../assets/img/ATtiny412BreakoutBoard/Programming412WithBreakoutBoard.jpeg)
///caption
ATtiny412 forritaður með breakout brettinu, Serial-UPDI millistykki og FTDI-USB snúru
///

