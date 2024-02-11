#include <Arduino.h>

void setup() {
    Serial.begin(9600);
}

void loop() {
    delay(1000);

    int photoValue = analogRead(A0);
    Serial.print(F("Photoresistor value: "));
    Serial.println(photoValue);
}