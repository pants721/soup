#include <cstdlib>
#include <functional>
#include <unistd.h>

#include "gfx/render_buffer.hpp"
#include "gfx/renderer.hpp"
#include "state.hpp"
#include "common.h"

static State global_state;
State &state = global_state;

static void tick() {
  for (auto obj : state.objects) {
    obj.tick();
  }
}

static void update() {
  state.renderer.update();
}

static void render() {
  state.renderer.draw();
}

int main() {

  RenderBuffer thing(5, 5, ' ', 0);
  thing._x = 15;
  thing._y = 1;
  thing.drawCircle(3, 3, 2, '#');
  state.renderer.addRenderBuffer(std::ref(thing));

  RenderBuffer thing2(1, 5, ' ', 1);
  thing2._x = 25;
  thing2._y = 1;
  thing2.drawLine(1, 1, 1, 5, '@');
  state.renderer.addRenderBuffer(std::ref(thing2));

  while (1) {
    // Clear terminal and render stack
    system("clear");
    state.renderer.clear();

    // Actual Game Events
    thing._moveLeft(1);
    thing2._moveLeft(1);

    // Actual rendering
    tick();
    update();
    render();

    // Renders at 25 frames per second
    usleep(40000);
  }
    }
