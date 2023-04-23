#ifndef ENTITY_PLAYER_HPP
#define ENTITY_PLAYER_HPP

#include "entity/game_object.hpp"
#include "input/input.hpp"
#include "util/util.hpp"

class Player : public GameObject {
private:
public:
  InputBus* input_bus;

  Player(InputBus* input_bus);
  Player(InputBus* input_bus, int x, int y, int width, int height, int layer, int vel_x, int vel_y);

  bool isCollision(int x_change, int y_change);
  void tick(u64 tick_count) override;
};

#endif // ENTITY_PLAYER_HPP
