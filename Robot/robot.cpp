#include "robot.h"

void Robot::hello(void) {
  float back_prox = get_prox_reading(BACK_PROX);
  if (back_prox >= (length_of_arena - 10)) {
    motor_control.stop();
    wall_response();
  }
  float side_prox = get_prox_reading(LEFT_PROX);
  motor_control.side_prox_error(side_prox);
  motor_control.forward(SPEED);
  delay(100);
}
