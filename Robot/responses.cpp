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
  motor_control.forward(SPEED);
  delay(1000);
	
}

void Robot::wall_response(void) {

  open_gates();
  delay(100);
  motor_control.reverse(SPEED);
  delay(1500);
  close_gates();
  delay(100);
  motor_control.forward(SPEED);
  delay(1000);

  if (loop_count % 2 == 0) { turn(y_max_wall, LEFT); }
  else {turn(y_max_wall, RIGHT); }
  delay(100);
  motor_control.forward(SPEED);
  delay(1500);
  motor_control.stop();
  
  if (loop_count % 2 == 0) {
    turn(x_0_wall, LEFT);
    delay(100);
    motor_control.stop();
  }
  else {
    turn(x_max_wall, RIGHT);
    delay(100);
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
	if (loop_count == 0) {turn(y_max_wall, LEFT);}
	  else if (loop_count % 2 == 0) {turn(y_0_wall, RIGHT);}
  	else {turn(y_0_wall, LEFT);}
	yellow_in_red(700);
	if (loop_count == 0) {turn(x_max_wall, RIGHT);}
    else if (loop_count % 2 == 0) {turn(x_max_wall, LEFT);}
    else {turn(x_0_wall, RIGHT);}
	yellow_in_red(1000);
	if (loop_count == 0) {turn(y_0_wall, RIGHT);}
    else if (loop_count % 2 == 0) {turn(y_max_wall, LEFT);}
  	else {turn(y_max_wall,RIGHT);}
	yellow_in_red(700);
	  if (loop_count == 0) {turn(x_max_wall, LEFT);}
    else if (loop_count % 2 == 0) {turn(x_max_wall, RIGHT);}
  	else {turn(x_0_wall, LEFT);}
}
