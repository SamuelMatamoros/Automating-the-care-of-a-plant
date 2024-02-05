#include <Arduino.h>

uint32_t delayT;

void setup() {
  Serial.begin(9600);

  pinMode(A0, INPUT);
  pinMode(2,INPUT);
  pinMode(3, OUTPUT);
  pinMode(13, OUTPUT);

}

void loop() {

  int knobVal = analogRead(A0);
  Serial.println(knobVal);

  int delayT = knobVal / 10;

  if (digitalRead(2) == HIGH) {
    digitalWrite(13, HIGH);
    while (digitalRead(2) == HIGH) {
      digitalWrite(3, HIGH);
      delay(delayT);
      digitalWrite(3, LOW);
      delay(delayT);
    }
  }
  else {
    digitalWrite(13, LOW);
  }

}