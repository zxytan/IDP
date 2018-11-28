#include "robot.h"

void Robot::hello(void) {
  float back_prox = get_prox_reading(BACK_PROX);
  if (back_prox >= (length_of_arena)) {
    motor_control.stop();
    wall_response();
  }
  float side_prox = get_prox_reading(LEFT_PROX);
  //motor_control.side_prox_error(side_prox);
  float current_heading = compass.get_heading();
  motor_control.compass_error(loop_count,current_heading);
  motor_control.forward(SPEED);
  
  if(back_prox>length_of_arena-30 || side_prox<30 || side_prox>length_of_arena-30){
    return;
  }

  colour_detector.update_status();
  uint8_t colour_status = colour_detector.get_status();

  

  switch(colour_status){
    case STATUS_RED:
      motor_control.stop();
      delay(3000);
      Serial.println("Red at index "+String(colour_detector.get_red_index()));
      
      for (int i = 0; i <= 4; ++i) {
        digitalWrite(RED_LED, HIGH);
        delay(250);
        digitalWrite(RED_LED, LOW);
        delay(250);
      }
      red_response();

      break;
    case STATUS_YELLOW:
      motor_control.stop();
      delay(3000);
      Serial.println("Yellow");
      
      for (int i=0; i<= 4; ++i) {
        digitalWrite(YELLOW_LED, HIGH);
        delay(250);
        digitalWrite(YELLOW_LED, LOW);
        delay(250);
      }
      yellow_response();
    
      break;
  }

}

void Robot::test() {
  float c_bearing = compass.get_heading();
  turn(y_max_wall, c_bearing);
  delay(1000);
  c_bearing = compass.get_heading();
  turn(y_0_wall, c_bearing);
  delay(1000);
  c_bearing = compass.get_heading();
  turn(x_0_wall, c_bearing);
  delay(1000);
  c_bearing = compass.get_heading();
  turn(x_max_wall, c_bearing);
}
