#include "entity/player.hpp"

#include "entity/game_object.hpp"
#include "util/util.hpp"
#include "common.hpp"

Player::Player(InputBus* input_bus) : GameObject(), input_bus(input_bus) {}

Player::Player(InputBus* input_bus, int x, int y, int width, int height,
               int layer, int vel_x, int vel_y)
    : GameObject(x, y, width, height, layer), input_bus(input_bus) {}



void Player::tick(u64 tick_count) {
  if (!input_bus->keys.empty()) {
    switch (input_bus->keys[0]) {
    case 'w':
      if (!isCollision(0, -1)) {
        moveUp(1);
      }
      break;
    case 'a':
      if (!isCollision(-1, 0)) {
        moveLeft(1);
      }
      break;
    case 's':
      if (!isCollision(0, 1)) {
        moveDown(1);
      }
      break;
    case 'd':
      if (!isCollision(1, 0)) {
        moveRight(1);
      }
      break;
    }
  }
}
