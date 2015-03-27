#include <LiquidCrystal.h> //include LiquidCrystal library

LiquidCrystal lcd = LiquidCrystal(); //create a LiquidCrystal object to control an LCD
char string1[] = "Tyrone and Shonda loves Tyra"; //variable to store the string "Hello!" 
char string2[] = " Forever";
char string3[] = "Line 3";
char string4[] = "Line 4";

#define LINE_1 0x80 // control codes for line 1
#define LINE_2 0xC0 // control codes for line 2
#define LINE_3 0x94 // control codes for line 3
#define LINE_4 0xD4 // control codes for line 4

void setup(void){
  lcd.init(); //initialize the LCD
  digitalWrite(13,HIGH); //turn on an LED for debugging
}



void loop(void){
  lcd.commandWrite(1); //bring the cursor to the starting position
  delay(1000); //delay 1000 ms to view change
  lcd.printIn(string1); //send the string to the LCD
  delay(1000); //delay 1000 ms to view change
  
  lcd.printIn(string2); //send the string to the LCD
  delay(1000); //delay 1000 ms to view change
  
  //lcd.commandWrite(2); //bring the cursor to the starting position
  //delay(1000); //delay 1000 ms to view change
  //lcd.printIn(string1); //send the string to the LCD
  //delay(1000); //delay 1000 ms to view change
} //repeat forever
