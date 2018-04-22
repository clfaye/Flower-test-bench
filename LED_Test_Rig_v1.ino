#include "FastLED.h"

const int numStrips = 1;
const int ledsPerStrip = 100;
const int numLEDs = numStrips * ledsPerStrip;
const int dataPin = 2;

const int relay1Pin = 33;
const int relay2Pin = 34;
const int relay3Pin = 35;
const int relay4Pin = 36;



int hue = 0;

int petalLast = 0;

CRGB leds[numLEDs];

void setup()
{
  pinMode(relay1Pin, OUTPUT);
  digitalWrite(relay1Pin, HIGH);  // Relay off

  pinMode(relay2Pin, OUTPUT);
  digitalWrite(relay2Pin, HIGH);  // Relay off

  pinMode(relay3Pin, OUTPUT);
  digitalWrite(relay3Pin, HIGH);  // Relay off

  pinMode(relay4Pin, OUTPUT);
  digitalWrite(relay4Pin, HIGH);  // Relay off






  digitalWrite(relay1Pin, LOW);  // Relay on
  delay(1000);
  digitalWrite(relay1Pin, HIGH);  // Relay off

  digitalWrite(relay2Pin, LOW);  // Relay on
  delay(1000);
  digitalWrite(relay2Pin, HIGH);  // Relay off

  digitalWrite(relay3Pin, LOW);  // Relay on
  delay(1000);
  digitalWrite(relay3Pin, HIGH);  // Relay off

  digitalWrite(relay4Pin, LOW);  // Relay on
  delay(1000);
  digitalWrite(relay4Pin, HIGH);  // Relay off


  // WS2811_PORTDC - pins 2,14,7,8,6,20,21,5,15,22,23,9,10,13,11,12 <-- 16 pins, no soldering onto pads on the back!
  //  LEDS.addLeds<WS2811_PORTDC, numStrips, GRB>(leds, ledsPerStrip);
  LEDS.addLeds<WS2811, dataPin, GRB>(leds, numLEDs);
  LEDS.setBrightness(200);
}


void loop()
{
  for (int petal = 0; petal < 5; petal++)
  {
petalLast = petal - 1;
if (petalLast < 0)
{
  petalLast = 4;
}
    for (int i = 0; i < (numLEDs / 5) ; i++)
    {
      leds[(petal * numLEDs / 5) + i] = CHSV(hue, 255, 255);
      leds[(petalLast * numLEDs / 5) + i] = CHSV(0, 0, 0);

    }
    FastLED.show();
    delay(150);
    hue = hue + 10;
    if (hue > 255)
    {
      hue = 0;
    }
  }

}

