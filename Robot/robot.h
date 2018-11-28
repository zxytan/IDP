
#ifndef ROBOT_H
#define ROBOT_H

#include "motor_control.h"
#include "compass.h"
#include "colour_detector.h"
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_APDS9960.h>
#include <Arduino.h>

#define YELLOW_LED 7
#define RED_LED 6
#define TRIG_PIN 2
#define ECHO_PIN 3
#define TRIG_PIN_2 4
#define ECHO_PIN_2 5
#define	YELLOW_MIN 500
#define YELLOW_MAX 600
#define RED_MIN 700
#define RED_MAX 800
#define SPEED 220
#define BACK_PROX false
#define LEFT_PROX true
#define LEFT true
#define RIGHT false



class Robot {
  public:
  	Robot();
    void leave_box();
    bool hello();
  	void go_home();
  	void emergency();
    void test();
    
  	int loop_count;
  	
  private:
  	float y_max_wall = 263;
  	float y_0_wall = 83;
  	float x_max_wall = 350;
  	float x_0_wall = 173;
  	float length_of_arena = 200;
  	float robot_length = 28;
    float robot_width = 20;
  	void open_gates();
  	void close_gates();
    void turn(float target, bool robot_direction);
  	void go_to_wall();
  	void yellow_in_red(int delay_time);
    void print_coords();
    void red_response();
    void yellow_response();
    void wall_response();
    float get_prox_reading(bool robot_direction); //updates back_prox or left_prox

  
  	MotorController motor_control;
    Compass compass;
    ColourDetector colour_detector;
    Servo servo_right;
    Servo servo_left;
};

#endif
