#include "Robot.h"
/*	go_to_wall() code
start_motor();
get_prox_reading(p_reading);
for (p_reading < y_max_length) { //put in numerical value for y_max_length
	get_prox_reading(p_reading);
	delay(1000);
}
stop_motor();

*/

void Robot::go_home() {
	float c_reading;
	float p_reading;
	get_compass_reading(c_reading);
	if c_reading == x_max_wall() {
		turn(y_0_wall, c_reading);
		go_to_wall()
	}
	else {
		if loop_count == 8 {
			turn(y_max_wall, c_reading);
			go_to_wall();
			get_compass_reading(c_reading);
			turn(x_0_wall, c_reading);
		}
	}
}