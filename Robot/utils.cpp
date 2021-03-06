
#include "robot.h"

void Robot::yellow_in_red(int delay_time) {
  delay(500);
	motor_control.forward(SPEED);
  long start_time = millis();
  while(millis()-start_time<delay_time){
    float current_heading = compass.get_heading();
    motor_control.compass_error(loop_count,current_heading);
    delay(100);
  }
	motor_control.stop();
}

void Robot::go_to_wall(void) {
	
	float back_prox = get_prox_reading(BACK_PROX);
  float current_heading = compass.get_heading();
  motor_control.compass_error(loop_count,current_heading);
  motor_control.forward(SPEED);
	while (back_prox < (length_of_arena-5)) { //numerical number for dist from back of robot to edge
		back_prox = get_prox_reading(BACK_PROX);
		delay(100);
	}
	motor_control.stop();

}

void Robot::turn(float target, bool robot_direction) {
  float bearing = compass.get_heading();
  if (robot_direction == RIGHT) {
    motor_control.rotate_left(SPEED); 
    while (abs(bearing - target) > 4) {
      bearing = compass.get_heading();
    }
    motor_control.stop();
  }
  else if (robot_direction == LEFT) {
    motor_control.rotate_right(SPEED);
    while (abs(bearing - target) > 4) {
      bearing = compass.get_heading();
    }
  }
}

void Robot::print_coords(void) {

  uint8_t sensor_number = colour_detector.get_red_index() + 1 ;  // assuming 0 at left edge
	float sensor_dist = 3.5 * sensor_number; //dist between sensors * sensor number ---- distance from ultrasound sensor
	int y_coord;
	int x_coord;
	float bearing = compass.get_heading();
	float back_prox = get_prox_reading(BACK_PROX);
	float left_prox = get_prox_reading(LEFT_PROX);
	if (bearing == x_0_wall)
	{
		x_coord = length_of_arena - back_prox;  //length_of_arena already accounts for robot length
		y_coord = left_prox - 1.0 + sensor_dist;
	}
	else{
		x_coord = back_prox + robot_length;
		y_coord = length_of_arena + robot_length - left_prox + 1.0 - sensor_dist;
	}

	Serial.println("Dangerous Mine: ( " + String(x_coord) + ", " + String(y_coord) + " )" );
}

float Robot::get_prox_reading(bool robot_direction) {
  float duration;
  if (robot_direction == BACK_PROX) {
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
  float distance = (duration/2) / 29.1;

  if (distance >= 400 || distance <= 0) {
   // Serial.println("Out of range");
    //Serial.println(distance);
	  distance = get_prox_reading(robot_direction);
  }
  else {
   // Serial.print(distance);
   // Serial.println(" cm");
  }
  return(distance);
}

void Robot::open_gates() {  //gates open at the same time

  servo_right.write(150);
  servo_left.write(-30);
  delay(500);
}

void Robot::close_gates() { //one gate open before the other to stop mines jamming the servos

  servo_right.write(40);
  delay(200);
  servo_left.write(115);
  delay(500);
}
