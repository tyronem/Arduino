#include "WProgram.h"
void setup();
unsigned long ping();
void loop();
unsigned long echo = 0;
int ultraSoundSignal = 7; // Ultrasound signal pin
unsigned long ultrasoundValue = 0;
int warn = 6;
int angry = 5;
int pulse = warn;
int delayTime = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(ultraSoundSignal,OUTPUT);
  pinMode(pulse, OUTPUT);
  pinMode(angry, OUTPUT);
  digitalWrite(warn, LOW);
  digitalWrite(angry, LOW);
}

unsigned long ping(){
  pinMode(ultraSoundSignal, OUTPUT); // Switch signalpin to output
  digitalWrite(ultraSoundSignal, LOW); // Send low pulse
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(ultraSoundSignal, HIGH); // Send high pulse
  delayMicroseconds(5); // Wait for 5 microseconds
  digitalWrite(ultraSoundSignal, LOW); // Holdoff
  pinMode(ultraSoundSignal, INPUT); // Switch signalpin to input
  digitalWrite(ultraSoundSignal, HIGH); // Turn on pullup resistor
  echo = pulseIn(ultraSoundSignal, HIGH); //Listen for echo
  ultrasoundValue = (echo / 58.138) * .39; //convert to CM then to inches
  return ultrasoundValue;
}

void loop()
{
  int x = 0;

  x = ping();
  Serial.println(x);
  if (x > 40) {
    delayTime = 100;   
    pulse = warn;
  }
  else if (x > 20) {
    delayTime = 400;
    pulse = warn;
  }
  else {
    delayTime = 900;
    pulse = angry;
  }

  digitalWrite(pulse, HIGH);
  //delayMicroseconds(delayTime);
  delay(delayTime);
  digitalWrite(pulse, LOW);

  //turn both the lights off
  digitalWrite(angry, LOW);
  digitalWrite(warn, LOW);
  //delay(250); //delay 1/4 seconds.
  delay(1000); //delay 1/4 seconds.
}

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

