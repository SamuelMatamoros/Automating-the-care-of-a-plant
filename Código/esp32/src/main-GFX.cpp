#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

#define TFT_CS   15 // Chip select line for TFT display
#define TFT_RST  4 // Reset line for TFT display
#define TFT_DC   2 // Data/command line for TFT display

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup() {
 tft.init(240, 320); // Initialize the display with the screen dimensions
 tft.invertDisplay(1);
 tft.setRotation(2);
 tft.fillScreen(ST77XX_BLACK); // Fill the screen with black
 tft.setTextColor(ST77XX_WHITE); // Set the text color to white
 tft.setTextSize(3); // Set the text size
 tft.setCursor(0, 0); // Set the cursor position
 tft.println("Hello, World!"); // Print a message
}

void loop() {
 // Your
}