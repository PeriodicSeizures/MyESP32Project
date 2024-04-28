#include <Arduino.h>

#include <LiquidCrystalIO.h>

//
// these are the pins onto which the shift register is connected to the arduino
//

#define WRITE_CLOCK_PIN 16
#define WRITE_DATA_PIN 14
#define WRITE_LATCH_PIN 15

//
// these are the shift register pins that you've connected your display to
//
const int rs = SHIFT_REGISTER_OUTPUT_CUTOVER + 0;
const int en = SHIFT_REGISTER_OUTPUT_CUTOVER + 1;
const int d4 = SHIFT_REGISTER_OUTPUT_CUTOVER + 2;
const int d5 = SHIFT_REGISTER_OUTPUT_CUTOVER + 3;
const int d6 = SHIFT_REGISTER_OUTPUT_CUTOVER + 4;
const int d7 = SHIFT_REGISTER_OUTPUT_CUTOVER + 5;

//
// Construction is very similar to the regular library, the only difference is that we can choose to provide
// a different means of reading and writing
//
LiquidCrystal lcd(rs, en, d4, d5, d6, d7, outputOnlyFromShiftRegister(WRITE_CLOCK_PIN, WRITE_DATA_PIN, WRITE_LATCH_PIN));

void setup() {
  // set up the LCD's number of columns and rows, must be called.
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}