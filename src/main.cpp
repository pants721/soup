#include <cstdlib>
#include <unistd.h>
#include <ncurses.h>
#include <iostream>
#include <sys/ioctl.h>

#include "render_buffer.hpp"
#include "common.hpp"
#include "renderer.hpp"

#define WIDTH 50
#define HEIGHT 25

int main(int argc, char *argv[]) {

  static Renderer renderer(WIDTH, HEIGHT);

  RenderBuffer test1(WIDTH, HEIGHT, ' ');
  test1.setPixel(1, 1, '#');
  test1.setPixel(2, 1, '#');
  test1.setPixel(3, 1, '#');

  test1.setPixel(1, 2, '#');
  test1.setPixel(3, 2, '#');

  test1.setPixel(1, 3, '#');
  test1.setPixel(2, 3, '#');
  test1.setPixel(3, 3, '#');
  renderer.addRenderBuffer(test1);

  while (1) {
    // Clear terminal and render stack
    system("clear");
    renderer.clear();

    // stuff
    test1.moveRight(1);

    // Actual rendering
    renderer.render();
    renderer.draw();

    // Renders at 25 frames per second
    usleep(40000);
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
