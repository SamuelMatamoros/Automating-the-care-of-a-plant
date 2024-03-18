#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>

int pwmPin = 2;
int pwmChannel = 0;
int pwmRes = 8;
int pwdFrequency = 1000;
int dt = 5;
int k = 10;

TFT_eSPI tft = TFT_eSPI();

void setup() 
{

  ledcSetup(pwmChannel, pwdFrequency, pwmRes);
  ledcAttachPin(pwmPin, pwmChannel);

  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(6);
  tft.setCursor(80, 100);
  tft.println("MA-z");

  for (int k = 0; k < 5; k++){

    for (int i = 0; i < 255; i++){
      ledcWrite(pwmChannel, i);
      delay(dt);
    }
    for (int j = 255; j >= 0; j--){
      ledcWrite(pwmChannel, j);
      delay(dt);
    }
    delay(100);
  }

  delay(3000);
  tft.fillScreen(TFT_BLACK);
  ledcWrite(pwmChannel, 255);
}

void loop() 
{

  tft.fillScreen(tft.color565(255,0,0));
  delay(3000);
  tft.fillScreen(TFT_GREEN);
  delay(3000);
  tft.fillScreen(TFT_BLUE);
  delay(3000);

}
