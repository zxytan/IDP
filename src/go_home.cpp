#include "Robot.h"

void Robot::go_home() {
	float c_reading;
	get_compass_reading(c_reading);
	if (c_reading == x_max_wall)
	{
		turn(y_0_wall, c_reading);
		go_to_wall();
	}
	else 
	{
		if (loop_count < 8 )
		{ 
			turn(y_max_wall, c_reading);
			go_to_wall();
			get_compass_reading(c_reading);
			turn(x_0_wall, c_reading);
		}
		go_to_wall();
		get_compass_reading(c_reading);
		turn(y_0_wall, c_reading);
		go_to_wall();
	}
}