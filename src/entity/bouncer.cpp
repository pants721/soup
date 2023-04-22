#include "entity/bouncer.hpp"

#include "entity/game_object.hpp"
#include "util/util.hpp"

Bouncer::Bouncer() : GameObject(), vel_x(1), vel_y(1) {}
Bouncer::Bouncer(int x, int y, int width, int height, int layer, int vel_x,
                 int vel_y)
    : GameObject(x, y, width, height, layer), vel_x(vel_x), vel_y(vel_y) {}

void Bouncer::tick(u64 tick_count) {
  x += vel_x;
  y += vel_y;
}

