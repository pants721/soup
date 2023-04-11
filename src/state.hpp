#ifndef STATE_H
#define STATE_H

#include "gfx/renderer.hpp"
#include "engine/game_object.hpp"
#include <vector>

class State {
private:
public:
  Renderer renderer;
  std::vector<GameObject> objects;

  ~State();
  State();
};

#endif // STATE_H
