#include <Arduino.h>

#define DTPin 21
#define CLKPin 19
#define button 22

int OldStateCLK;
int NewStateCLK;
int counter = 0;

void setup() {

    Serial.begin(9600);

    pinMode(DTPin, INPUT);
    pinMode(CLKPin, INPUT);
    pinMode(button, INPUT);

    OldStateCLK = digitalRead(CLKPin);
}

void loop() {

    
    NewStateCLK = digitalRead(CLKPin);
    
    if (NewStateCLK != OldStateCLK) {
        
        // Serial.print("New CLK: ");
        // Serial.print(NewStateCLK);
        // Serial.print("  old CLK: ");
        // Serial.print(OldStateCLK);
        // Serial.print("  DT:");
        // Serial.print(digitalRead(DTPin));

        if (digitalRead(DTPin) == NewStateCLK) {
            counter ++;
        }
        else {
            counter --;
        }

        Serial.println(counter);
    }

    OldStateCLK = NewStateCLK;

    if (digitalRead(button) != 1) {
        while (digitalRead(button) == 0) {}
        delay(10);
    }
}