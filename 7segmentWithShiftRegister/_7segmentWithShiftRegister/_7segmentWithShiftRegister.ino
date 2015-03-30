/* LucidTronix 7 Segment LED
 * and 74HC595 shift register
 * Tutorial at: 
 * http://www.lucidtronix.com/tutorials/41
 */

int dataPin = 2;
int latchPin = 3;
int clockPin = 4;
/* Here a zero corresponds to an LED being ON and a 1 corresponds to an LED being OFF.
Maybe a little counter-intuitive, but it is this way because the seven segment Display 
we are using is a common anode device so you toggle the different LEDs on and 
off by connecting ground to the LED pins. 
*/
/* 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, F, C, - */
byte dec_digits[] = {0b11000000,0b11111001,0b10100100,0b10110000,0b10011001,0b10010010,0b10000011,0b11111000,0b10000000,0b10011000, 0b10001110, 0b01000110, 0b10111111};

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0b11111111); 
  digitalWrite(latchPin, HIGH);
}

void loop() {
  for (int numberToDisplay = 0; numberToDisplay < 13; numberToDisplay++) {
    // take the latchPin low so 
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[numberToDisplay]); 
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    // pause before next value:
    delay(750);
  }
}
