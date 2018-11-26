//#include <PID_v1.h>
#include "motor_control.h"
#include "compass.h"
#define SPEED 250 
#define BACK_PROX false
#define LEFT_PROX true
#define RIGHT false
#define LEFT true
#define length_of_arena 190
#define TRIG_PIN 2
#define ECHO_PIN 3
#define TRIG_PIN_2 4
#define ECHO_PIN_2 5

int loop_count;
float y_max_wall = 260;
float y_0_wall = 80;
float x_max_wall = 350;
float x_0_wall = 170;

long initial;

MotorController motor_control(2,1);
Compass compass;
//double bearing = compass.get_heading();
//double Setpoint;
//PID motor_PID(&bearing, &motor_control.correction, &Setpoint, 2, 5, 1, DIRECT);
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
  return(distance);
}



void holla(void) {
  long back_prox = get_prox_reading(BACK_PROX);
  if (back_prox >= (length_of_arena - 10 )) {
    wall_response();
  }
  motor_control.forward(SPEED);
  delay(500);
}

void turn(float target, float initial) {
  float bearing = initial;
  if (target > initial) {
    motor_control.rotate_right(250);
    
    while ((target - bearing) > 4) {
      bearing = compass.get_heading();
    }
    motor_control.stop();
  }
  else if (target < initial) {
    motor_control.rotate_left(250);
    while ((bearing - target) > 4) {
      bearing = compass.get_heading();
    }
  }
}


void wall_response(void) {
  if (loop_count % 2 == 0) {
    float c_bearing = compass.get_heading();
    turn(y_0_wall, c_bearing);
    motor_control.stop();
  }
  else {
    float c_bearing = compass.get_heading();
    turn(y_max_wall, c_bearing);
    motor_control.stop();
   }
  //open_gates();
  motor_control.reverse(SPEED);
  delay(1500);
  //close_gates();
  motor_control.forward(SPEED);
  delay(500);
  if (loop_count % 2 == 0) {
    float c_bearing = compass.get_heading();
    turn(x_0_wall, c_bearing);
    motor_control.stop();
  }
  else {
    float c_bearing = compass.get_heading();
    turn(x_max_wall, c_bearing);
    motor_control.stop();
  }
  loop_count += 1;
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
  initial = get_prox_reading(LEFT);
  
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  motor_control.forward(SPEED);
  //delay(3000);
  //motor_control.reverse(SPEED);
  delay(1000);
  motor_control.side_prox_error(initial);
}
