#include "Robot.h"

void Robot::leave_box() {
	motor_control.forward(SPEED);
	delay(5000); //check
	motor_control.stop();
}

//set up LEDs

pinMode(YELLOW_LED, OUTPUT);
pinMode(RED_LED, OUTPUT);
