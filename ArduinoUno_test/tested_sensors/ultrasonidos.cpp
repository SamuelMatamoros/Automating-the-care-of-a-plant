#include <Arduino.h>
#include <NewPing.h>

#define trigPin 10
#define echoPin 13
#define maxDist 400

NewPing sonar(trigPin, echoPin, maxDist);

void setup() {
    Serial.begin(9600);
}

void loop() {
    float duration = sonar.ping_median(5);
    float distance = (duration / 2) * 0.0343;

    Serial.print("Distance = ");
    if (distance >= 400 || distance <= 2) {
        Serial.println("Out of range");
    }
    else {
        Serial.print(distance);
        Serial.println(" cm");
        delay(500);
    }
    delay(500);
}
