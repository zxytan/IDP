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

  robot->emergency();
  //robot->test();
/*
  long robot_time = millis();
  while(robot_time < 420000) {
    if(robot->hello()){
      robot_time = 420001;
    }else{
      robot_time = millis();
    }
  }
  Serial.println("going home");
  robot->go_home();
  
  while(1){}
  */
  
  
}
