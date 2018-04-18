//char inByte; // incoming serial byte
#include "LiquidCrystal.h"
String inputString = ""; // a string to hold incoming data
boolean stringComplete = false; 
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int i,j;
void setup()
{
  // start serial port at 9600 bps:
 // Serial1.begin(9600);
  Serial.begin(9600);
  lcd.begin(16, 2);
// establishContact(); // send a byte to establish contact until receiver responds 

pinMode(P1_6,INPUT);
pinMode(P1_7,INPUT);
pinMode(P1_4,INPUT);
pinMode(P1_7,INPUT);}

void loop()
{
      while (Serial.available())
         {

          
          
                    char inChar = Serial.read(); 
                    // add it to the inputString          
                    inputString += inChar;
                    
                    if (inChar == '\n') {
                              stringComplete = true;
                              break;
                                        }
         }          
          if (stringComplete) {
        if(digitalRead(P1_6)==HIGH)
        { i=1;}
        else
        { i=0;}
         if(digitalRead(P1_7)==HIGH)
        { j=1;}
        else
        { j=0;}
        lcd.setCursor(0,0);
        lcd.print("Precipitation ");
        lcd.setCursor(0,1);
        lcd.print(inputString.charAt(0));
        lcd.print(inputString.charAt(1));
//        lcd.setCursor(0,1);
//        lcd.print("T1   ");
//        lcd.print("1 ");
//        lcd.print("T2   ");
//        lcd.print("0 ");
        
        inputString = "";
        stringComplete = false;
                             }

       
          delay(500);

       

}


//void establishContact() {
//  while (Serial.available() <= 0) {
//    lcd.setCursor(0,1);
//    lcd.println('A'); // send a capital A
//    delay(300);
//  }
//}

