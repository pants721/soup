#include <cstdlib>
#include <unistd.h>
#include <ncurses.h>
#include <iostream>
#include <sys/ioctl.h>

#include "render_buffer.hpp"
#include "common.hpp"
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

  while (1) {
    // Clear terminal and render stack
    system("clear");
    renderer.clear();

    // stuff
    test1.moveUp(5);
    // test1.moveLeft(5);
    // test1.moveDown(10);
    // test1.moveRight(5);

    // Actual rendering
    renderer.render();
    renderer.draw();

    // Renders at 25 frames per second
    // usleep(40000);
    usleep(400000);
  }
}










// RenderBuffer test1(WIDTH, HEIGHT, ' ');
// test1.setPixel(i + 1, 1, '#');
// test1.setPixel(i + 2, 1, '#');
// test1.setPixel(i + 3, 1, '#');

// test1.setPixel(i + 1, 2, '#');
// test1.setPixel(i + 3, 2, '#');

// test1.setPixel(i + 1, 3, '#');
// test1.setPixel(i + 2, 3, '#');
// test1.setPixel(i + 3, 3, '#');



// RenderBuffer test1(WIDTH, HEIGHT, ' ');
// test1.setPixel(count, 12, '#');
// ++count;
// renderer.addRenderBuffer(test1);
