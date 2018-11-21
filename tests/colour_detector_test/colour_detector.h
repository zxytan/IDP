

/* Colour detector library.
 *  
 * Inputting data
 * - Define the colour levels and estimate update time, in colour_detector.cpp
 * - Pins are defined in colour_detector.h (but shouldn't need to be changed)
 * 
 * Initialisation and updating
 * - Use the ColourDetector class. Constructor doesn't take any arguments
 * - Call ColourDetector.update_status() to update the status
 * 
 * Reading status
 * - Statuses are defined as STATUS_BLACK, STATUS_WHITE, STATUS_RED, STATUS_YELLOW, corresponding to 0,1,2,3
 * - Read the status with ColourDetector.get_status()
 * - If there is a red mine, the index of the latest colour sensor to detect a red mine is detected 
 *   read this with ColourDetector.get_red_index()
 *   
 * Status meanings
 * - STATUS_YELLOW: At least one yellow mine was detected. There could be red mines present.
 * - STATUS_RED: At least one red mine was detected, but no yellow mines.
 * - STATUS_WHITE: At least one sensor detected white, but none detected red or yellow.
 * - STATUS_BLACK: All colour sensors detect black.
*/
 
#ifndef COLOUR_SENSORS_H_GUARD
#define COLOUR_SENSORS_H_GUARD

#include <inttypes.h>

#define START_PIN 9
#define NUM_SENSORS 1

//Yellow has highest priority, with decreasing priority down to black
#define STATUS_YELLOW 3
#define STATUS_RED 2 
#define STATUS_WHITE 1
#define STATUS_BLACK 0

class SingleSensor{
	
public:
	SingleSensor();
	void update_estimate(float dt);
	void set_pin(uint8_t pin){ this->pin = pin; }
	uint8_t get_estimate()const{ return verified_estimate; }
	
private:

	uint8_t get_closest_reading(int reading);

	uint8_t pin;
	float timer;
	float change_time;
	uint8_t current_estimate;
	uint8_t verified_estimate;
};

class ColourDetector{

public:

	ColourDetector();
	void update_status();
	uint8_t get_status()const{ return status; }
  uint8_t get_red_index()const{ return red_index; }
	
private:

	SingleSensor sensors[NUM_SENSORS];
	uint8_t status;
	uint8_t red_index;
	unsigned long prev_millis;
  
};

#endif
