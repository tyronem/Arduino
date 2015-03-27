#include <LiquidCrystal.h> //include LiquidCrystal library

LiquidCrystal lcd = LiquidCrystal(); //create a LiquidCrystal object to control an LCD
char string1[] = "Ty & Shonda loves Tyra"; //variable to store the string "Hello!" 
char string2[] = " Forever";

int time;
void setup(void){
  lcd.init(); //initialize the LCD
  time = millis();               // get start time of inner loop
  digitalWrite(13,HIGH); //turn on an LED for debugging
}

//Here we send the timervalue to the display
void writeUptime() {
  char uptimeVal[16];

  //build a String With the uptime
  unsigned long ut=millis();
  
  unsigned long m_sec=ut%1000;
  ut=ut/1000;
  unsigned long sec=ut%60;
  ut=ut/60;
  unsigned long m=ut%60;
  ut=ut/60;
  unsigned long h=ut%24;
  ut=ut/24;

  uptimeVal[0]=' ';
  uptimeVal[1]=' ';
  uptimeVal[2]=(h/10)+48;     
  uptimeVal[3]=(h%10)+48;
  uptimeVal[4]=':';
  uptimeVal[5]=(m/10)+48;     
  uptimeVal[6]=(m%10)+48;
  uptimeVal[7]=':';
  uptimeVal[8]=(sec/10)+48;     
  uptimeVal[9]=(sec%10)+48;
  uptimeVal[10]=':';
  uptimeVal[11]=(m_sec/100)+48;     
  m_sec=m_sec%100;
  uptimeVal[12]=(m_sec/10)+48;
  uptimeVal[13]=(m_sec%10)+48;
  uptimeVal[14]=' ';
  uptimeVal[15]=' ';
  lcd.printIn(uptimeVal);
}

void loop(void){
  lcd.commandWrite(2); //bring the cursor to the starting position
  delay(1000); //delay 1000 ms to view change
  lcd.printIn(string1); //send the string to the LCD
  delay(1000); //delay 1000 ms to view change
  lcd.printIn(string2); //send the string to the LCD
  delay(1000); //delay 1000 ms to view change
  //writeUptime();
  //delay(1000);

} //repeat forever
