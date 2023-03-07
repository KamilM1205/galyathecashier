#ifndef CONTEXT_H_
#define CONTEXT_H_

#include "engine/color.h"
#include "engine/math.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <cstdint>

namespace Engine {

class Context {
private:
  Rect screen_coord;
  int32_t width, height;
  GLFWwindow *window;

public:
  void update();
  void set_screen_coordinate(float x, float y, float w, float h);
  int32_t get_width();
  int32_t get_height();
  void clear_screen(Color color);
  void draw_triangle(Color color, Vector2 v1, Vector2 v2, Vector2 v3);
  void draw_rect(Color color, Vector2 pos, Vector2 size);
  void draw_rect(Color color, Rect rect);
  void draw_filled_rect(Color color, Vector2 pos, Vector2 size);
  void draw_filled_rect(Color color, Rect rect);

  Context(GLFWwindow *window);
  ~Context();
};

} // namespace Engine

#endif // !CONTEXT_H_
