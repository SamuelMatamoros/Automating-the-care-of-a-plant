#include <Arduino.h>

#define DTPin 21
#define CLKPin 19
#define button 23

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

        if (digitalRead(DTPin) != NewStateCLK) {
            counter ++;
        }
        else {
            counter --;
        }
        
        Serial.print("  Counter:");
        Serial.println(counter);
    }

    OldStateCLK = NewStateCLK;

}