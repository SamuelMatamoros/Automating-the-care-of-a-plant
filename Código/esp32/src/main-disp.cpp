#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h> 

TFT_eSPI tft = TFT_eSPI();

void setup() 
{
  tft.init();
  tft.invertDisplay(1);
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
