#include "game_object.hpp"
#include "../common.h"

GameObject::GameObject() : x(0), y(0), width(1), height(1), layer(0), render_buffer(1, 1, ' ', 0) {}
GameObject::GameObject(int width, int height) : x(0), y(0), width(width), height(height), render_buffer(width, height, ' ', 0) {}
GameObject::GameObject(int width, int height, int layer) : x(0), y(0), width(width), height(height), render_buffer(width, height, ' ', layer) {}

void GameObject::update() {
  this->tick();

  // Render update
  this->render_buffer._x = this->x;
  this->render_buffer._y = this->y;
  this->render_buffer.width = this->width;
  this->render_buffer.height = this->height;
}

void GameObject::tick() {}

// Movement
void GameObject::moveUp(int amount) {
  this->render_buffer._moveUp(amount);
}

void GameObject::moveDown(int amount) {
  this->render_buffer._moveDown(amount);
}

void GameObject::moveLeft(int amount) {
  this->render_buffer._moveLeft(amount);
}

void GameObject::moveRight(int amount) {
  this->render_buffer._moveRight(amount);
}

