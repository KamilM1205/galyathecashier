#include "engine/events.h"

Engine::KeyEvent *Engine::create_key_event(int key, int scancode, int action,
                                           int mods) {
  return new Engine::KeyEvent{key, scancode, action, mods};
}

Engine::MouseEvent *Engine::create_mouse_click_event(int key, int action,
                                                     int mods, double x,
                                                     double y) {
  return new Engine::MouseEvent{key, action, mods, x, y, 0.0, 0.0};
}

Engine::MouseEvent *Engine::create_mouse_scroll_event(double x_offset,
                                                      double y_offset, double x,
                                                      double y) {
  return new Engine::MouseEvent{0, 0, 0, x, y, x_offset, y_offset};
}

Engine::MouseEvent *Engine::create_mouse_motion_event(double x, double y) {
  return new Engine::MouseEvent{0, 0, 0, x, y, 0.0, 0.0};
}
