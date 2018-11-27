
#include "colour_detector.h"

//Defines

#define ESTIMATE_BLACK 0
#define ESTIMATE_WHITE 1
#define ESTIMATE_RED 2
#define ESTIMATE_YELLOW 3

#define BLACK_CHANGE_RATE_THRESHOLD 400

float sensor_change_time = 0.3;

int colour_readings[NUM_SENSORS][4] = {{0,1000,546-390,546-216},
                                      {0,1000,575-459,575-273},
                                      {0,1000,611-480,611-288},
                                      {0,1000,625-495,625-310},
                                      {0,1000,614-471,614-282},
                                      {0,1000,546-378,546-203},
                                      {0,1000,112,227}};

//int colour_readings[NUM_SENSORS][4] = {{0,1000,112,227}};

//SingleSensor class methods

SingleSensor::SingleSensor():timer(0),change_time(sensor_change_time),black_reading(0),
	current_estimate(ESTIMATE_BLACK),verified_estimate(ESTIMATE_BLACK){
  black_reading = analogRead(pin);
}

void SingleSensor::update_estimate(float dt){
  int reading = analogRead(pin);
  uint8_t new_estimate = get_closest_reading(abs(reading-black_reading));
  if(new_estimate != current_estimate){
    current_estimate = new_estimate;
    if(current_estimate != verified_estimate){
      timer = 0;
    }else{
      timer = change_time;
    }
  }else if(current_estimate != verified_estimate){
    timer += dt;
    if(timer > change_time){
      verified_estimate = current_estimate;
    }
  }
}

void SingleSensor::move_towards_black_reading(float dt){
  int reading = analogRead(pin);
  //Update the black_reading, if change rate is less than a certain threshold
  float change_rate = abs(reading-black_reading)/dt;
  if(change_rate<BLACK_CHANGE_RATE_THRESHOLD){
    black_reading = reading;
    //Serial.println(black_reading);
  }
}

uint8_t SingleSensor::get_closest_reading(int reading){
	int min_dif = 1100;
	int dif = 0;
	int min_dif_index = 0;
	for(int i=0;i<4;i++){
		dif = abs(colour_readings[pin-START_PIN][i] - reading);
    if(i==0){
      dif *= 1;
    }
		if(dif<min_dif){
			min_dif = dif;
			min_dif_index = i;
		}
	}
	return min_dif_index; //Corresponds to ESTIMATE_BLACK, ESTIMATE_WHITE, etc.
}

//ColourDetector class methods

ColourDetector::ColourDetector():status(STATUS_BLACK),red_index(0),prev_millis(0){
	for(int i=0;i<NUM_SENSORS;i++){
		sensors[i].set_pin(START_PIN + i);
	}
}

void ColourDetector::update_status(){
	//Measure time elapsed since last update
	
	unsigned long current_millis = millis();
	float dt = (current_millis-prev_millis)/1000.0;
	prev_millis = current_millis;
	
	//Update the sensors
	
	for(int i=0;i<NUM_SENSORS;i++){
		sensors[i].update_estimate(dt);
	}

	//Update status
	
	uint8_t highest_estimate = 0;
	
	for(int i=0;i<NUM_SENSORS;i++){
		highest_estimate = max(highest_estimate,sensors[i].get_estimate());
		if(sensors[i].get_estimate()==ESTIMATE_RED){
			red_index = i;
		}
	}
	
	//If the highest estimate is red, then status is red, etc
	//Therefore, status = highest estimate
	status = highest_estimate;
}
