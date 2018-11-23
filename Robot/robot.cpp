#include "robot.h"

void Robot::main_loop(void) {
  float back_prox = get_prox_reading(BACK_PROX);
  if (back_prox >= (length_of_arena - 10)) {
    motor_control.stop();
    wall_response();
  }
  motor_control.forward(SPEED);
  delay(100);
}
