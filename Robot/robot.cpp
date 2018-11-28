#include "robot.h"

bool Robot::hello(void) {
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

  colour_detector.update_status();
  uint8_t colour_status = colour_detector.get_status();

  if(back_prox>length_of_arena-50 || side_prox<36 || side_prox>length_of_arena-30){
    if((loop_count%2==0 && side_prox<36) || (loop_count%2==1 && side_prox>length_of_arena-30)){
      return true;  
    }else{
      return false;  
    }
  }

  if(colour_status != STATUS_BLACK){
    motor_control.stop();
    delay(500);
    colour_detector.update_status();
    colour_status = colour_detector.get_status();
  }

  switch(colour_status){
    case STATUS_RED:
      motor_control.stop();
      delay(1000);
  
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
      delay(1000);
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

void Robot::emergency() {
  close_gates();
  motor_control.forward(SPEED);
  delay(6000);
  motor_control.stop();
  turn(x_0_wall, LEFT);
  delay(100);
  motor_control.forward(SPEED);
  delay(6000);
  motor_control.stop();
}

void Robot::test() {
  go_home();
}
