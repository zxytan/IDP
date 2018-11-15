#include "Robot.h"

void Robot::leave_box() {
	int dist = 5; //check distance to get out of box
	forward(dist, 1);
}

//set up LEDs
//these functions are from arduino???

const int yellow_LED = 7;
const int red_LED = 6;

pinMode(yellow_LED, OUTPUT);
pinMode(red_LED, OUTPUT);
