#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define PIXELCOUNT 12

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXELCOUNT, PIN, NEO_GRB + NEO_KHZ800);

struct color {
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

void setup() {
  strip.begin();
  strip.show();
}

struct color yellowish = { 140, 60, 0 };
struct color white = { 190, 150, 90 };
struct color blue = { 0, 0, 190 };

void loop() {
  colorFade(1000, blue, white);
  colorFade(1000, white, yellowish);
}

void colorFade(uint16_t delayTime, color color1, color color2) {
  int up;
  for(int down = 100; down > 0; down--) {
    up = 100 - down;

    uint8_t red   = ((color1.r * down) + (color2.r * up)) / 200;
    uint8_t green = ((color1.g * down) + (color2.g * up)) / 200;
    uint8_t blue  = ((color1.b * down) + (color2.b * up)) / 200;

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
