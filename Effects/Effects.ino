#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 6
#define NUMLEDS 60

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMLEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(128);
  strip.show();
}

void loop() {
  for(int i = 0; i<=6; i++){
    Gravity();    
  }
  for(int i = 0; i<=5; i++){
    KnightRider(20,30);
  }
}



