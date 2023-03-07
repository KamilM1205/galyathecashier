#include "game/game.h"
#include "engine/color.h"
#include "engine/context.h"
#include "engine/math.h"
#include <cstdio>

void GameApp::handle_keyboard(Engine::KeyEvent *event) {
  printf("%d", event->scancode);
}

void GameApp::handle_mouse(Engine::MouseEvent *event) {}

void GameApp::handle_joystick() {}

void GameApp::init() {}

void GameApp::update(float dt) {}

void GameApp::draw(Engine::Context *ctx) {
  ctx->set_screen_coordinate(0.0, 0.0, 640.0, 480.0);
  ctx->clear_screen(Engine::Color(0, 0, 100));
  ctx->draw_triangle(Engine::Color(255, 255, 255), Engine::Vector2(),
                     Engine::Vector2(0.0f, 480.0f),
                     Engine::Vector2(640.0f, 480.0f));
}
