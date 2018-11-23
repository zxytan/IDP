#include "robot.h"
#include "motor_control.h"

Robot::Robot():motor_control(left_motor_port, right_motor_port) {
  loop_count = 0;
  Compass compass;
  servo_right.attach(9);
  servo_left.attach(10);
};
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
