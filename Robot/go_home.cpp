#include "robot.h"

void Robot::go_home(void) {
	float c_reading = compass.get_heading();
	if (abs(c_reading - x_max_wall) < 5)
	{
		turn(y_0_wall,RIGHT);
		go_to_wall();
	}
	else 
	{
		if (loop_count < 6 )
		{ 
			turn(y_max_wall, RIGHT);
			go_to_wall();
			turn(x_0_wall, LEFT);
		}
		go_to_wall();
		turn(y_0_wall, LEFT);
		go_to_wall();
	}
}
