#include "robot.h"
#include "motor_control.h"

Robot::Robot():motor_control(2, 1) {
  
  loop_count = 0;
  
  servo_right.attach(9);
  servo_left.attach(10);
  
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);

  motor_control.init();
  Compass compass;
  compass.init();
  ColourDetector colour_detector;
};

void Robot::leave_box() {
  close_gates();
  float c_bearing = compass.get_heading();
  turn(y_max_wall, c_bearing);
	motor_control.forward(SPEED);
	delay(1000);
	motor_control.stop();
  c_bearing = compass.get_heading();
  turn(x_max_wall, c_bearing);
  motor_control.forward(SPEED);
  delay(3000);
  motor_control.stop();
}
