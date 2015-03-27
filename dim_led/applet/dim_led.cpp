#include "WProgram.h"
int value = 0;                            // variable to keep the actual value 
int ledpin = 9;                           // light connected to digital pin 9
int ledpin_new = 10;
int delaytime = 40;
void setup() 
{ 
  // nothing for setup 
} 

void loop() 
{ 
  for(value = 0 ; value <= 255; value+=5) // fade in (from min to max) 
  { 
    analogWrite(ledpin, value);           // sets the value (range from 0 to 255) 
    analogWrite(ledpin_new, value);           // sets the value (range from 0 to 255)    
    delay(delaytime);                            // waits for 30 milli seconds to see the dimming effect 
  } 
  for(value = 255; value >=0; value-=5)   // fade out (from max to min) 
  { 
    analogWrite(ledpin, value); 
    analogWrite(ledpin_new, value);
    delay(delaytime); 
  }  
}
int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

