/* Blinking LED without using delay
 * --------------------------------
 *
 * turns on and off a light emitting diode(LED) connected to a digital  
 * pin, without using the delay() function.  this means that other code
 * can run at the same time without being interrupted by the LED code.
 *
 * Created 14 February 2006
 * David A. Mellis
 * http://arduino.berlios.de
 */

int ledPin = 13;                // LED connected to digital pin 13
int value = LOW;                // previous value of the LED
long previousMillis = 0;        // will store last time LED was updated
long interval = 500;           // interval at which to blink (milliseconds)

void setup()
{
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
}

void loop()
{
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, is the difference
  // between the current time and last time we blinked the LED bigger than
  // the interval at which we want to blink the LED.
  if (millis() - previousMillis > interval) {
    previousMillis = millis();   // remember the last time we blinked the LED

    // if the LED is off turn it on and vice-versa.
    if (value == LOW)
      value = HIGH;
    else
      value = LOW;

    digitalWrite(ledPin, value);
  }
}
