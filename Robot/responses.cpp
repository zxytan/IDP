#include "Robot.h"


void Robot::yellow_response() {
	delay(3000); //stationary wait for 3 seconds

	//flash yellow LED for 2 seconds 
	for (int i=0; i<= 4; ++i) {
		digitalWrite(YELLOW_LED, HIGH);
		delay(250);
		digitalWrite(YELLOW_LED, LOW);
		delay(250);
	}

	open_gates();
	
}

void Robot::wall_response() {
  if (loop_count % 2 == 0) {turn(RIGHT);}
  else {turn(LEFT);}
	open_gates();
	motor_control.reverse(SPEED);
	delay(1000);
	close_gates();
	motor_control.forward(SPEED);
	delay(1000);
	if (loop_count % 2 == 0) {turn(RIGHT);}
  else {turn(LEFT);}
  loop_count += 1;
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
	get_compass_reading(bearing);
	turn(y_0_wall, bearing);
	yellow_in_red();
	turn(bearing, y_0_wall);
	yellow_in_red();
	turn(y_max_wall, bearing);
	yellow_in_red();
	turn(bearing, y_max_wall);
}
