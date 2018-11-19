#include "Robot.h"

void Robot::forward(float dist, bool direction) {
	start_motor(1);
	delay(dist / SPEED);
	stop_motor();
}

void Robot::go_to_wall() {
	start_motor(1);
	get_prox_reading(BACK_PROX, back_prox);
	while (back_prox < length_of_arena) { //numerical number for dist from back of robot to edge
		get_prox_reading(BACK_PROX, back_prox);
		delay(500);
	}
	stop_motor();

}
