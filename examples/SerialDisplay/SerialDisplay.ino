/*
   Displays text sent over the serial port (e.g. from the Serial Monitor) on
   an attached LCD.
   YWROBOT
  Compatible with the Arduino IDE 1.0
  Library version:1.1
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//    Wire.setClock(clockFrequency);      not in this library



LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
#define clockrate 100000
  Wire.begin();
  Wire.setClock(clockrate);  // force data rate to known value
  lcd.init();                      // initialize the lcd
  lcd.backlight();
  Serial.begin(9600);
}

void loop()
{
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }
}
