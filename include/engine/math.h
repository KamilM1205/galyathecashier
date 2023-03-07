#ifndef MATH_H_
#define MATH_H_

namespace Engine {

class Vector2 {
public:
  float x;
  float y;
  float x_gl;
  float y_gl;

  Vector2();
  Vector2(float x, float y);
  Vector2(Vector2 &vec);
  void convert_coordinates(float min_x, float min_y, float max_x, float max_y);
};

class Rect {
public:
  float x;
  float y;
  float w;
  float h;
  float x_gl;
  float y_gl;
  float w_gl;
  float h_gl;

  Rect();
  Rect(float x, float y, float w, float h);
  Rect(Vector2 pos, Vector2 size);
  Rect(Rect &rect);
  void convert_coordinates(float min_x, float min_y, float max_x, float max_y);
};

} // namespace Engine

#endif // !MATH_H_
