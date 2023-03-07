#include "game/game.h"
int main() {
  GameApp *game = new GameApp();
  game->run();
  delete game;
}
