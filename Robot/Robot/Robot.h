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
	#include "WProgram.h"
#endif

class Robot {
public:
	void print_coords();
	void red_response();
	void yellow_response();
	void wall_response();
	void go_home();
	void forward(); //includes use of PID library to stay on course
	void turn(float target, float initial);
	void leave_box();
	void init();
private:

};

#endif

