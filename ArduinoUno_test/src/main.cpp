#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Stepper.h>
#include <NewPing.h>

#define trigPin 10
#define echoPin 13
#define maxDist 400

NewPing sonar(trigPin, echoPin, maxDist);

DHT_Unified dht(12, DHT11);

uint32_t delayMS;

void setup() {
  Serial.begin(9600);

  // dht.begin();
  // sensor_t sensor;
  // dht.temperature().getSensor(&sensor);
  // dht.humidity().getSensor(&sensor);

  // delayMS = 2000;
}

void loop() {

  // delay(delayMS);

  // int photoValue = analogRead(A0);
  // Serial.print(F("Photoresistor value: "));
  // Serial.print(photoValue);
  // Serial.print("  /   ");

  // sensors_event_t event;
  // dht.temperature().getEvent(&event);
  // Serial.print(F("Temperatura: "));
  // Serial.print(event.temperature);
  // Serial.print(F("ºC  /   Humidity: "));
  // dht.humidity().getEvent(&event);
  // Serial.print(event.relative_humidity);
  // Serial.println(F("%"));

  float duration = sonar.ping_median(5);

  // float distance = sonar.ping_cm();
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
