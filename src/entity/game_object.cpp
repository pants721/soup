#include "game_object.hpp"
#include "../common.h"

GameObject::GameObject() : x(1), y(1), width(1), height(1), layer(0), render_buffer(1, 1, ' ', 0) {}
GameObject::GameObject(int width, int height) : x(1), y(1), width(width), height(height), render_buffer(width, height, ' ', 0) {}
GameObject::GameObject(int width, int height, int layer) : x(1), y(1), width(width), height(height), render_buffer(width, height, ' ', layer) {}

void GameObject::update() {
  // Render update
  this->render_buffer._x = this->x;
  this->render_buffer._y = this->y;
  this->render_buffer.width = this->width;
  this->render_buffer.height = this->height;
}

void GameObject::tick() {}

// Movement
void GameObject::moveUp(int amount) {
  this->y -= amount;
}

void GameObject::moveDown(int amount) {
  this->y += amount;
}

void GameObject::moveLeft(int amount) {
  this->x -= amount;
}

void GameObject::moveRight(int amount) {
  this->x += amount;
}

