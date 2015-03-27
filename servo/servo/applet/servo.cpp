#include "WProgram.h"
void doServo();
void calculateNowPulse();
//from http://dma.ucla.edu/senselab/node/386

int minPulse = 500; // Pulse for minimum servo position (microseconds)
int maxPulse = 2500; // Pulse for maximum servo position (microseconds)
int refreshTime = 20; // the time needed in between pulses (milliseconds)
int servoPin = 2; // you decide which pin to put the servo on!
int lastPulse = 0;
int pulse = 0;

int nowPulse = 500; // nowPulse will always store the current pulse that we're giving to the servo
int temp; // always good to have a temp variable

// this function stands on its own... all you have to do is make sure the "nowPulse" variable is updated and that it equals something between "minPulse" and "maxPulse"
void doServo() {
  // pulse the servo again if rhe refresh time (20 ms) have passed:
  if (millis() - lastPulse >= refreshTime) {
    digitalWrite(servoPin, HIGH); // Turn the motor on
    delayMicroseconds(nowPulse); // Length of the pulse sets the motor position
    digitalWrite(servoPin, LOW); // Turn the motor off
    lastPulse = millis(); // save the time of the last pulse
  }
}

// replace this with whatever you want... read an analog sensor, arbitrarily choose a number, do something based on time... whatever. I'm choosing to listen to the computer for an instruction.
void calculateNowPulse() {
/*   
  while (Serial.available()>0) { // while there are bytes to read
    temp = Serial.read(); // read one
    nowPulse = minPulse + 15*temp/2; // this seems arbitary but its actually just approximately precalculating: nowPulse=minPulse+temp*(maxPulse-minPulse)/255
  }
*/

  temp = 8;
  nowPulse = minPulse + 15*temp/2;
}

void setup(void) {
  pinMode(servoPin, OUTPUT); // Set servo pin as an output pin
  pulse = nowPulse; 
  Serial.begin(9600); // let's get this PC connection party started
}

// the loop is super simple... figure out how long the pulse should be and then doing servo stuff
void loop(void) {
  calculateNowPulse();
  doServo();
}
int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

