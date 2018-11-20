#include "motor_control.h"
#define SPEED 250 
#define BACK_PROX false
#define LEFT_PROX true
#define RIGHT false
#define LEFT true
#define length_of_arena 170
#define TRIG_PIN 3
#define ECHO_PIN 2
#define TRIG_PIN_2 4
#define ECHO_PIN_2 5

int loop_count;

MotorController motor_control(1,2);

float get_prox_reading(bool direction) {
  long duration;
  if (direction == BACK_PROX) {
    digitalWrite(TRIG_PIN_2, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_2, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_2, LOW);
  
    duration = pulseIn(ECHO_PIN_2, HIGH);
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
  get_prox_reading(direction);
  return;
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  return(distance);
}



void holla(void) {
  float back_prox = get_prox_reading(BACK_PROX);
  if (back_prox >= (length_of_arena - 5)) {
    motor_control.stop();
    wall_response();
  }
  motor_control.forward(SPEED);
  delay(100);
}

void wall_response(void) {
  if (loop_count % 2 == 0) {turn(RIGHT);}
  else {turn(LEFT);}
  //open_gates();
  motor_control.reverse(SPEED);
  delay(1000);
  //close_gates();
  motor_control.forward(SPEED);
  delay(1000);
  if (loop_count % 2 == 0) {turn(RIGHT);}
  else {turn(LEFT);}
  loop_count += 1;
  motor_control.stop();
}

void turn(bool direction) {
  if (direction == RIGHT) {
    //check variables!!!
    motor_control.rotate_right(SPEED);
    delay(1000);
    
  }
  else {
    motor_control.rotate_left(SPEED);
    delay(1100);
  }
  motor_control.stop();
}

void setup() {
  // put your setup code here, to run once:
  loop_count = 0;
  Serial.begin (9600);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);

  motor_control.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  turn(RIGHT);
  motor_control.forward(SPEED);
  delay(1000);
  motor_control.stop();
  turn(LEFT);
  motor_control.forward(SPEED);
  delay(1000);
  motor_control.stop();
  

}
