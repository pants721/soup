#include <cstdlib>
#include <__functional/reference_wrapper.h>

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

  RenderBuffer test1(WIDTH, HEIGHT, ' ');
  test1.setPixel(21, 21, '#');
  test1.setPixel(22, 21, '#');
  test1.setPixel(23, 21, '#');

  test1.setPixel(21, 22, '#');
  test1.setPixel(23, 22, '#');

  test1.setPixel(21, 23, '#');
  test1.setPixel(22, 23, '#');
  test1.setPixel(23, 23, '#');
  renderer.addRenderBuffer(std::ref(test1));

  RenderBuffer test2(WIDTH, HEIGHT, ' ');
  test2.setPixel(31, 31, '#');
  test2.setPixel(32, 31, '#');
  test2.setPixel(33, 31, '#');

  test2.setPixel(31, 32, '#');
  test2.setPixel(33, 32, '#');

  test2.setPixel(31, 33, '#');
  test2.setPixel(32, 33, '#');
  test2.setPixel(33, 33, '#');
  renderer.addRenderBuffer(std::ref(test2));

  while (1) {
    // Clear terminal and render stack
    system("clear");
    renderer.clear();

    // Actual Game Events
    test1.moveUp(1);
    test2.moveDown(1);
    test2.moveRight(1);

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
