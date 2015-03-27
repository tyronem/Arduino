#include <OneWire.h>
#include <SoftwareSerial.h>
#include <serLCD.h>

/* DS18S20 Temperature chip i/o  */

OneWire  ds(10);  // on pin 8
serLCD lcd = serLCD(12); // desired pin
/*
int redPin   = 11;   // Red LED,   connected to digital pin 9
int greenPin = 9;  // Green LED, connected to digital pin 10
int bluePin  = 10;  // Blue LED,  connected to digital pin 11

// Program variables
int redVal   = 255; // Variables to store the values to send to the pins
int greenVal = 1;   // Initial values are Red full, Green and Blue off
int blueVal  = 1;
*/

void setup(void) {
  // initialize inputs/outputs
  // start serial port
  Serial.begin(9600);
  //led.setup();
  delay(1000);
  
  /*

  pinMode(redPin,   OUTPUT);   // sets the pins as output
  pinMode(greenPin, OUTPUT);   
  pinMode(bluePin,  OUTPUT); 

  analogWrite(redPin,   0);   // Write current values to LED pins
  analogWrite(greenPin, 0); 
  analogWrite(bluePin,  0);  
  */
}


void loop(void) {
  byte i;
  byte present = 0;
  byte data[12];
  byte addr[8];
  int Temp;
  if ( !ds.search(addr)) {
    Serial.print("No more addresses.\n");
    ds.reset_search();
    return;
  }

  Serial.print("R=");  //R=28 Not sure what this is
  for( i = 0; i < 8; i++) {
    Serial.print(addr[i], HEX);
    Serial.print(" ");
  }

  if ( OneWire::crc8( addr, 7) != addr[7]) {
    Serial.print("CRC is not valid!\n");
    return;
  }

  if ( addr[0] != 0x28) {
    Serial.print("Device is not a DS18B20 family device.\n");
    return;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44,1);	   // start conversion, with parasite power on at the end

  delay(1000);     // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.

  present = ds.reset();
  ds.select(addr);
  ds.write(0xBE);	   // Read Scratchpad

  //Serial.print("P=");
  //Serial.print(present,HEX);
  //Serial.print(" ");
  for ( i = 0; i < 9; i++) {	     // we need 9 bytes
    data[i] = ds.read();
    Serial.print(data[i], HEX);
    Serial.print("  ");
  }
  Temp=(data[1]<<8)+data[0];//take the two bytes from the response relating to temperature

  Temp=Temp>>4;//divide by 16 to get pure celcius readout
  int TempC = Temp;
  //next line is Fahrenheit conversion
  int TempF=Temp*1.8+32; // comment this line out to get celcius

  //Serial.print("T=");//output the temperature to serial port

  Serial.print(TempF);
  Serial.print(TempC);
  lcd.clear();
  lcd.selectLine(1);
  //lcd.print("Temp: ");
  lcd.print(TempF);
  lcd.print("F");
  
  lcd.selectLine(2);
  //lcd.print("Temp: ");
  lcd.print(TempC);
  lcd.print("C");
  
  //led.at(1,1,"Temp: ");
  //led.at(1,7, Temp);
  /*
  if (Temp <= 70) {
    redVal = 0;
    greenVal = 0;
    blueVal = 255;
    led.at(2,1, "Cool       ");
  }
  if (Temp > 70 && Temp <= 79) {
    redVal = 0;
    greenVal = 255;
    blueVal = 0;
    led.at(2,1, "Normal     ");
  }
  if (Temp >= 80) {
    redVal = 255;
    greenVal = 0;
    blueVal = 0;
    led.at(2,1, "Hot       ");
  }
  */
  /*
  analogWrite(redPin,   redVal);   // Write current values to LED pins
  analogWrite(greenPin, greenVal); 
  analogWrite(bluePin,  blueVal);  
  */

  delay(700);


  //  Serial.print("  ");


  Serial.print(" CRC=");
  Serial.print( OneWire::crc8( data, 8), HEX);
  Serial.println();
}



