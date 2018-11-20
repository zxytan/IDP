#include "Robot.h"

void Robot::leave_box() {
	motor_control.forward(SPEED);
	delay(5000); //check
	motor_control.stop();
}

//set up pins

void Robot::init() {
  Serial.begin (9600);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);

  motor_control.init();
  
}
