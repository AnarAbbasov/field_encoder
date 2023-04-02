//#include <PS2Keyboard.h>

#include <PS2Keyboard.h>




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
