#include "bouncer.hpp"

#include "../common.hpp"
#include <iostream>

Bouncer::Bouncer(int width, int height, int layer) {
  this->width = width;
  this->height = height;
  this->layer = layer;
  this->x = 1;
  this->y = 1;
  this->render_buffer = RenderBuffer(width, height, ' ', layer);
}

void Bouncer::tick() {
  // x collision
  if (x + width >= WIDTH) {
    vel_x = -vel_x;
  } if (x <= 1) {
    vel_x = abs(vel_x);
  }
  moveRight(vel_x);

  // y collision
  if (y + height >= HEIGHT - 2) {
    vel_y = -vel_y;
  } if (y <= 1) {
    vel_y = abs(vel_y);
  }
  moveDown(vel_y);
}
