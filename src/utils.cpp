#include "Robot.h"

void Robot::yellow_in_red() {
	motor_control.forward(SPEED);
	for (int i = 0; i <= 15; ++i) {
		get_light_reading(light);
		if (light >= YELLOW_MIN && light <= YELLOW_MAX) {
			yellow_response();
			motor_control.forward(SPEED);
			delay(10000);
			motor_control.stop();
			i += 10;
			close_gates();
		}
		delay(1000);
	}
	motor_control.stop();
}

void Robot::go_to_wall() {
	motor_control.forward(SPEED);
	get_prox_reading(BACK_PROX, back_prox);
	while (back_prox < length_of_arena) { //numerical number for dist from back of robot to edge
		get_prox_reading(BACK_PROX, back_prox);
		delay(500);
	}
	motor_control.stop();

}



void Robot::print_coords() {

	// sensor_number =  //which sensor picked up the mine? --- 0 at left edge
	// sensor_dist = // dist between sensors * sensor number ---- distance from ultrasound sensor
	
	float c_reading;
	int y_coord;
	int x_coord;
	get_compass_reading(c_reading);
	if (c_reading == x_0_wall)
	{
		x_coord = length_of_arena - back_prox - robot_length;
		y_coord = left_prox + sensor_dist;
	}
	else
	{
		x_coord = back_prox + robot_length;
		y_coord = length_of_arena - left_prox + robot_length - sensor_dist;
	}

	Serial.println("Dangerous Mine: ( " + x_coord + ", " + y_coord + " )" );
}