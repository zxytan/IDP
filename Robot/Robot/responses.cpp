#include "Robot.h"

void Robot::wall_response() {
	loop_count += 1;
	float reading;
	get_compass_reading(reading);
	turn(y_0_wall, reading);
	open_gates();
	forward(28, -1);
	close_gates();
	forward(8, 1);
	get_compass_reading(reading);
	turn(x_max_wall, reading);
}