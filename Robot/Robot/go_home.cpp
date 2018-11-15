#include "Robot.h"

void Robot::go_home() {
	get_compass_reading(reading);
	if reading == x_max_wall()
		turn(y_0_wall, reading);
		forward()

}