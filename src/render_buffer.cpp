#include "render_buffer.hpp"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

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
  this->layer = 0;
}

RenderBuffer::RenderBuffer(size_t width, size_t height, char value, int layer) {
  this->pixels.assign(height, std::vector<char>(width, value));
  this->width = width;
  this->height = height;
  this->layer = layer;
}

/// INDEX BASE 1
// Pixel manipulation
char RenderBuffer::getPixel(size_t x_coord, size_t y_coord) {
  return this->pixels[y_coord-1][x_coord-1];
}

void RenderBuffer::setPixel(size_t x_coord, size_t y_coord, char value) {
  this->pixels[y_coord-1][x_coord-1] = value;
}

void RenderBuffer::clearPixel(size_t x_coord, size_t y_coord) {
  this->pixels[y_coord-1][x_coord-1] = ' ';
}

void RenderBuffer::setAll(char value) {
  for (auto& row : this->pixels) {
    std::fill(row.begin(), row.end(), value);
  }
}

void RenderBuffer::setLayer(int val) {
  this->layer = val;
}

void RenderBuffer::drawLineLow(int x1, int y1, int x2, int y2, char value) {
  int dx = x2 - x1;
  int dy = y2 - y1;
  int yi = 1;

  if (dy < 0) {
    yi = -1;
    dy = -dy;
  }
  int D = (2 * dy) - dx;
  int y = y1;

  for (int x = x1; x <= x2; x++) {
    this->setPixel(x, y, value);
    if (D > 0) {
      y = y + yi;
      D = D + (2 * (dy - dx));
    } else {
      D = D + 2 * dy;
    }
  }
}

void RenderBuffer::drawLineHigh(int x1, int y1, int x2, int y2, char value) {
  int dx = x2 - x1;
  int dy = y2 - y1;
  int xi = 1;

  if (dx < 0) {
    xi = -1;
    dx = -dx;
  }
  int D = (2 * dx) - dy;
  int x = x1;

  for (int y = y1; y <= y2; y++) {
    this->setPixel(x, y, value);
    if (D > 0) {
      x = x + xi;
      D = D + (2 * (dx - dy));
    } else {
      D = D + 2 * dx;
    }
  }
}


void RenderBuffer::drawLine(int x1, int y1, int x2, int y2, char value) {
  using namespace std;
  if (x1 == x2) {
    // Vertical line
    for (int i = min(y1, y2); i <= max(y1, y2); i++) {
      this->setPixel(x1, i, value);
    }
  } else if (y1 == y2) {
    // Horizontal line
    for (int i = min(x1, x2); i <= max(x1, x2); i++) {
      this->setPixel(i, y1, value);
    }
  } else {
    // Diagonal line
    // Source: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm

    if (abs(y2 - y1) < abs(x2 - x1)) {
      if (x1 > x2) {
        this->drawLineLow(x2, y2, x1, y1, value);
      } else {
        this->drawLineLow(x1, y1, x2, y2, value);
      }
    } else {
      if (y1 > y2) {
        this->drawLineHigh(x2, y2, x1, y1, value);
      } else {
        this->drawLineHigh(x1, y1, x2, y2, value);
      }
    }
  }
}

void RenderBuffer::drawRect(int x, int y, int width, int height, char value) {
  // Top line
  this->drawLine(x, y, x + width, y, value);
  // Left line
  this->drawLine(x, y, x, y + height, value);
  // Right line
  this->drawLine(x + width, y, x + width, y + height, value);
  // Bottom line
  this->drawLine(x, y + height, x + width, y + height, value);
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

// Smaller buffer should be passed as r
void RenderBuffer::overlay(RenderBuffer r) {
  for (size_t i = 0; i < r.height; i++) {
    for (size_t j = 0; j < r.width; j++) {
      // Merge the two images by overwriting pixels of image1 with pixels of
      // image2
      if (r.pixels[i][j] != ' ') {
        size_t render_x = j + r.x - 1;
        size_t render_y = i + r.y + 1;
        this->pixels[render_y][render_x] = r.pixels[i][j];
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
