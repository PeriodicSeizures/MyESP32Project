#include <Arduino.h>
/*
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

DHT_Unified dht(14, DHT11);

uint32_t delayMS;

void setup() {
  Serial.begin(115200);

  dht.begin();
  
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);

  delayMS = sensor.min_delay / 1000;
}

void loop() {
  delay(delayMS);

  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
}
*/



/*
int dataPin = 14; //4;
int latchPin = 15; //5;
int clockPin = 16; //6;

byte leds = 0;

// forward declare
void updateShiftRegister();

void setup() 
{
  Serial.begin(115200);

  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() 
{
  leds = 0;
  updateShiftRegister();
  delay(500);
  for (int i = 0; i < 8; i++)
  // B?
  //int i = 1;
  {
    // Q a-b-c-d-e-f-g-h
    //  are reversed in index
    // Q a7-b6-c5-d4-e3-f2-g1-h0
    // Qb is connected, so index is 6
    bitSet(leds, i);
    Serial.print(F("LED: "));
    Serial.print(i);
    Serial.println();
    updateShiftRegister();
    delay(1000);
  }
}

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
*/



/*
#include <LiquidCrystal_74HC595.h>

#define SR_DATA 14
#define SR_LATCH 15
#define SR_CLOCK 16

LiquidCrystal_74HC595 lcd(SR_DATA, SR_CLOCK, SR_LATCH, 1, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Hello, World 1");
  lcd.setCursor(0, 1);
  lcd.print("Hello, World 2");
  //lcd.print(millis() / 1000);
  delay(1000);
}*/



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