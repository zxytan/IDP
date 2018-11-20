
#include "colour_detector.h"

ColourDetector colour_detector;

void setup() {
  Serial.begin(9600);
}

void loop() {
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
      Serial.println("Red at index "+String(colour_detector.get_red_index()));
      break;
    case STATUS_YELLOW:
      Serial.println("Yellow");
      break;
  }
}
