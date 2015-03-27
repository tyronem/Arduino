#include "WProgram.h"
/* Ultrasound Sensor 
 *------------------
 *
 * Reads values (00014-01199) from an ultrasound sensor (3m sensor)
 * and writes the values to the serialport.
 *
 * http://www.xlab.se | http://www.0j0.org
 * copyleft 2005 Mackie for XLAB | DojoDave for DojoCorp
 *
 * extended 02.01.2007 by aktor
 * used for PING Ultrasonic Range Finder (#28015 from Parallax)
 * detection of two distance ranges for two digital outputs
 */

void setup();
void loop();
int ultraSoundSignal = 7; // Ultrasound signal pin
int val = 0;
int ultrasoundValue = 0;
int timecount = 0; // Echo counter
int ledPin1 = 13; // LED at digital pin 13
int ledPin2 = 10; // LED at digital pin 10

void setup() {
  beginSerial(9600);			// Sets the baud rate to 9600
  pinMode(ledPin1, OUTPUT);		// Sets the digital pin 13 as output
  pinMode(ledPin2, OUTPUT);		// Sets the digital pin 10 as output
}

void loop() {
  timecount = 0;
  val = 0;
  pinMode(ultraSoundSignal, OUTPUT); // Switch signalpin to output

  /* Send low-high-low pulse to activate the trigger pulse of the sensor
   * -------------------------------------------------------------------
   */

  digitalWrite(ultraSoundSignal, LOW); // Send low pulse
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(ultraSoundSignal, HIGH); // Send high pulse
  delayMicroseconds(5); // Wait for 5 microseconds
  digitalWrite(ultraSoundSignal, LOW); // Holdoff

  /* Listening for echo pulse
   * -------------------------------------------------------------------
   */

  pinMode(ultraSoundSignal, INPUT); // Switch signalpin to input
  val = digitalRead(ultraSoundSignal); // Append signal value to val
  while(val == LOW) { // Loop until pin reads a high value
    val = digitalRead(ultraSoundSignal);
  }

  while(val == HIGH) { // Loop until pin reads a high value
    val = digitalRead(ultraSoundSignal);
    timecount = timecount +1;		// Count echo pulse time
  }

  /* Writing out values to the serial port
   * -------------------------------------------------------------------
   */

  ultrasoundValue = timecount; // Append echo pulse time to ultrasoundValue

  serialWrite('A'); // Example identifier for the sensor
  printInteger(ultrasoundValue);
  serialWrite(10);
  serialWrite(13);

  /* Lite up LED if the timevalues passed by the echo pulse (distances mesured an compared as dispayed on the serial monitor) 
   * -------------------------------------------------------------------
   */


  //LED1 (GREEN) ON, Pin13, distances high   
  if((timecount <= 1300) && (timecount >= 1100)){ 
    digitalWrite(ledPin1, HIGH);
    delay(1200);			// waits for a second
  }
  else
  {
    digitalWrite(ledPin1, LOW);
  }

  //LED2 (RED) ON, Pin10, distance low
  if((timecount <= 900) && (timecount >= 700)){ 
    digitalWrite(ledPin2, HIGH);
    delay(1300);			// waits for a second
  }
  else
  {
    digitalWrite(ledPin2, LOW);
  }

  /* Delay of program
   * -------------------------------------------------------------------
   */

  delay(400);   //orig 100
} 

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

