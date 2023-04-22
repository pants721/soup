#include <unistd.h>

#include "common.hpp"
#include "state.hpp"

#include "entity/entity.hpp"
#include "gfx/gfx.hpp"
#include "util/util.hpp"

int main(int argc, char** argv) {
  State state = State();

  GameObject thing = GameObject(1, 1, 0);
  thing.loadSprite("sprites/default.txt");
  state.game_objects.push_back(thing);

  state.init();

  while (1) {
    // Clear terminal and render stack
    system("clear");
    state.renderer.clear();


    // Actual rendering
    state.tick();
    state.update();
    state.render();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000/FPS)); // FPS
  }
}
