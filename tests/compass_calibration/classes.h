/*
 * classes.h
 *
 *  Created on: 7 Nov 2018
 *      Author: tom
 *
 *  For the declaration of classes
 */

// ** Preamble ** //

// **** PUBLIC **** //

class digitalOutput { // A generic digital Output
public:
	int pin;
	bool defaultStatus, status;
	digitalOutput(int inputPin, bool inputDefault = 0, bool inputStatus = 0) {
		// sets the relevant pin to be an output. Outpus **MUST** be defined with a pin.
		pin = inputPin;
		defaultStatus = inputDefault;
		status = inputStatus;
		pinMode(pin, OUTPUT);
		digitalWrite(pin, status);
	}
	void set_default () {
		// sets the output to the default value
		status = defaultStatus;
		digitalWrite(pin, status);
	}
	void set (bool newStatus) {
		// sets output to on or off
		status = newStatus;
		digitalWrite(pin, status);
	}
	bool get () {
		// returns current state
		return status;
	}
};

class led { // A class for LEDs
  public:
    int pin;
    bool status;
    led(int inputPin, bool inputStatus = 0) {
      // creates an LED, assigns its pin to be an output, and sets it to "status". LEDs **MUST** be defined with a pin.
      pin = inputPin;
      status = inputStatus;
      pinMode(pin, OUTPUT);
      digitalWrite(pin, status);
    }
    void set(bool newStatus = 0){
      //change led to on/off. Default Off.
      status = newStatus;
      digitalWrite(pin, status);
    }
};

class motor { // A class for driving motors via the Adafruit Motor Shield V2
  public:
    int port, speed;
    Adafruit_DCMotor *thisMotor;
    Adafruit_MotorShield assignedMotorShield;
  motor(int inputPort, int inputSpeed = 0){
    //creates ada-fruit object and assigns to port with initial speed default 0
    port = inputPort;
    speed = inputSpeed;
  }
  void init() {
    thisMotor = assignedMotorShield.getMotor(port);
    thisMotor->setSpeed(speed);
  }
  void setSpeed(int newSpeed){
    //sets new speed for the motor
    speed = newSpeed;
    thisMotor->setSpeed(speed);
  }
  void setForward(){
    //sets motor to forward direction
    thisMotor->run(FORWARD);
  }
  void setBackward(){
    //sets motor to backward direction
    thisMotor->run(BACKWARD);
  }
  void emergencyStop(){
    //stops motor immediately and resets speed to zero
    thisMotor->run(RELEASE);
    speed = 0;
    thisMotor->setSpeed(speed);
  }
};

class coord { // A class for coordinates used in navigation
	public:
		int x, y;
		coord(int inputX = 0, int inputY = 0) {
			/* Constructor, can use:
			 * coord newCoord(100, 12);
			 * to create a constructor
			 * (defaults to (0, 0)
			 */
			x = inputX;
			y = inputY;
		}
		coord add(coord inputCoord) {
			// Returns a coordinate that is the original plus the input elementwise
			coord outputCoord;
			outputCoord.x = x + inputCoord.x;
			outputCoord.y = y + inputCoord.y;
			return outputCoord;
		}
		coord subtract(coord inputCoord) {
			// Returns a coordinate that is the original minus the input elementwise
			coord outputCoord;
			outputCoord.x = x - inputCoord.x;
			outputCoord.y = y - inputCoord.y;
			return outputCoord;
		}
		float distance(coord inputCoord) {
			// Returns the distance between two coordinates
			coord difference = subtract(inputCoord);
			return pow(pow(difference.x,2) + pow(difference.y,2), 0.5);
    		}
};

class rectangle { // A class used to denote "keepout zones"
	/* 
	 *     x0    x1
	 *      |    |
	 *  y1--a----b--
	 *      |    |
	 *  y0--c----d--
	 *      |    |
	 */
	public:
		int x0, x1, y0, y1;
                coord a, b, c, d;
                rectangle(int inputX0 = 0, int inputX1 = 0, int inputY0 = 0, int inputY1 = 0) {
                        // Creates the coordinates for the corners, a, b, c, d (see diagram above)
                        x0 = inputX0; x1 = inputX1; y0 = inputY0; y1 = inputY1;
                        a = coord(x0, y1);
                        b = coord(x1, y1);
                        c = coord(x0, y0);
                        d = coord(x1, y0);
                }
		bool isInside(coord inputCoord) {
			// Returns True if "inputCoord" is inside the rectangle object. Else returns False.
			if ( (inputCoord.x > x0 && inputCoord.x < x1) && (inputCoord.y > y0 && inputCoord.y < y1) ) {
				return 1;
			} else {
				return 0;
			}
		}
		coord nearestCorner(coord inputCoord) {
			// Returns the coordinate of the nearest corner to the "inputCoord"
			coord corner = a;
			if (inputCoord.distance(b) < inputCoord.distance(corner)) {
				corner = b;
			}
			if (inputCoord.distance(c) < inputCoord.distance(corner)) {
				corner = c;
			}
			if (inputCoord.distance(d) < inputCoord.distance(corner)) {
				corner = d;
			}
			return corner;
		}
};

class compass { // A class for the LSM303 Accelerometer and Magnetometer
    public:
		Adafruit_LSM303_Mag_Unified assignedCompass;
		int declinationAngle;
        float xFluxCorrection;
        float yFluxCorrection;
		compass(Adafruit_LSM303_Mag_Unified inputCompass, int inputDeclinationAngle = 0) {
			// Constructor for compass wrapper class; specify sensor object and local declination angle (default zero)
			assignedCompass = inputCompass;
			declinationAngle = inputDeclinationAngle;
		}
		void init() {
			// Wrapper function to start compass functionality
			assignedCompass.begin();
		}
		float getHeading() {
			// Get current compass flux readings
			sensors_event_t reading;
			assignedCompass.getEvent(&reading);
			// Calculate current bearing
			float outputHeading = (atan2((reading.magnetic.y - yFluxCorrection), (reading.magnetic.x - xFluxCorrection)) * 180) / PI;
			// Account for local magnetic flux changes by subtracting declination angle
			outputHeading = outputHeading - declinationAngle;
			// Correct for negative bearing results
			if (outputHeading < 0) {
				outputHeading = 360 + outputHeading;
			}
			return outputHeading;
		}
};

class ultrasound{
    public:
    NewPing assignedSensor = NewPing(0, 0);
    ultrasound(NewPing inputSensor) {
        assignedSensor = inputSensor;
    }
    int getReading(){
        return assignedSensor.ping_cm();
    }
};

class infrared { // A class for Infrared Sensors
    public:
		char port;
		infrared(char inputPort) {
			port = inputPort;
		}
		float voltage() {
			return analogRead(port) * 0.0048828125;
		}
		float distance() {
			return IR_SCALE * pow(voltage(), -1);
		}
};

// **** PRIVATE **** //
