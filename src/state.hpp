#ifndef STATE_HPP
#define STATE_HPP

#include <vector>
#include "gfx/renderer.hpp"
#include "entity/game_object.hpp"
#include "util/types.hpp"

class State {
private:
public:
  Renderer renderer;
  std::vector<GameObject> game_objects;
  u64 tick_count;

  void init();
  void tick();
  void update();
  void render();
};

#endif // STATE_HPP
