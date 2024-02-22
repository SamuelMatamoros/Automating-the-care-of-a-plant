#include <Arduino.h>

#define SenPin 34

int value;
int valueCrude;
int highest = 0;
int lowest = 1000;
int SenvAL;

void setup() {

    Serial.begin(9600);

    pinMode(SenPin, INPUT);

    delay(5000);
}

void loop() {

    // Lowest aprox. 0
    // Highest aprox. 2700

    valueCrude = analogRead(SenPin);
    Serial.print("Value: ");
    Serial.print(valueCrude);

    if (value > 1000) {
        if (value > highest) {
            highest = value;
        }
    }
    else {
        if (value < lowest) {
            lowest = value;
        }
    }

    Serial.print("  Highest:");
    Serial.print(highest);
    Serial.print("  Lowest:");
    Serial.print(lowest);
    int mapped = map(value, lowest, highest, 100, 0);
    Serial.print("  Mapped:");
    Serial.print(mapped);
    Serial.println("%");
    
    delay(500);
}

