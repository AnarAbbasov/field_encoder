#include <morse.h>
#include <PS2Keyboard.h>
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int DataPin = 8;
const int IRQpin =  3;
//Initialise keyboard instance
PS2Keyboard keyboard;
//Define pins for morse sender instance
#define PIN_STATUS  13
#define PIN_SPEAKER 10

//initialise morse sender 
MorseSender *callsignSender;
String StartupMessage="MorseSender V1.0.0",Copyright="Anar(c) 2023";
 int disp_chars=0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
 
   delay(1000);
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  Serial.println("Keyboard Test:");
 
  lcd.print(StartupMessage);
  delay(1000);
  for(int x: StartupMessage)
  {
    lcd.scrollDisplayLeft();
     delay(500);
    }
 // delay(1000); 
 lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(Copyright);
    delay(1000);
   
  for(int y: Copyright)
  {
    lcd.scrollDisplayLeft();
     delay(500);
    }
//  delay(2000);
  lcd.clear();
  lcd.print(">");
  callsignSender = new SpeakerMorseSender(PIN_SPEAKER,600);
  callsignSender->setup();
 // callsignSender->setMessage(String("KG7RNM "));
 //lcd.autoscroll();
//lcd.setCursor(0, 0);

}


void loop() {


  


 //if(!callsignSender->continueSending())
 //{
   // callsignSender->startSending();
  //}
 
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
      
   // otherwise, just print and send all normal characters
  
   
   Serial.print(c);
   
   disp_chars++;
     Serial.print(disp_chars);
     lcd.print(c);
     if (disp_chars==16){
    lcd.scrollDisplayLeft();
     disp_chars=0;
     lcd.clear();
      
  //lcd.setCursor(0, 0);
   //lcd.print("KM>");
   // lcd.setCursor(3, 0);
   lcd.print(c);
  
     }
     
   callsignSender->setMessage(String(c));
   callsignSender->sendBlocking();
   //callsignSender->continueSending();
    
    

    }
  

  }


  

  
}
