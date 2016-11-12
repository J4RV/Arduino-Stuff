#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

float hue = 0;

void KnightRider(int trail, uint8_t wait){
  for(int i=0; i<NUMLEDS*2; i++){
    Trail(i, trail);
    strip.show();
    delay(wait);
    hue += 0.25f;
  }
}

void Trail(int startPos, int trail){
  for(int j=0; j<=trail; j++) {
    uint32_t color;
    int pos;
    float alpha;
    //Vamos desde 0 hasta el doble del nº de leds
    pos = (startPos + j)%(NUMLEDS*2);
    alpha = (j*1.0f)/(trail);

    color = Wheel(hue + j*2, alpha);    

    if(pos>=NUMLEDS){
      //si pos es mayor al nº de leds, vamos hacia la izq.
      pos = (NUMLEDS - pos%NUMLEDS) -1;
    }

    strip.setPixelColor(pos, color);
  }
}


