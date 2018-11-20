#include "Robot.h"

void Robot::go_home() {
	float c_reading = compass.get_heading();
	if (c_reading == x_max_wall)
	{
		turn(RIGHT);
		go_to_wall();
	}
	else 
	{
		if (loop_count < 8 )
		{ 
			turn(RIGHT);
			go_to_wall();
			turn(LEFT);
		}
		go_to_wall();
		turn(LEFT);
		go_to_wall();
	}
}
