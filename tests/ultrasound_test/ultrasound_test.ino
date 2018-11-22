#define TRIG_PIN 2
#define ECHO_PIN 3
#define TRIG_PIN_2 4
#define ECHO_PIN_2 5

void setup() {
  Serial.begin (9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);
}

void loop() {
  long duration, distance, duration2, distance2;
  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2) / 29.1;

  if (distance >= 400 || distance <= 0){
    Serial.println("Back: Out of range");
    Serial.println(distance);
  }else {
    Serial.print("Back: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  
  digitalWrite(TRIG_PIN_2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_2, LOW);
  
  duration2 = pulseIn(ECHO_PIN_2, HIGH);
  distance2 = (duration2/2) / 29.1;

  if (distance2 >= 400 || distance2 <= 0){
    Serial.println("Side: Out of range");
  }else {
    Serial.print("Side :");
    Serial.print(distance2);
    Serial.println(" cm");
  }
  
  delay(500);
}
