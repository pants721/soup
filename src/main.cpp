#include <cstdlib>
#include <functional>
#include <unistd.h>

#include "gfx/render_buffer.hpp"
#include "gfx/renderer.hpp"
#include "common.h"

int main() {
  static Renderer renderer(WIDTH, HEIGHT);

  RenderBuffer thing(5, 5, ' ', 0);
  thing._x = 15;
  thing._y = 1;
  thing.drawCircle(3, 3, 2, '#');
  renderer.addRenderBuffer(std::ref(thing));

  RenderBuffer thing2(1, 5, ' ', 1);
  thing2._x = 25;
  thing2._y = 1;
  thing2.drawLine(1, 1, 1, 5, '@');
  renderer.addRenderBuffer(std::ref(thing2));

  while (1) {
    // Clear terminal and render stack
    system("clear");
    renderer.clear();

    // Actual Game Events
    thing._moveLeft(1);
    thing2._moveLeft(1);

    // Actual rendering
    renderer.render();
    renderer.draw();

    // Renders at 25 frames per second
    #ifdef _WIN32
    // Windows
    Sleep(40);

    #else
    // Unix, Mac
    usleep(40000);

    #endif // _WIN32
  }
}
