
int colour_reading;
int COLOUR_LDR_PIN = 9; //Analog

void setup() {
  Serial.begin(9600);
}

void loop() {
  colour_reading = analogRead(COLOUR_LDR_PIN);
  Serial.println(colour_reading);
}
