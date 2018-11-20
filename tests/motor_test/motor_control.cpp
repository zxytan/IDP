
#include "motor_control.h"
  
MotorController::MotorController(uint8_t left_motor_port, uint8_t right_motor_port):AFMS(),left_motor(AFMS.getMotor(left_motor_port)),right_motor(AFMS.getMotor(right_motor_port)){}

int correction = 5;

void MotorController::init(){
  AFMS.begin();
  stop();
}
  
void MotorController::forward(uint8_t motor_speed){
  left_motor->setSpeed(motor_speed);
<<<<<<< HEAD
  right_motor->setSpeed(motor_speed+correction);
=======
  right_motor->setSpeed(motor_speed);
>>>>>>> 3002af08986dbafcff2bd57e40514a4a8963f0e1
  left_motor->run(BACKWARD);
  right_motor->run(BACKWARD);
}


void MotorController::reverse(uint8_t motor_speed){
  left_motor->setSpeed(motor_speed);
<<<<<<< HEAD
  right_motor->setSpeed(motor_speed + correction);
=======
  right_motor->setSpeed(motor_speed);
>>>>>>> 3002af08986dbafcff2bd57e40514a4a8963f0e1
  left_motor->run(FORWARD);
  right_motor->run(FORWARD);
}

void MotorController::rotate_right(uint8_t motor_speed){
  left_motor->setSpeed(motor_speed);
<<<<<<< HEAD
  right_motor->setSpeed(motor_speed + correction);
=======
  right_motor->setSpeed(motor_speed);
>>>>>>> 3002af08986dbafcff2bd57e40514a4a8963f0e1
  left_motor->run(BACKWARD);
  right_motor->run(FORWARD);
}

void MotorController::rotate_left(uint8_t motor_speed){
  left_motor->setSpeed(motor_speed);
<<<<<<< HEAD
  right_motor->setSpeed(motor_speed + correction);
=======
  right_motor->setSpeed(motor_speed);
>>>>>>> 3002af08986dbafcff2bd57e40514a4a8963f0e1
  left_motor->run(FORWARD);
  right_motor->run(BACKWARD);
}

void MotorController::stop(){
  left_motor->run(RELEASE);
  right_motor->run(RELEASE);  
}
