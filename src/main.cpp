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
#define HEIGHT 35

// TODO
// - Keyboard input
int main() {
  static Renderer renderer(WIDTH, HEIGHT);

  RenderBuffer test1(3, 3, ' ', 2);
  test1.x = 3;
  test1.y = 1;
  test1.setPixel(1, 1, '#');
  test1.setPixel(2, 1, '#');
  test1.setPixel(3, 1, '#');

  test1.setPixel(1, 2, '#');
  test1.setPixel(3, 2, '#');

  test1.setPixel(1, 3, '#');
  test1.setPixel(2, 3, '#');
  test1.setPixel(3, 3, '#');
  renderer.addRenderBuffer(std::ref(test1));

  RenderBuffer test2(3, 3, ' ', 0);
  test2.x = 1;
  test2.y = 1;
  test2.setPixel(1, 1, 'A');
  test2.setPixel(2, 1, 'A');
  test2.setPixel(3, 1, 'A');

  test2.setPixel(1, 2, 'A');
  test2.setPixel(3, 2, 'A');

  test2.setPixel(1, 3, 'A');
  test2.setPixel(2, 3, 'A');
  test2.setPixel(3, 3, 'A');
  renderer.addRenderBuffer(std::ref(test2));

  while (1) {
    // Clear terminal and render stack
    system("clear");
    renderer.clear();

    // Actual Game Events
    // test1.moveUp(1);
    // test2.moveDown(1);
    // test2.moveRight(1);

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
