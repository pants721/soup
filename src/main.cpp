#include <cstdlib>
#include <functional>
#include <unistd.h>

#include "gfx/render_buffer.hpp"
#include "gfx/renderer.hpp"
#include "entity/game_object.hpp"
#include "entity/bouncer.hpp"
#include "state.hpp"
#include "common.hpp"

int main() {

  // Start
  State state = State();

  Bouncer thing = Bouncer(3, 3, 0);
  thing.render_buffer.fromFile("test.txt");
  thing.render_buffer.display();
  thing.vel_x = 1;
  thing.vel_y = 1;
  state.bouncer_objects.push_back(thing);

  state.init();

 while (1) {
    // Clear terminal and render stack
    system("clear");
    state.renderer.clear();

    // Actual Game Events

    // Actual rendering
    state.tick();
    state.update();
    state.render();

    // Renders at 25 frames per second
    usleep(40000);
  }
}
