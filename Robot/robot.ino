#include "robot.h"
#include "motor_control.h"
#include "colour_detector.h"
#include "compass.h"



Robot* robot;

void setup() {
  robot = new Robot();
  Serial.begin(9600);
  robot->leave_box();
  
  
}

void loop() {

  while(millis() < 420000 && loop_count < 8) {
    robot->hello();
  }
  robot->go_home();
  break;

  //robot->emergency();
  
}
