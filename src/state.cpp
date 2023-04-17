#include "state.hpp"

void State::init() {
  for (auto &obj : this->objects) {
    this->renderer.addRenderBuffer(std::ref(obj.render_buffer));
  }
}

void State::tick() {
  for (auto &obj : this->objects) {
    obj.tick();
  }
}

void State::update() {
  for (auto &obj : this->objects) {
    obj.update();
  }
  this->renderer.update();
}

void State::render() { this->renderer.draw(); }
