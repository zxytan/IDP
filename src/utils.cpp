#include "Robot.h"

void Robot::forward(float dist, bool direction) {
	start_motor(1);
	delay(dist / SPEED);
	stop_motor();
}


