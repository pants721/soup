#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <type_traits>
#include "render_buffer.hpp"

// Constructors
RenderBuffer::RenderBuffer() : pixels(), width(), height() { }

RenderBuffer::RenderBuffer(char value) {
  this->setAll(value);
}

RenderBuffer::RenderBuffer(size_t width, size_t height) : width(width), height(height) { }

RenderBuffer::RenderBuffer(size_t width, size_t height, char value) {
  this->width = width;
  this->height = height;
  this->setAll(value);
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
  memset(pixels, value, sizeof(pixels));
}

// Rendering
void RenderBuffer::draw() {
  for (int row = 0; row < this->height; row++) {
    for (int col = 0; col < this->width; col++) {
      std::cout << pixels[row][col];
    }
    std::cout << std::endl;
  }
}

void RenderBuffer::overlay(RenderBuffer r) {
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++) {
      // Merge the two images by overwriting pixels of image1 with pixels of
      // image2
      if (r.pixels[i][j] != ' ') {
        this->pixels[i][j] = r.pixels[i][j];
      }
    }
  }
}

// Debug
void RenderBuffer::display() {
  for (int a = 0; a < this->height; a++) {
    for (int b = 0; b < this->width; b++) {
      std::cout << pixels[a][b] << " ";
    }
    std::cout << std::endl;
  }
}
