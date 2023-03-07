#ifndef _EVENTS_H_
#define _EVENTS_H_

namespace Engine {

struct KeyEvent {
  int key;
  int scancode;
  int action;
  int mods;
};

struct MouseEvent {
  int key;
  int action;
  int mods;
  double x;
  double y;
  double x_offset;
  double y_offset;
};

KeyEvent *create_key_event(int key, int scancode, int action, int mods);

MouseEvent *create_mouse_click_event(int key, int action, int mods, double x,
                                     double y);
MouseEvent *create_mouse_scroll_event(double x_offset, double y_offset,
                                      double x, double y);
MouseEvent *create_mouse_motion_event(double x, double y);

} // namespace Engine

#endif // !_EVENTS_H_
