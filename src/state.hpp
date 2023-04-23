#ifndef STATE_HPP
#define STATE_HPP

#include "entity/entity.hpp"
#include "gfx/gfx.hpp"
#include "input/input.hpp"
#include "util/util.hpp"

class State {
private:
public:
  Renderer renderer;
  InputBus input_bus;
  std::vector<GameObject*> game_objects;
  u64 tick_count;

  void init();
  void clear();
  void tick();
  void update();
  void render();
};

#endif // STATE_HPP
