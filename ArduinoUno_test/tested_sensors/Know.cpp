// for button soder 10k resistor

#include <Arduino.h>

#define inputCLK 4
#define inputDT 5
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

  if (currentStateCLK != previousStateCLK) {
    if (digitalRead(inputDT) != currentStateCLK) {
      counter --;
      digitalWrite(ledCW, LOW);
      digitalWrite(ledCCW, HIGH);
    }
    else {
      counter ++;
      digitalWrite(ledCW, HIGH);
      digitalWrite(ledCCW, LOW);
    }
    Serial.print("Button: ");
    Serial.print(button);
    Serial.print("    CLK: ");
    Serial.print(digitalRead(inputCLK));
    Serial.print("    DT: ");
    Serial.print(digitalRead(inputDT));
    Serial.print("    Counter: ");
    Serial.println(counter);
  }

  previousStateCLK = currentStateCLK;

}
