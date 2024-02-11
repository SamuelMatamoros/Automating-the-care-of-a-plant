#include <Arduino.h>

#define inputCLK 4
#define inputDT 5
// for button soder 10k resistor
#define button 6

#define ledCW 8
#define ledCCW 9

int counter = 0;
int currentStateCLK;
int previousStateCLK;

void setup() {

  Serial.begin(9600);
  pinMode(inputCLK, INPUT);
  pinMode(inputDT, INPUT);
  pinMode(button, INPUT);
  pinMode(ledCW, OUTPUT);
  pinMode(ledCCW, OUTPUT);

  previousStateCLK = digitalRead(inputCLK);

}

void loop() {

  currentStateCLK = digitalRead(inputCLK);
  int buttonState = digitalRead(button);
  

  if (currentStateCLK != previousStateCLK) {

    if (digitalRead(inputDT) == currentStateCLK) {
      counter --;
      digitalWrite(ledCW, LOW);
      digitalWrite(ledCCW, HIGH);
    }
    else {
      counter ++;
      digitalWrite(ledCW, HIGH);
      digitalWrite(ledCCW, LOW);
    }
    Serial.print("CLK: ");
    Serial.print(digitalRead(inputCLK));
    Serial.print("    DT: ");
    Serial.print(digitalRead(inputDT));
    Serial.print("    Counter: ");
    Serial.println(counter);
  }

  previousStateCLK = currentStateCLK;

  while (buttonState != 1) {
    buttonState = digitalRead(button);

    if (buttonState == 1) {
      Serial.println("Button pressed!!");
      delay(100);
    }
  }

}