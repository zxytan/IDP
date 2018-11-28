#include "robot.h"

void Robot::go_home(void) {
	float c_reading = compass.get_heading();
	float back_prox = get_prox_reading(BACK_PROX);
	if (abs(c_reading - x_0_wall) < 80)
	{
    if(back_prox<length_of_arena-5){
      go_to_wall();
    }
    turn(y_0_wall, LEFT);
    if(back_prox<length_of_arena-5){
      go_to_wall();
    }
	}
	else 
	{ 
		if(back_prox<length_of_arena-5){
      go_to_wall();
    }
   turn(y_0_wall,RIGHT);
    if(back_prox<length_of_arena-5){
      go_to_wall();
    }
    turn(x_0_wall, RIGHT);
    if(back_prox<length_of_arena-5){
      go_to_wall();
    }
	}
 
}
