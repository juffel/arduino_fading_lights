#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define PIXELCOUNT 12

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXELCOUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

// uint32_t yellowish = strip.Color(140, 60, 0);
// uint32_t white = strip.Color(140, 100, 60);

void loop() {
  colorFade(1000, 140, 60, 0, 190, 150, 90);
  colorFade(1000, 190, 150, 90, 140, 60, 0);
}

void colorFade(uint16_t delayTime, uint8_t r1, uint8_t g1, uint8_t b1, uint8_t r2, uint8_t g2, uint8_t b2) {
  int up;
  for(int down = 100; down > 0; down--) {
    up = 100 - down;

    uint8_t red   = ((r1 * down) + (r2 * up)) / 200;
    uint8_t green = ((g1 * down) + (g2 * up)) / 200;
    uint8_t blue  = ((b1 * down) + (b2 * up)) / 200;

    setAll(strip.Color(red, green, blue));
    delay(delayTime);
  }

}

void setAll(uint32_t color) {
  for(int i = 0; i < PIXELCOUNT; i++) {
    setPixel(i, color);
  }
  strip.show();
}

void setPixel(uint8_t index, uint32_t color) {
  strip.setPixelColor(index, color);
}

void setPixel(uint8_t index, uint32_t r, uint32_t g, uint32_t b) {
  strip.setPixelColor(index, strip.Color(r, g, b));
}
