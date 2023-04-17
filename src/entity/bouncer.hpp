#ifndef BOUNCER_H
#define BOUNCER_H

#include "game_object.hpp"

class Bouncer : public GameObject {
public:
  int vel_x;
  int vel_y;

  Bouncer();
  Bouncer(int width, int height);
  Bouncer(int width, int height, int layer);

  void tick();

};

#endif // BOUNCER_H
