#include "motor_control.h"
#define SPEED 250 
#define BACK_PROX false
#define LEFT_PROX true
#define RIGHT false
#define LEFT true
#define length_of_arena 160
#define TRIG_PIN 3
#define ECHO_PIN 2
#define TRIG_PIN_2 4
#define ECHO_PIN_2 5

int loop_count;

MotorController motor_control(1,2);

float get_prox_reading(bool direction) {
  long duration;
  if (direction == BACK_PROX) {
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
  if (direction == BACK_PROX) {
    //back_prox = distance;
    return (distance);
  }
  else {
    //left_prox = distance;
    return(distance);
  }
}


void wall_response(void) {
  if (loop_count % 2 == 0) {
    turn(RIGHT);
    motor_control.stop();
  }
  else {
    turn(LEFT);
    motor_control.stop();
   }
  //open_gates();
  motor_control.reverse(SPEED);
  delay(1500);
  //close_gates();
  motor_control.forward(SPEED);
  delay(500);
  if (loop_count % 2 == 0) {
    turn(RIGHT);
    motor_control.stop();
  }
  else {
    turn(LEFT);
    motor_control.stop();
  }
  loop_count += 1;
  motor_control.stop();
}

void turn(bool direction) {
  if (direction == RIGHT) {
    //check variables!!!
    motor_control.rotate_right(SPEED);
    delay(1103);
    
  }
  else {
    motor_control.rotate_left(SPEED);
    delay(1213);
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
  motor_control.forward(SPEED);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  float back_prox = get_prox_reading(BACK_PROX);
  if (back_prox >= (length_of_arena - 10 )) {
    while (back_prox >= ( 10 )) {
    motor_control.reverse(SPEED);
    delay(500);
    float back_prox = get_prox_reading(BACK_PROX);
    }
  }
  motor_control.forward(SPEED);
  delay(500);
}
