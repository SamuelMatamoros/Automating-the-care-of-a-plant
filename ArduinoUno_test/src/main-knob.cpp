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
  // pinMode(button, INPUT);
  pinMode(ledCW, OUTPUT);
  pinMode(ledCCW, OUTPUT);

  previousStateCLK = digitalRead(inputCLK);
  Serial.println("------------KNOB TEST------------");
  Serial.print("CLK: ");
  Serial.print(digitalRead(inputCLK));
  Serial.print("    DT: ");
  Serial.print(digitalRead(inputDT));
  Serial.print("    Current: ");
  Serial.print(currentStateCLK);
  Serial.print("    Previous: ");
  Serial.println(previousStateCLK);

}

void loop() {

  currentStateCLK = digitalRead(inputCLK);
  

  if (currentStateCLK != previousStateCLK) {
    Serial.print("CLK: ");
    Serial.print(digitalRead(inputCLK));
    Serial.print("    DT: ");
    Serial.print(digitalRead(inputDT));
    Serial.print("    Current: ");
    Serial.print(currentStateCLK);
    Serial.print("    Previous: ");
    Serial.println(previousStateCLK);

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
    // Serial.print("Button: ");
    // Serial.print(button);
    Serial.print("CLK: ");
    Serial.print(digitalRead(inputCLK));
    Serial.print("    DT: ");
    Serial.print(digitalRead(inputDT));
    Serial.print("    Counter: ");
    Serial.println(counter);
  }

  previousStateCLK = currentStateCLK;

}
