#include "render_buffer.hpp"

#include <__algorithm/fill.h>
#include <cstdlib>
#include <iostream>
#include <vector>

// Constructors
RenderBuffer::RenderBuffer() : pixels(), width(), height() { }

RenderBuffer::RenderBuffer(char value) {
  this->setAll(value);
}

RenderBuffer::RenderBuffer(size_t width, size_t height) : width(width), height(height) { }

RenderBuffer::RenderBuffer(size_t width, size_t height, char value) {
  this->pixels.assign(height, std::vector<char>(width, value));
  this->width = width;
  this->height = height;
}

/// INDEX BASE 1
// Pixel manipulation
char RenderBuffer::getPixel(size_t x, size_t y) {
  return this->pixels[y-1][x-1];
}

void RenderBuffer::setPixel(size_t x, size_t y, char value) {
  this->pixels[y-1][x-1] = value;
}

void RenderBuffer::clearPixel(size_t x, size_t y) {
  this->pixels[y-1][x-1] = ' ';
}

void RenderBuffer::setAll(char value) {
  for (auto& row : this->pixels) {
    std::fill(row.begin(), row.end(), value);
  }
}

// Rendering
void RenderBuffer::draw() {
  for (size_t row = 0; row < this->height; row++) {
    for (size_t col = 0; col < this->width; col++) {
      std::cout << pixels[row][col];
    }
    std::cout << std::endl;
  }
}

void RenderBuffer::overlay(RenderBuffer r) {
  for (size_t i = 0; i < this->height; i++) {
    for (size_t j = 0; j < this->width; j++) {
      // Merge the two images by overwriting pixels of image1 with pixels of
      // image2
      if (r.pixels[i][j] != ' ') {
        this->pixels[i][j] = r.pixels[i][j];
      }
    }
  }
}

// Transform
void RenderBuffer::moveUp(size_t amount) {
  if (this->pixels.size() == 0) return;
  for (size_t i = 0; i < amount; i++) {
    this->pixels.push_back(this->pixels[0]);
    this->pixels.erase(this->pixels.begin());
    this->pixels.back().assign(this->height, ' ');
  }
}

void RenderBuffer::moveDown(size_t amount) {
  if (this->pixels.size() == 0) return;
  for (size_t i = 0; i < amount; i++) {
    this->pixels.insert(this->pixels.begin(), this->pixels.back());
    this->pixels.pop_back();
    this->pixels.front().assign(this->height, ' ');
  }
}

void RenderBuffer::moveLeft(size_t amount) {
  if (this->pixels.size() == 0) return;
  for (size_t i = 0; i < amount; i++) {
    for (size_t j = 0; j < this->height; j++) {
      this->pixels[j].push_back(' ');
      this->pixels[j].erase(this->pixels[j].begin());
    }
  }
}

void RenderBuffer::moveRight(size_t amount) {
  if (this->pixels.size() == 0) return;
  for (size_t i = 0; i < amount; i++) {
    for (size_t j = 0; j < this->height; j++) {
      this->pixels[j].insert(this->pixels[j].begin(), ' ');
      this->pixels[j].pop_back();
    }
  }
}

// Debug
void RenderBuffer::display() {
  for (size_t a = 0; a < this->height; a++) {
    for (size_t b = 0; b < this->width; b++) {
      std::cout << pixels[a][b] << " ";
    }
    std::cout << std::endl;
  }
}
