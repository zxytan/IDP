#include "robot.h"
#include "motor_control.h"
#include "colour_detector.h"
#include "compass.h"

Robot robot;

void setup() {
  // put your setup code here, to run once:
  robot.init();
  robot.leave_box();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  robot.hello();
}
