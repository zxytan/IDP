#include "Robot.h"


void Robot::yellow_response() {
	delay(3000); //stationary wait for 3 seconds

	//flash yellow LED for 2 seconds 
	for (int i = 0; i <= 4; ++i) {
		digitalWrite(yellow_LED, HIGH);
		delay(250);
		digitalWrite(yellow_LED, LOW);
		delay(250);
	}

	open_gates();
	
}

void Robot::wall_response() {
	loop_count += 1;
	float reading;
	get_compass_reading(reading);
	turn(y_0_wall, reading);
	open_gates();
	forward(28, -1);
	close_gates();
	forward(8, 1);
	get_compass_reading(reading);
	turn(x_max_wall, reading);
}

