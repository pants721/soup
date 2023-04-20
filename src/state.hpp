#ifndef STATE_H
#define STATE_H

#include <vector>
#include "gfx/renderer.hpp"
#include "entity/game_object.hpp"

class State {
private:
public:
  Renderer renderer;
  std::vector<GameObject> game_objects;
  uint64_t tick_count;

  void init();
  void tick();
  void update();
  void render();
};

#endif // STATE_H
