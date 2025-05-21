w = 17.9;
l = 29.7;
th = 0.4;
e = 0.01;

difference(){
  cube([w,l,th]);
  translate([0,0,-e])linear_extrude(th+2*e)import("QC_Fab-brd.svg");
}