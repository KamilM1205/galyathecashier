#ifndef COLOR_H_
#define COLOR_H_

#include <cstdint>

namespace Engine {

class Color {
public:
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;

  float r_gl;
  float g_gl;
  float b_gl;
  float a_gl;

  Color(uint8_t r, uint8_t g, uint8_t b);
  Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
  // Hex color #aarrggbb #rrggbb
  Color(const char *color);

  void convertToGl();
};

} // namespace Engine

#endif // !COLOR_H_
