#include "WProgram.h"
#include "LiquidCrystal.h"
//include LiquidCrystal library

LiquidCrystal lcd = LiquidCrystal(); //create a LiquidCrystal object to control an LCD
char string1[] = "Tyrone and Shonda"; //variable to store the string "Hello!" 
char string2[] = "loves Tyra Mitchell";
char string3[] = "Forever and Ever.";
char string4[] = "'Smiley! 2/20/2007'";

#define LINE_1 0x80 // control codes for line 1
#define LINE_2 0xC0 // control codes for line 2
#define LINE_3 0x94 // control codes for line 3
#define LINE_4 0xD4 // control codes for line 4

/*

The pinout is as follows:

Arduino         LCD                    20x4 pin
2               Enable                   6
3               Data Bit 0 (DB0)          7
4               (DB1)                    8
5               (DB2)                    9
6               (DB3)                    10
7               (DB4)                    11
8               (DB5)                    12
9               (DB6)                    13
10              (DB7)                    14
11              Read/Write (RW)          5
12              Register Select (RS)     4 



*/

void setup(void){
  lcd.init(); //initialize the LCD
  //this command, on a 4-line interface will allow you to display on all 4 lines with a little help.
  //you must do this before you do anything else.
  lcd.commandWrite(B111000); // 8 bit interface, 5x8dots,2 lines
  delay(100);
  digitalWrite(13,HIGH); //turn on an LED for debugging
}



void loop(void){
  lcd.commandWrite(1); //bring the cursor to the starting position
  delay(1500); //delay 1000 ms to view change
  lcd.printIn(string1); //send the string to the LCD
  delay(1500); //delay 1000 ms to view change
  
  lcd.commandWrite(LINE_2);
  lcd.printIn(string2); //send the string to the LCD
  delay(1500); //delay 1000 ms to view change
  
  lcd.commandWrite(LINE_3);
  lcd.printIn(string3); //send the string to the LCD
  delay(1500); //delay 1000 ms to view change
  
  lcd.commandWrite(LINE_4);
  lcd.printIn(string4); //send the string to the LCD
  delay(1500); //delay 1000 ms to view change
}
int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

