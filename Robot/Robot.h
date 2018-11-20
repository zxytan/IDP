/*
 Name:		Robot.h
 Created:	11/13/2018 7:49:16 PM
 Author:	zxyt2, phmn3
 Editor:	http://www.visualmicro.com
*/

#ifndef _Robot_h
#define _Robot_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include <WProgram.h>
#endif

#include "motor_control.h"
#include "compass.h"

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
#define SPEED 100 //(check)
#define BACK_PROX 0
#define LEFT_PROX 1
#define RIGHT 0
#define LEFT 1


class Robot {
public:
	Robot() {
		loop_count = 0;
	};
  
  void init(void);
	void print_coords(void);
	void red_response(void);
	void yellow_response(void);
	void wall_response(void);
	void go_home(void);
	void leave_box(void);
	
  
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
	float length_of_arena = 1; //measure this value
	float robot_length = 1; //measure this value
  void get_compass_reading(void); //use to get approx bearing?
	void open_gates(void); //check servo positions in these functions
	void close_gates(void);
  void turn(bool direction);
	void go_to_wall(void);
	void yellow_in_red(void);
	MotorController motor_control(1,2);
  Compass compass;
};

#endif
