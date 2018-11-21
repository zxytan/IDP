
#ifndef _Robot_h
#define _Robot_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include <WProgram.h>
#endif

#include "motor_control.h"
#include "compass.h"
#include <Servo.h>

#define YELLOW_LED 7
#define RED_LED 6
#define TRIG_PIN 3
#define ECHO_PIN 2
#define TRIG_PIN_2 4
#define ECHO_PIN_2 5
#define	YELLOW_MIN 500
#define YELLOW_MAX 600
#define RED_MIN 700
#define RED_MAX 800
#define SPEED 250 
#define BACK_PROX false
#define LEFT_PROX true
#define RIGHT false
#define LEFT true


class Robot {
  public:
  	Robot() {
  		loop_count = 0;
      MotorController motor_control(1,2);
  		Compass compass;
      servo_right.attach(9);
      servo_left.attach(10);
  	};
    
    void init();
    void leave_box();
    void main();
    
  	void print_coords();
  	void red_response();
  	void yellow_response();
  	void wall_response();
  	void go_home();
  	
    
  	void get_prox_reading(bool direction); //updates back_prox or left_prox
  	
  private:
  	int loop_count;
  	float y_max_wall = 65;
  	float y_0_wall = 14;
  	float x_max_wall = 325;
  	float x_0_wall = 335;
   
  	float back_prox;
  	float left_prox;
  	float light[7];
  	float length_of_arena = 230;
  	float robot_length = 28;
    float robot_width = 20;
  	void open_gates(); //check servo positions in these functions
  	void close_gates();
    void turn(bool direction);
  	void go_to_wall();
  	void yellow_in_red();
  
  	MotorController motor_control;
    Compass compass;
    Servo servo_right;
    Servo servo_left;
};

#endif
