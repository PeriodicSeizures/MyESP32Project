#include <Arduino.h>

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