
#include "colour_detector.h"
#include "motor_control.h"
#define YELLOW_LED 7
#define RED_LED 6

ColourDetector colour_detector;
MotorController motor_control(1,2);

void setup() {
  Serial.begin(9600);
  motor_control.init();
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  motor_control.forward(100);
  colour_detector.update_status();
  uint8_t colour_status = colour_detector.get_status();
  switch(colour_status){
    case STATUS_BLACK:
      Serial.println("Black");
      break;
    case STATUS_WHITE:
      Serial.println("White");
      break;
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
    
      break;
  }
}
