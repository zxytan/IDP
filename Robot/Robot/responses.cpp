#include "Robot.h"

void Robot::wall_response() {
	loop_count += 1;
	float reading;
	get_compass_reading(reading);
	turn(y_0_wall, reading);


}