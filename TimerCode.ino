#include "TM1637.h"
#define CLK 3//pins definitions for TM1637 and can be changed to other ports       
#define DIO 2
TM1637 tm1637(CLK,DIO);
TM1637 display(CLK, DIO);

byte timecount = 0;
byte digits; //reference point

typedef struct {
  byte time_placement; //placement of the number of the module (0,1,2 or 3)
  byte displayed_number; //number displayed (0 - 9)
} digitPoints;
digitPoints dynamicArray[4]; //creates 4 digitPoints objects (size of array is created by the number of Ndigits)

void setup()
{
  Serial.begin(9600);
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

void loop()
{
  timesetup();

  timecount++;
  delay(100);
}

void timesetup() {
  byte nDigits = floor(log10(abs(timecount))) + 1;
  digits = 4-nDigits;
  timeplace(nDigits, timecount);
  for (int i = 0; i <= nDigits-1; i++) {  tm1637.display(dynamicArray[i].time_placement, dynamicArray[i].displayed_number); }
}


void timeplace(byte nDigits, int timecount) {
  if (nDigits > 0 && nDigits < 5) {
    dynamicArray[(nDigits-1)] = {(nDigits-1)+digits, timecount%10};
    timeplace(nDigits-1, timecount/10);
  }
}
