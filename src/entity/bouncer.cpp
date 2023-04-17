#include "bouncer.hpp"

#include "../common.h"
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
  // if (x >= WIDTH) {
  //   this->vel_x = -this->vel_x;
  // } if (x <= 1) {
  //   this->vel_x = abs(vel_x);
  // }

  // std::cout << vel_x;
  // moveRight(vel_x);
  moveRight(1);
}
