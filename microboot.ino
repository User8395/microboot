#include <EEPROM.h>
#include "serialstream.h"
#define FEATURES ""

void(* reset) (void) = 0;
void startupopts();
void run(String thingtorun);

void setup() {
  Serial.begin(115200);
  delay(5000);
  Serial.println("microboot 0.0.0");
  Serial.println("Extra features: " FEATURES);
  if (EEPROM.read(0) == 1) {
    Serial.println("Loading startup options");
    EEPROM.put(0, 0);
    startupopts();
  } else {
    Serial.println("Press RESET to show startup options");
    EEPROM.put(0, 1);
    delay(3000);
  }
  EEPROM.put(0, 0);
  Serial.println("Running from serial stream");
  run("serial");
  Serial.println("Program execution complete, halting");
  Serial.println("SYSTEM HALTED");
}

void loop() {}

void startupopts() {
  Serial.println("Startup options are currently unavailable right now");
  Serial.println("Resetting...");
  delay(100);
  reset();
}

void run(String thingtorun) {
  if (thingtorun == "serial") {
    serialstream.init();
  }
  reset();
}