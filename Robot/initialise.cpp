#include "robot.h"
#include "motor_control.h"

Robot::Robot():motor_control(left_motor_port, right_motor_port) {
  loop_count = 0;
  Compass compass;
  servo_right.attach(9);
  servo_left.attach(10);
};
void Robot::leave_box() {
  for (int i = 0; i < 10 ; ++i) {
    float side_prox = get_prox_reading(LEFT_PROX);
    motor_control.side_prox_error(side_prox);
	  motor_control.forward(SPEED);
	  delay(1000); //check
  }
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
