#include <cstdlib>
#include <functional>
#include <unistd.h>

#include "gfx/render_buffer.hpp"
#include "gfx/renderer.hpp"
#include "entity/game_object.hpp"
#include "entity/bouncer.hpp"
#include "state.hpp"
#include "common.h"

int main() {

  State state = State();

  Bouncer thing = Bouncer(10, 10, 0);
  thing.render_buffer.drawLine(1, 1, 10, 10, 'A');
  thing.render_buffer.display();
  thing.vel_x = 1;
  state.objects.push_back(thing);

  state.init();

 // while (1) {
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
 // }
}
