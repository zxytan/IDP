#include "robot.h"


void Robot::yellow_response(void) {
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

void Robot::wall_response(void) {
  float c_bearing = compass.get_heading();
  if (loop_count % 2 == 0) {
    turn(y_0_wall, c_bearing);
    motor_control.stop();
  }
  else {
    turn(y_max_wall, c_bearing);
    motor_control.stop();
   }
  open_gates();
  motor_control.reverse(SPEED);
  delay(1500);
  close_gates();
  motor_control.forward(SPEED);
  delay(500);
  c_bearing = compass.get_heading();
  if (loop_count % 2 == 0) {
    turn(x_0_wall, c_bearing);
    motor_control.stop();
  }
  else {
    turn(x_max_wall, c_bearing);
    motor_control.stop();
  }
  loop_count += 1;
  motor_control.stop();
}

void Robot::red_response(void) {
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
  float c_bearing = compass.get_heading();
	if (loop_count % 2 == 0) {turn(y_0_wall, c_bearing);}
  	else {turn(y_0_wall, c_bearing);}
	yellow_in_red();
  c_bearing = compass.get_heading();
	if (loop_count % 2 == 0) {turn(x_max_wall, c_bearing);}
  	else {turn(x_0_wall,c_bearing);}
	yellow_in_red();
  c_bearing = compass.get_heading();
	if (loop_count % 2 == 0) {turn(y_max_wall, c_bearing);}
  	else {turn(y_max_wall,c_bearing);}
	yellow_in_red();
  c_bearing = compass.get_heading();
	if (loop_count % 2 == 0) {turn(x_max_wall, c_bearing);}
  	else {turn(x_0_wall, c_bearing);}
}
