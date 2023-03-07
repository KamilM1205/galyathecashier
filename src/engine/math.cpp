#include "engine/math.h"
#include <cstdio>

float convertToIdentityRange(float value, float min, float max) {
  return ((value - min) * 2 / (max - min)) + -1.0;
}

Engine::Vector2::Vector2() {
  x = 0.0;
  y = 0.0;
}

Engine::Vector2::Vector2(float x, float y) {
  this->x = x;
  this->y = y;
}

Engine::Vector2::Vector2(Engine::Vector2 &vec) {
  x = vec.x;
  y = vec.y;
}

void Engine::Vector2::convert_coordinates(float min_x, float min_y, float max_x,
                                          float max_y) {
  x_gl = convertToIdentityRange(x, min_x, max_x);
  y_gl = convertToIdentityRange(y, min_y, max_y);
  printf("%f - %f; %f - %f.", x, x_gl, y, y_gl);
}

Engine::Rect::Rect() {
  x = 0.0;
  y = 0.0;
  w = 1.0;
  h = 1.0;
}

Engine::Rect::Rect(float x, float y, float w, float h) {
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
}

Engine::Rect::Rect(Engine::Vector2 pos, Engine::Vector2 size) {
  x = pos.x;
  y = pos.y;
  w = size.x;
  h = size.y;
}

Engine::Rect::Rect(Engine::Rect &rect) {
  x = rect.x;
  y = rect.y;
  w = rect.w;
  h = rect.h;
}

void Engine::Rect::convert_coordinates(float min_x, float min_y, float max_x,
                                       float max_y) {
  x_gl = convertToIdentityRange(x, min_x, max_y);
  y_gl = convertToIdentityRange(y, min_y, max_y);
  w_gl = convertToIdentityRange(w, min_x, max_x);
  h_gl = convertToIdentityRange(h, min_y, max_y);
}
