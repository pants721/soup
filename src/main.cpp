#include <chrono>
#include <cstdlib>
#include <functional>
#include <thread>
#include <unistd.h>

#include "gfx/render_buffer.hpp"
#include "gfx/renderer.hpp"
#include "entity/game_object.hpp"
#include "state.hpp"
#include "common.hpp"

int main() {

  // Start
  State state = State();

  GameObject thing = GameObject(1, 1, 0);
  thing.loadSprite("sprites/default.txt");
  state.game_objects.push_back(thing);

  state.init();

while (1) {
    // Clear terminal and render stack
    system("clear");
    state.renderer.clear();

    // Actual Game Events
    state.renderer.frame.drawRect(0, 0, WIDTH, HEIGHT, '#');
    state.renderer.frame.drawLine(0, 0, WIDTH - 1, HEIGHT - 1, 'A');

    // Actual rendering
    state.tick();
    state.update();
    state.render();

    // FPS
    // std::this_thread::sleep_for(std::chrono::milliseconds(40)); // 25 FPS
    // std::this_thread::sleep_for(std::chrono::milliseconds(100/3)); // 30 FPS
    std::this_thread::sleep_for(std::chrono::milliseconds(100/6)); // 60 FPS
  }
}
