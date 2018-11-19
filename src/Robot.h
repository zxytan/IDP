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

#define YELLOW_LED 7
#define RED_LED 6
#define	YELLOW_MIN 500
#define YELLOW_MAX 600
#define RED_MIN 700
#define RED_MAX 800
#define SPEED 100 //(check)
#define BACK_PROX 0
#define LEFT_PROX 1


class Robot {
public:
	Robot() {
		loop_count = 0;
		MotorController motor_control(1,2);
	};
	void print_coords();
	void red_response();
	void yellow_response();
	void wall_response();
	void go_home();
	void turn(float target, float initial);
	void leave_box();
	void init();
	void get_light_reading(float& reading);
	void get_prox_reading(bool direction, float& reading);
	void get_compass_reading(float& reading);
private:
	int loop_count;
	float y_max_wall = 65;
	float y_0_wall = 14;
	float x_max_wall = 325;
	float x_0_wall = 335;
	float bearing;
	float back_prox;
	float left_prox;
	float light;
	float length_of_arena = 1;
	void open_gates(); //check servo positions in these functions
	void close_gates();
	void go_to_wall();
	void yellow_in_red();
	MotorController motor_control;
};

#endif