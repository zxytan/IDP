#include "Robot.h"

void Robot::main(void) {
  get_prox_reading(BACK_PROX);
  if (back_prox >= (length_of_arena - 5)) {
    motor_control.stop();
    wall_response();
  }
  motor_control.forward(SPEED);
  delay(100);
}
