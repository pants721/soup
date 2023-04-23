#include "common.hpp"
#include "state.hpp"

#include "entity/entity.hpp"
#include "gfx/gfx.hpp"
#include "util/util.hpp"

int main() {
  SET_RAW_MODE(); // I could set you to raw mode

  State state = State();

  Player thing2(&state.input_bus);
  thing2.loadSprite("sprites/default.txt");
  thing2.x = 15;
  thing2.y = 15;
  state.game_objects.push_back(&thing2);

  state.init();

  bool exit = false;
  while (!exit) {

    state.clear(); // Clear the terminal and renderer stack

    // Actual rendering
    state.tick();
    state.update();
    state.render();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000/FPS)); // FPS
  }

  RESTORE_MODE();
}
