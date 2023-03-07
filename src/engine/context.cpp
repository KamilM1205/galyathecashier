#include "engine/context.h"
#include "engine/glad/gl.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <cstdint>

void Engine::Context::update() { glfwGetWindowSize(window, &width, &height); }

void Engine::Context::set_screen_coordinate(float x, float y, float w,
                                            float h) {
  screen_coord.x = x;
  screen_coord.y = y;
  screen_coord.w = w;
  screen_coord.h = h;
}

int32_t Engine::Context::get_width() { return width; }

int32_t Engine::Context::get_height() { return height; }

void Engine::Context::clear_screen(Color color) {
  glClearColor(color.r_gl, color.g_gl, color.b_gl, color.a_gl);
  glClear(GL_COLOR_BUFFER_BIT);
}

void Engine::Context::draw_triangle(Color color, Vector2 v1, Vector2 v2,
                                    Vector2 v3) {
  v1.convert_coordinates(screen_coord.x, screen_coord.y, screen_coord.w,
                         screen_coord.h);
  v2.convert_coordinates(screen_coord.x, screen_coord.y, screen_coord.w,
                         screen_coord.h);
  v3.convert_coordinates(screen_coord.x, screen_coord.y, screen_coord.w,
                         screen_coord.h);

  color.convertToGl();
  glColor4f(color.r_gl, color.g_gl, color.b_gl, color.a_gl);
  glBegin(GL_TRIANGLES);

  glVertex2f(v1.x_gl, v1.y_gl);
  glVertex2f(v2.x_gl, v2.y_gl);
  glVertex2f(v3.x_gl, v3.y_gl);

  glEnd();
}

Engine::Context::Context(GLFWwindow *window) { this->window = window; }

Engine::Context::~Context() {}
