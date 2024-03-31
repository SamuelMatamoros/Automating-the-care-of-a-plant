#include <WiFi.h>
#include "time.h"

#define ledPin 2

const char* ssid       = "Test1";
const char* password   = "0012345678";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 0;

void printLocalTime()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    // Serial.println("Failed to obtain time");
    return;
  }
  // Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");

//   Serial.println(&timeinfo, "%H:%M:%S");
}

void setup()
{
  // Serial.begin(9600);

  pinMode(ledPin,OUTPUT);
  
  //connect to WiFi
  // Serial.printf("Connecting to %s ", ssid);
  WiFi.mode(WIFI_STA);
  WiFi.enableSTA(true);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      digitalWrite(ledPin,HIGH);
      delay(500);
      digitalWrite(ledPin,LOW);
      delay(500);
      // Serial.print(".");
  }
  // Serial.println(" CONNECTED");
  digitalWrite(ledPin,HIGH);
  
  //init and get the time
  // configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  // printLocalTime();

  //disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop()
{
  delay(1000);
  // printLocalTime();
}