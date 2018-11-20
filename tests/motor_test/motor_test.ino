
#include "motor_control.h"

MotorController motor_controller(1,2);

void setup(){
  motor_controller.init();
  motor_controller.forward(250);
}

void loop(){
  delay(2500);
<<<<<<< HEAD
  motor_controller.rotate_right(250);
  delay(300);
  motor_controller.stop();
  delay(300);
  motor_controller.rotate_right(250);
  delay(400);
  motor_controller.stop();
  delay(300);
  motor_controller.rotate_right(250);
  delay(500);
  motor_controller.stop();
  delay(300);
  //motor_controller.forward(250);
=======
  //motor_controller.rotate_right(250);
  //delay(1100);
  motor_controller.forward(250);
>>>>>>> 3002af08986dbafcff2bd57e40514a4a8963f0e1
}

/*
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *left_motor = AFMS.getMotor(1);
Adafruit_DCMotor *right_motor = AFMS.getMotor(2);

void setup(){
  AFMS.begin();

  left_motor->setSpeed(150);
  right_motor->setSpeed(150);
  left_motor->run(RELEASE);
  right_motor->run(RELEASE);
  
}

void loop(){
  
}
*/
