#include "game_object.hpp"
#include "../common.hpp"

GameObject::GameObject() : x(0), y(0), width(1), height(1), layer(0), render_buffer(1, 1, ' ', 0) {}
GameObject::GameObject(int width, int height) : x(0), y(0), width(width), height(height), render_buffer(width, height, ' ', 0) {}
GameObject::GameObject(int width, int height, int layer) : x(0), y(0), width(width), height(height), render_buffer(width, height, ' ', layer) {}

void GameObject::loadSprite(std::string path) {
  // We create the temp render buffer because it seg faults if you try to do the
  // commented out code and the game object width is smaller than the sprite
  // you're trying to load
  RenderBuffer temp(WIDTH, HEIGHT, ' ');
  temp.fromFile(path);
  width = temp.width;
  height = temp.height;
  render_buffer = temp;

  // render_buffer.fromFile(path);
  // width = render_buffer.width;
  // height = render_buffer.height;
}

void GameObject::update() {
  // Render update
  render_buffer._x = x;
  render_buffer._y = y;
  render_buffer.width = width;
  render_buffer.height = height;
}

void GameObject::tick(uint64_t tick_count) {
  moveRight(1);
}

// Movement
void GameObject::moveUp(int amount) {
  y -= amount;
}

void GameObject::moveDown(int amount) {
  y += amount;
}

void GameObject::moveLeft(int amount) {
  x -= amount;
}

void GameObject::moveRight(int amount) {
  x += amount;
}
