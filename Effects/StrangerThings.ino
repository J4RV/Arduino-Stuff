#include <Adafruit_NeoPixel.h>

String letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZÑ";
int spacing = 2;
void StrangerThings(String phrase, int wait){
  for (int i = 0; i < phrase.length(); i++){
    int pos = letters.indexOf(phrase.charAt(i));
    strip.setPixelColor(pos * spacing, GetRandomColor());
    strip.show();
    delay(wait);
    strip.setPixelColor(pos * spacing, 0);
  }
}
