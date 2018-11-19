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
#define SPEED 5 //cm/s (check)


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
	void start_motor(bool direction);
	void stop_motor();
	void turn(float target, float initial);
	void leave_box();
	void init();
	void get_light_reading(float& reading);
	void get_prox_reading(float& reading);
	void get_compass_reading(float& reading);
private:
	int loop_count;
	float y_max_wall = 65;
	float y_0_wall = 245;
	float x_max_wall = 155;
	float x_0_wall = 335;
	float bearing;
	float back_prox;
	float right_prox;
	float light;
	void open_gates(); //check servo positions in these functions
	void close_gates();
	void forward(float dist, bool direction); //includes use of PID library to stay on course
	void go_to_wall();
};

#endif