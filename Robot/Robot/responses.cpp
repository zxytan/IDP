#include "Robot.h"

void Robot::yellow_response() {
	delay(3000); //stationary wait for 3 seconds

	//flash yellow LED for 2 seconds 
	for (i=0; i<= 8; ++i)
		digitalWrite(yellow_LED, HIGH);
		delay(250);
		digitalWrite(yellow_LED, LOW);
		delay(250);
	



}
