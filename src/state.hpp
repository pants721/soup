#ifndef STATE_H
#define STATE_H

#include <vector>
#include "gfx/renderer.hpp"
#include "entity/game_object.hpp"
#include "entity/bouncer.hpp"

class State {
private:
public:
  Renderer renderer;
  std::vector<GameObject> game_objects;
  std::vector<Bouncer> bouncer_objects;

  void init();
  void tick();
  void update();
  void render();
};

#endif // STATE_H
