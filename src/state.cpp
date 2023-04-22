#include "state.hpp"

#include "entity/entity.hpp"
#include "util/util.hpp"

void State::init() {
  for (auto &obj : game_objects)
    renderer.addRenderBuffer(std::ref(obj->render_buffer));
}

void State::clear() {
  system("clear");
  renderer.clear();
}

void State::tick() {
  for (auto &obj : game_objects)
    obj->tick(tick_count);
  tick_count++;
}

void State::update() {
  for (auto &obj : game_objects)
    obj->update();
  renderer.update();
}

void State::render() { renderer.draw(); }
