#include "CapacitiveSensor.h"
#include <Keyboard.h>

#include "capacitiveKey.h"

//#define SERIAL_OUTPUT
#define DISABLE_PIN 15

void setup() {
  #ifdef SERIAL_OUTPUT
  Serial.begin(115200);
  #endif
  Keyboard.begin();
  pinMode(DISABLE_PIN, INPUT_PULLUP);
}

CapacitiveKey key0 = CapacitiveKey(
  2,    //resistor leg 1 + metal plate
  5,    //resistor leg 2
  5,    //activation point
  'z'   //keyboard key
);
CapacitiveKey key1 = CapacitiveKey(
  6,    //resistor leg 1 + metal plate
  9,    //resistor leg 2
  5,    //activation point
  'x'   //keyboard key
);

void loop() {
  bool keyboardActive = digitalRead(DISABLE_PIN);
  key0.keyUpdate(keyboardActive);
  key1.keyUpdate(keyboardActive);

  #ifdef SERIAL_OUTPUT
  Serial.print(key0.sample);
  Serial.print(",");
  Serial.println(key1.sample);
  #endif
}
