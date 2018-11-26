
/*  Motor Control library, for controlling the drive motors
 *  Initialise a MotorController object with the ports of the left and right motors 
 *  Call the forward, reverse, rotate_right, rotate_left functions to start movement
 *  Call the stop function to stop movement
 *  For movement functions, supply a motor speed from 0 -> 255
 */
 
#ifndef MOTOR_CONTROL_H_GUARD
#define MOTOR_CONTROL_H_GUARD

#define TRIG_PIN_2 4
#define ECHO_PIN_2 5

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

class MotorController{

public:

  MotorController(uint8_t left_motor_port,uint8_t right_motor_port);
  void init();
  void forward(uint8_t motor_speed);
  void reverse(uint8_t motor_speed);
  void rotate_right(uint8_t motor_speed);
  void rotate_left(uint8_t motor_speed);
  void stop();
  void side_prox_error(long target);
  

private:

  Adafruit_MotorShield AFMS;
  Adafruit_DCMotor *left_motor;
  Adafruit_DCMotor *right_motor;
  double correction = 0;
  
};

#endif
