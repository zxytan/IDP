#include "Robot.h"

void Robot::leave_box() {
	int dist = 5; //check distance to get out of box
	forward(dist, 1);
}