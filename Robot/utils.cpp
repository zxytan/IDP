#include "Robot.h"

void Robot::yellow_in_red(void) {
	motor_control.forward(SPEED);
	for (int i = 0; i <= 15; ++i) {
		get_light_reading();
		for (int n = 0; n <= 6; ++n) {
			if (light[n] >= YELLOW_MIN && light[n] <= YELLOW_MAX) {
				yellow_response();
				motor_control.forward(SPEED);
				delay(10000);
				i += 10;
				close_gates();
				break;
			}
		}
		delay(1000);
	}
	motor_control.stop();
}

void Robot::go_to_wall(void) {
	motor_control.forward(SPEED);
	get_prox_reading(BACK_PROX);
	while (back_prox < length_of_arena) { //numerical number for dist from back of robot to edge
		get_prox_reading(BACK_PROX);
		delay(500);
	}
	motor_control.stop();

}

void Robot::turn(bool direction) {
	if (direction == RIGHT) {
    //check variables!!!
		motor_control.rotate_right(50);
	  delay(200);
		
	}
	else {
		motor_control.rotate_left(50);
    delay(200);
	}
	motor_control.stop();
}

void Robot::print_coords(void) {

	// sensor_number =  ; //which sensor picked up the mine? --- 0 at left edge
	sensor_dist = 10; //if in cm? dist between sensors * sensor number ---- distance from ultrasound sensor
	int y_coord;
	int x_coord;
	float bearing = compass.get_heading()
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

void Robot::get_prox_reading(bool direction) {
  long duration;
  if (direction == BACK) {
  	digitalWrite(TRIG_PIN, LOW);
  	delayMicroseconds(2);
  	digitalWrite(TRIG_PIN, HIGH);
  	delayMicroseconds(10);
  	digitalWrite(TRIG_PIN, LOW);
  
  	duration = pulseIn(ECHO_PIN, HIGH);
  }
  else {
	digitalWrite(TRIG_PIN_2, LOW);
  	delayMicroseconds(2);
  	digitalWrite(TRIG_PIN_2, HIGH);
  	delayMicroseconds(10);
  	digitalWrite(TRIG_PIN_2, LOW);
  
  	duration = pulseIn(ECHO_PIN_2, HIGH);
  }
  long distance = (duration/2) / 29.1;

  if (distance >= 400 || distance <= 0) {
    Serial.println("Out of range");
    Serial.println(distance);
	distance = get_prox_reading(direction);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  return (distance);
}
