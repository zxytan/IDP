
#ifndef COMPASS_H
#define COMPASS_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

class Compass{

public:

  Compass() {Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);};
  void init();
  float get_heading();

private:
  void displaySensorDetails();
};

#endif
