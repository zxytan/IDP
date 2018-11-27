
#include "motor_control.h"
  
MotorController::MotorController(uint8_t left_motor_port, uint8_t right_motor_port):AFMS(),left_motor(AFMS.getMotor(left_motor_port)),right_motor(AFMS.getMotor(right_motor_port)){}

void MotorController::init(){
  AFMS.begin();
  stop();
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);
}

void MotorController::side_prox_error(long target) {
  float Kp = 3;
  /*
  digitalWrite(TRIG_PIN_2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_2, LOW);
  
  float duration = pulseIn(ECHO_PIN_2, HIGH);
  float distance = (duration/2) / 29.1;

  int error = target - distance;
  */
  float bearing = compass.get_heading();
  
  
  correction = -error*Kp;
}
void MotorController::forward(uint8_t motor_speed){
  left_motor->setSpeed(motor_speed);
  right_motor->setSpeed(motor_speed - 20 - correction);
  left_motor->run(FORWARD);
  right_motor->run(FORWARD);
}

void MotorController::reverse(uint8_t motor_speed){
  left_motor->setSpeed(motor_speed);
  right_motor->setSpeed(motor_speed - 20);

  left_motor->run(BACKWARD);
  right_motor->run(BACKWARD);
}

void MotorController::rotate_right(uint8_t motor_speed){
  left_motor->setSpeed(motor_speed);
  right_motor->setSpeed(motor_speed);

  left_motor->run(BACKWARD);
  right_motor->run(FORWARD);
}

void MotorController::rotate_left(uint8_t motor_speed){
  left_motor->setSpeed(motor_speed);

  right_motor->setSpeed(motor_speed);

  left_motor->run(FORWARD);
  right_motor->run(BACKWARD);
}

void MotorController::stop(){
  left_motor->run(RELEASE);
  right_motor->run(RELEASE);  
}
