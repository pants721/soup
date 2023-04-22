#ifndef ENTITY_BOUNCER_HPP
#define ENTITY_BOUNCER_HPP

#include "entity/game_object.hpp"

class Bouncer : public GameObject {
public:
  int vel_x;
  int vel_y;

  Bouncer();
  Bouncer(int x, int y, int width, int height, int layer, int vel_x, int vel_y);

  void tick(u64 tick_count) override;
};

#endif // ENTITY_BOUNCER_HPP
