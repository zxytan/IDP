#include "Robot.h"

void Robot::yellow_in_red() {
	motor_control.forward(SPEED);
	for (int i = 0; i <= 15; ++i) {
		get_light_reading();
		for (int n = 0; n <= 6; ++n) {
			if (light[n] >= YELLOW_MIN && light[n] <= YELLOW_MAX) {
				yellow_response();
				motor_control.forward(SPEED);
				delay(10000);
				motor_control.stop();
				i += 10;
				close_gates();
			}
		}
		delay(1000);
	}
	motor_control.stop();
}

void Robot::go_to_wall() {
	motor_control.forward(SPEED);
	get_prox_reading(BACK_PROX);
	while (back_prox < length_of_arena) { //numerical number for dist from back of robot to edge
		get_prox_reading(BACK_PROX);
		delay(500);
	}
	motor_control.stop();

}

void Robot::turn(float target, float initial) {
	if (target > initial) {
		motor_control.rotate_right(50);
		while ((target - bearing)>2) {
			get_compass_reading(bearing);
			delay(200);
		}
		motor_control.stop();
	}
	else if (target < initial) {
		motor_control.rotate_left(50);
		while ((bearing - target) > 2) {
			get_compass_reading(bearing);
			delay(200);
		}
	}
}

void Robot::print_coords() {

	// sensor_number =  ; //which sensor picked up the mine? --- 0 at left edge
	sensor_dist = 0.1; //if in metres??? // dist between sensors * sensor number ---- distance from ultrasound sensor
	int y_coord;
	int x_coord;
	float c_reading;
	get_compass_reading();
	get_prox_reading(BACK_PROX);
	get_prox_reading(LEFT_PROX);
	if (bearing == x_0_wall)
	{
		x_coord = length_of_arena - back_prox - robot_length;
		y_coord = left_prox + sensor_dist;
	}
	else{
		x_coord = back_prox + robot_length;
		y_coord = length_of_arena - left_prox + robot_length - sensor_dist;
	}

	Serial.println("Dangerous Mine: ( " + x_coord + ", " + y_coord + " )" );
}

void 