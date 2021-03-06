
#include "colour_detector.h"

//Defines

#define ESTIMATE_BLACK 0
#define ESTIMATE_WHITE 1
#define ESTIMATE_RED 2
#define ESTIMATE_YELLOW 3

float sensor_change_time = 0.1;
/*
int colour_readings[NUM_SENSORS][4] = {{620,1000,458,238},
                                      {683,1000,523,277},
                                      {722,1000,576,328},
                                      {703,1000,526,301},
                                      {721,1000,538,278},
                                      {647,1000,473,248},
                                      {582,1000,460,260}};
*/
/*
int colour_readings[NUM_SENSORS][4] = {{707,1000,525,280},
                                      {765,1000,582,310},
                                      {742,1000,564,323},
                                      {737,1000,534,283},
                                      {707,1000,520,240}};
*/
int colour_readings[NUM_SENSORS][4] = {{694,1000,534,286},
                                      {761,1000,594,326},
                                      {756,1000,542,309},
                                      {766,1000,562,302},
                                      {703,1000,479,245}};

float colour_weights[4] = {1.0,1.0,1.0,1.0};

//SingleSensor class methods

SingleSensor::SingleSensor():timer(0),change_time(sensor_change_time),
	current_estimate(ESTIMATE_BLACK),verified_estimate(ESTIMATE_BLACK){}

void SingleSensor::update_estimate(float dt){
	uint8_t new_estimate = get_closest_reading(analogRead(pin));
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

uint8_t SingleSensor::get_closest_reading(int reading){
	int min_dif = 1100;
	int dif = 0;
	int min_dif_index = 0;
	for(int i=0;i<4;i++){
		dif = abs(colour_readings[pin-START_PIN][i] - reading) * colour_weights[i];
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
