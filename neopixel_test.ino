#include <Arduino.h>
#include "FastLED.h" // Use Version 3.1.3
#define ESP8266_LED 5
#define NUM_LEDS 4 //Number of LEDs
#define DATA_PIN 4 //Default Data Pin for ledunia NEOPIXELs
CRGB leds[NUM_LEDS];

void setup()
{
    delay(2000);
      FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  pinMode(ESP8266_LED, OUTPUT);
  Serial.begin(9600);
  Serial.print("<");

  for (int p = 0; p < 15; p++)
  {
    digitalWrite(p, HIGH);
    Serial.print(digitalRead(p));
  }
  Serial.println(">");
  Serial.print("<");
  delay(100);
  for (int l = 0; l < 15; l++)
  {
    digitalWrite(l, LOW);
    Serial.print(digitalRead(l));
  }
  Serial.println(">");

}

void loop()
{
// Move a single white led
  for (int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
    // Turn our current led on to white, then show the leds
    leds[whiteLed] = CRGB::White;

    // Show the leds (only one of which is set to white, from above)
    FastLED.show();

    // Wait a little bit
    delay(100);

    // Turn our current led back to black for the next loop around
    leds[whiteLed] = CRGB::Black;
  }

  digitalWrite(ESP8266_LED, HIGH);
  delay(500);
  digitalWrite(ESP8266_LED, LOW);
  delay(500);
}
