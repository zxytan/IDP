#include "Robot.h"

Serial.begin(9600);

void Robot::leave_box() {
	int dist = 5; //check distance to get out of box
	forward(dist, 1);
}

//set up LEDs

pinMode(YELLOW_LED, OUTPUT);
pinMode(RED_LED, OUTPUT);
