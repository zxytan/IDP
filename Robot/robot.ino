#include "robot.h"
#include "motor_control.h"
#include "colour_detector.h"
#include "compass.h"

Robot robot;

void setup() {
  // put your setup code here, to run once:
  robot.init();
 // leave_box(); - error: leave_box was not declared in this scope 
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //main_loop(); - error main_loop was not declared in this scope
}
