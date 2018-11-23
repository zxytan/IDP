#include "robot.h"

void Robot::go_home(void) {
	float c_reading = compass.get_heading();
	if (c_reading == x_max_wall)
	{
		turn(y_0_wall,c_reading);
		go_to_wall();
	}
	else 
	{
		if (loop_count < 8 )
		{ 
			turn(y_max_wall, c_reading);
			go_to_wall();
      c_reading = compass.get_heading();
			turn(x_0_wall, c_reading);
		}
		go_to_wall();
    c_reading = compass.get_heading();
		turn(y_0_wall, c_reading);
		go_to_wall();
	}
}
