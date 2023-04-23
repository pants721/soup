#include "common.hpp"
#include "state.hpp"

#include "entity/entity.hpp"
#include "gfx/gfx.hpp"
#include "util/util.hpp"

int main() {
  SET_RAW_MODE(); // I could set you to raw mode

  State state = State();

  Bouncer bouncer;
  bouncer.loadSprite("sprites/bouncer.txt");
  state.game_objects.push_back(&bouncer);

  Player player(&state.input_bus);
  player.loadSprite("sprites/player.txt");
  player.x = 15;
  player.y = 15;
  state.game_objects.push_back(&player);

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
