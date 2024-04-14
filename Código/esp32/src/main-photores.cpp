#include <Arduino.h>
#define photoresistorPin 25

void setup() {
    Serial.begin(9600);
    pinMode(photoresistorPin,INPUT);
}

void loop() {
    Serial.println(analogRead(photoresistorPin));
    // delay(500);
}