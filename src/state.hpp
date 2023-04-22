#ifndef STATE_HPP
#define STATE_HPP

#include "entity/entity.hpp"
#include "gfx/gfx.hpp"
#include "util/util.hpp"

class State {
private:
public:
  Renderer renderer;
  std::vector<GameObject*> game_objects;
  u64 tick_count;

  void init();
  void clear();
  void tick();
  void update();
  void render();
};

#endif // STATE_HPP
