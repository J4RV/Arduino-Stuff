#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 21
#define NUMLEDS 60
#define BRIGHTNESS 128

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMLEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show();
}

void loop() {
  strip.clear();
  
  MaxAmperageTest(50); 
  //StrangerThings(" BEHIND YOU ", 1200);

  //Punto de fuego rebotando.
  ResetIVs(0.9);
  for (int i = 0; i <= 25; i++) {
    Gravity(255, 220, 255, 0.95, 0.85, 0);
  }

  //Coche fantastico arcoiris.
  for (int i = 0; i <= 3; i++) {
    KnightRider(30, 0.5, 5, 50);
  }

  //Coche fantastico.
  KnightRiderSetHue(0);
  for (int i = 0; i <= 6; i++) {
    KnightRider(30, 0, 0, 6);
  }
}



