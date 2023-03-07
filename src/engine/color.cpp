#include "engine/color.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string.h>

Engine::Color::Color(uint8_t r, uint8_t g, uint8_t b) {
  this->r = r;
  this->g = g;
  this->b = b;
  a = 255;
  convertToGl();
}

Engine::Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
  convertToGl();
}

// Hex color
// TODO works wrong (every start program other colors)
Engine::Color::Color(const char *color) {
  uint8_t r, g, b, a;
  char *p;
  char buff[2];

  if (strlen(color) == 7) {
    strncpy(buff, color + 1, 2);
    r = strtoul(buff, &p, 16);

    if (p == 0) {
      printf("Not a color");
      return;
    }

    strncpy(buff, color + 3, 2);
    g = strtoul(buff, &p, 16);

    if (p == 0) {
      printf("Not a color");
      return;
    }

    strncpy(buff, color + 5, 2);
    b = strtoul(buff, &p, 16);

    if (p == 0) {
      printf("Not a color");
      return;
    }

    a = 255;
  } else if (strlen(color) == 9) {
    strncpy(buff, color + 1, 2);
    a = strtoul(buff, &p, 16);

    if (p == 0) {
      printf("Not a color");
      return;
    }

    strncpy(buff, color + 3, 2);
    r = strtoul(buff, &p, 16);

    if (p == 0) {
      printf("Not a color");
      return;
    }

    strncpy(buff, color + 5, 2);
    g = strtoul(buff, &p, 16);

    if (p == 0) {
      printf("Not a color");
      return;
    }

    strncpy(buff, color + 7, 2);
    b = strtoul(buff, &p, 16);

    if (p == 0) {
      printf("Not a color");
      return;
    }
  }

  printf("%d %d %d", r, g, b);
  convertToGl();
}

void Engine::Color::convertToGl() {
  r_gl = (float)r / 255;
  g_gl = (float)g / 255;
  b_gl = (float)b / 255;
  a_gl = (float)a / 255;
}
