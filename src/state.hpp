#ifndef STATE_H
#define STATE_H

#include "gfx/renderer.hpp"
#include "entity/game_object.hpp"
#include <vector>

class State {
private:
public:
  Renderer renderer;
  std::vector<GameObject> objects;

  void init();
  void tick();
  void update();
  void render();
};

#endif // STATE_H
