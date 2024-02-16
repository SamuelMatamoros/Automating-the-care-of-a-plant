#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(16, OUTPUT);
}

void loop() {

  Serial.println(touchRead(0));

  if (touchRead(4) < 40) {
    digitalWrite(2, HIGH);
    digitalWrite(16, HIGH);
  } else {
    digitalWrite(2, LOW);
    digitalWrite(16, LOW);
  }
  delay(100);
  
}