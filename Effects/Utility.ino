uint32_t Wheel(byte WheelPos, float alpha) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color((255 - WheelPos * 3) * alpha , 0, WheelPos * 3 * alpha);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3 * alpha, (255 - WheelPos * 3) * alpha);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3* alpha,  (255 - WheelPos * 3)*alpha, 0);
}

void Smooth(float r, float g, float b){
  for(int i = 0; i<NUMLEDS; i++){
    SmoothPixel(i, r, g, b);
  }
}

void SmoothPixel(int i, float r, float g, float b){
  long lngRGB = strip.getPixelColor(i);
  
  uint8_t u8R = (uint8_t)((lngRGB >> 16) & 0xff),
  u8G = (uint8_t)((lngRGB >> 8) & 0xff),
  u8B = (uint8_t)(lngRGB & 0xff);
  
  strip.setPixelColor(i, u8R*r, u8G*g, u8B*b);
}
