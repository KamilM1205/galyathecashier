#ifndef GAME_H_
#define GAME_H_

#include "engine/app.h"
#include "engine/context.h"

class GameApp : public Engine::App {
public:
  void handle_keyboard(Engine::KeyEvent *event) override;
  void handle_joystick() override;
  void handle_mouse(Engine::MouseEvent *event) override;

  void init() override;
  void draw(Engine::Context *ctx) override;
  void update(float dt) override;
};

#endif // GAME_H_
