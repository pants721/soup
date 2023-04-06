#include <cstdlib>
#include <functional>

// Windows
#ifdef _WIN32
#include <Windows.h>
#include <synchapi.h>
// Unix, Mac
#else
#include <unistd.h>
#endif // _WIN32

#include "render_buffer.hpp"
#include "renderer.hpp"

#define WIDTH 100
#define HEIGHT 25

int main() {
  static Renderer renderer(WIDTH, HEIGHT);

  RenderBuffer thing(5, 5, ' ', 0);
  thing.x = 15;
  thing.y = 1;
  thing.drawCircle(3, 3, 2, '#');
  renderer.addRenderBuffer(std::ref(thing));

  RenderBuffer thing2(1, 5, ' ', 1);
  thing2.x = 25;
  thing2.y = 1;
  thing2.drawLine(1, 1, 1, 5, '@');
  renderer.addRenderBuffer(std::ref(thing2));

  while (1) {
    // Clear terminal and render stack
    system("clear");
    renderer.clear();

    // Actual Game Events
    thing.moveLeft(1);
    thing2.moveLeft(1);

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
