#include "common.hpp"
#include "state.hpp"

#include "entity/entity.hpp"
#include "gfx/gfx.hpp"
#include "util/util.hpp"

int main(int argc, char** argv) {
  State state = State();

  Bouncer thing = Bouncer();
  thing.loadSprite("sprites/bouncer.txt");
  thing.vel_x = 1;
  thing.vel_y = 1;
  state.game_objects.push_back(&thing);

  GameObject thing2 = GameObject();
  thing2.loadSprite("sprites/default.txt");
  thing2.x = 15;
  thing2.y = 15;
  state.game_objects.push_back(&thing2);

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
