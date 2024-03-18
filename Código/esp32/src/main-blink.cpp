#include <Arduino.h>

int pwmPin = 12;
int pwmChan = 0;
int pwmRes = 8;
int pwmFreq = 1000;


void setup() {
  Serial.begin(9600);
  // ledcSetup(pwmChan, pwmFreq, pwmRes);
  // ledcAttachPin(pwmPin, pwmChan);
  // pinMode(2, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {

  // for (int i = 0; i < 255; i++) {
  //   ledcWrite(pwmChan, i);
  //   delay(10);
  // }
  // ledcWrite(pwmChan, 0);
  // delay(1000);

  Serial.println(touchRead(13));

  if (touchRead(13) < 40) {
    digitalWrite(2, HIGH);
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(2, LOW);
    digitalWrite(12, LOW);
  }
  delay(100);
  
}