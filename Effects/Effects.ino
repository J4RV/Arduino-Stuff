#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 6
#define NUMLEDS 60

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMLEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(255);
  strip.show();
}

void loop() {
  strip.clear();
  StrangerThings(" BEHIND YOU ", 1200);
  //Punto de fuego rebotando.
  for(int i = 0; i<=5; i++){
    Gravity(255,220,255,0.95,0.8,0);    
  }
  
  //Coche fantastico arcoiris.
  for(int i = 0; i<=3; i++){
    KnightRider(50, 0.25, 4, 20);
  }
  
  //Coche fantastico.
  KnightRiderSetHue(0);
  for(int i = 0; i<=6; i++){
    KnightRider(30, 0, 0, 6);
  }
}



