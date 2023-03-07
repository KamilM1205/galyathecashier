#ifndef APP_H_
#define APP_H_

#include "engine/context.h"
#include "engine/events.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <string>

namespace Engine {

class App {
protected:
  std::string title;
  int width;
  int height;
  bool fullscreen;
  bool should_quit;
  GLFWwindow *window;
  Context *ctx;

public:
  static void error_callback(int error, const char *description);
  static void keyboard_callback(GLFWwindow *window, int key, int scancode,
                                int action, int mods);
  static void mouse_callback(GLFWwindow *window, int button, int action,
                             int mods);
  static void mouse_motion_callback(GLFWwindow *window, double x, double y);
  static void scroll_callback(GLFWwindow *window, double x_offset,
                              double y_offset);

  App();
  void run();
  ~App();

  virtual void init(){};
  virtual void update(float dt){};
  virtual void draw(Context *ctx){};
  virtual void handle_mouse(MouseEvent *event){};
  virtual void handle_keyboard(KeyEvent *event){};
  virtual void handle_joystick(){};
};

} // namespace Engine

#endif // !APP_H_
