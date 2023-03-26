#include <PS2Keyboard.h>

#include <PS2Keyboard.h>

/*


  LiquidCrystal Library - Autoscroll


 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal


 library works with all LCD displays that are compatible with the


 Hitachi HD44780 driver. There are many of them out there, and you


 can usually tell them by the 16-pin interface.


 This sketch demonstrates the use of the autoscroll()


 and noAutoscroll() functions to make new text scroll or not.


 The circuit:


 * LCD RS pin to digital pin 12


 * LCD Enable pin to digital pin 11


 * LCD D4 pin to digital pin 5


 * LCD D5 pin to digital pin 4


 * LCD D6 pin to digital pin 3


 * LCD D7 pin to digital pin 2


 * LCD R/W pin to ground


 * 10K resistor:


 * ends to +5V and ground


 * wiper to LCD VO pin (pin 3)


 Library originally added 18 Apr 2008


 by David A. Mellis


 library modified 5 Jul 2009


 by Limor Fried (http://www.ladyada.net)


 example added 9 Jul 2009


 by Tom Igoe


 modified 22 Nov 2010


 by Tom Igoe


 modified 7 Nov 2016


 by Arturo Guadalupi


 This example code is in the public domain.


 http://www.arduino.cc/en/Tutorial/LiquidCrystalAutoscroll


*/


// include the library code:

#include <LiquidCrystal.h>
//#include < PS2Keyboard.h>




// initialize the library by associating any needed LCD interface pin

// with the arduino pin number it is connected to


const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 2;


LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int DataPin = 8;
const int IRQpin =  3;

PS2Keyboard keyboard;

void setup() {


  // set up the LCD's number of columns and rows:


  lcd.begin(16, 2);
   delay(1000);
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  Serial.println("Keyboard Test:");
 lcd.print("Keyboard Test:");
}


void loop() {


  
lcd.autoscroll();


 
if (keyboard.available()) {
   
     
// read the next key
  char c = keyboard.read();
    
    // check for some of the special keys
    if (c == PS2_ENTER) {
      Serial.println();
     
    } else if (c == PS2_TAB) {
      Serial.print("[Tab]");
    } else if (c == PS2_ESC) {
      Serial.print("[ESC]");
    } else if (c == PS2_PAGEDOWN) {
      Serial.print("[PgDn]");
    } else if (c == PS2_PAGEUP) {
      Serial.print("[PgUp]");
    } else if (c == PS2_LEFTARROW) {
      Serial.print("[Left]");
    } else if (c == PS2_RIGHTARROW) {
      Serial.print("[Right]");
    } else if (c == PS2_UPARROW) {
      Serial.print("[Up]");
    } else if (c == PS2_DOWNARROW) {
      Serial.print("[Down]");
    } else if (c == PS2_DELETE) {
      Serial.print("[Del]");
    } else {
      
      // otherwise, just print all normal characters
   Serial.print(c);
       lcd.print(c);
       //lcd.print("Keyboard Test:");
    delay(500);
//lcd.clear();
    }
  

  }


  



}
