#include "engine/app.h"
#include "engine/context.h"
#include "engine/events.h"
#include "engine/glad/gl.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <cstddef>
#include <cstdio>
#include <cstdlib>

Engine::KeyEvent *keyboard_event;
Engine::MouseEvent *mouse_motion;
Engine::MouseEvent *mouse_event;

void Engine::App::keyboard_callback(GLFWwindow *window, int key, int scancode,
                                    int action, int mods) {
  keyboard_event = create_key_event(key, scancode, action, mods);
}

void Engine::App::mouse_callback(GLFWwindow *window, int button, int action,
                                 int mods) {
  double x, y;
  glfwGetCursorPos(window, &x, &y);
  mouse_event = create_mouse_click_event(button, action, mods, x, y);
};

void Engine::App::mouse_motion_callback(GLFWwindow *window, double x,
                                        double y) {
  double posx, posy;
  glfwGetCursorPos(window, &posx, &posy);
  mouse_motion = create_mouse_motion_event(x, y);
}

void Engine::App::error_callback(int error, const char *description) {
  // TODO use log instead printf
  printf("GLFW Error: %d %s\n", error, description);
}

Engine::App::App() {
  glfwSetErrorCallback(error_callback);
  if (!glfwInit())
    exit(EXIT_FAILURE);

  title = "GameApp";
  width = 640;
  height = 480;
  fullscreen = false;
  should_quit = false;

  init();
}

void Engine::App::run() {
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwSetKeyCallback(window, keyboard_callback);
  glfwSetCursorPosCallback(window, mouse_motion_callback);
  glfwSetMouseButtonCallback(window, mouse_callback);

  glfwMakeContextCurrent(window);
  gladLoadGL(glfwGetProcAddress);
  glfwSwapInterval(1);

  ctx = new Context(window);

  while (!glfwWindowShouldClose(window) && !should_quit) {
    if (keyboard_event != NULL) {
      handle_keyboard(keyboard_event);
      keyboard_event = NULL;
    } else if (mouse_event != NULL) {
      handle_mouse(mouse_event);
      mouse_event = NULL;
    } else if (mouse_motion != NULL) {
      handle_mouse(mouse_motion);
      mouse_motion = NULL;
    }

    update(0.0);

    ctx->update();
    glViewport(0, 0, ctx->get_width(), ctx->get_height());
    draw(ctx);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

Engine::App::~App() {
  glfwDestroyWindow(window);
  glfwTerminate();
}
