#include "state.hpp"

#define object_for(objects, call)                                              \
  for (auto &obj : this->objects) {                                            \
    obj.call();                                                                \
  }

#define add_to_renderer(objects)                                               \
  for (auto &obj : this->objects) {                                            \
    this->renderer.addRenderBuffer(std::ref(obj.render_buffer));               \
  }

void State::init() {
  add_to_renderer(game_objects);
  add_to_renderer(bouncer_objects);
}

void State::tick() {
  object_for(game_objects, tick);
  object_for(bouncer_objects, tick);
}

void State::update() {
  object_for(game_objects, update);
  object_for(bouncer_objects, update);
  this->renderer.update();
}

void State::render() { this->renderer.draw(); }
