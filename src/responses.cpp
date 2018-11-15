#include "Robot.h"


void Robot::yellow_response() {
	delay(3000); //stationary wait for 3 seconds

	//flash yellow LED for 2 seconds 
	for (int i=0; i<= 4; ++i)
		digitalWrite(YELLOW_LED, HIGH);
		delay(250);
		digitalWrite(YELLOW_LED, LOW);
		delay(250);

	open_gates();
	
}

void Robot::wall_response() {
	loop_count += 1;
	float reading;
	get_compass_reading(reading);
	turn(y_0_wall, reading);
	open_gates();
	forward(28, 0);
	close_gates();
	forward(8, 1);
	get_compass_reading(reading);
	turn(x_max_wall, reading);
}

void Robot::red_response() {
	delay(3000); //stationary wait for 3 seconds

	//flash red LED for 2 seconds 
	for (int i = 0; i <= 4; ++i) {
		digitalWrite(RED_LED, HIGH);
		delay(250);
		digitalWrite(RED_LED, LOW);
		delay(250);
	}

	print_coords();
	close_gates();
	float bearing;
	get_compass_reading(bearing);
	turn(y_0_wall, bearing);
	start_motor(1);
	for (int i = 0; i <= 15; ++i) {
		float light;
		get_light_reading(light);
		if (light >= YELLOW_MIN && light <= YELLOW_MAX) {
			yellow_response();
			forward(10, 1);
		}
		delay(1000);

	}
}
