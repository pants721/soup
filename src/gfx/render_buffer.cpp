#include "render_buffer.hpp"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <cmath>

// Constructors
RenderBuffer::RenderBuffer() : pixels(), width(), height() { }

RenderBuffer::RenderBuffer(char value) {
  this->setAll(value);
}

RenderBuffer::RenderBuffer(size_t width, size_t height) : width(width), height(height), _x(1), _y(1) { }

RenderBuffer::RenderBuffer(size_t width, size_t height, char value) {
  this->pixels.assign(height, std::vector<char>(width, value));
  this->width = width;
  this->height = height;
  this->layer = 0;
  this->_x = 1;
  this->_y = 1;
}

RenderBuffer::RenderBuffer(size_t width, size_t height, char value, int layer) {
  this->pixels.assign(height, std::vector<char>(width, value));
  this->width = width;
  this->height = height;
  this->layer = layer;
  this->_x = 1;
  this->_y = 1;
}

RenderBuffer::RenderBuffer(size_t width, size_t height, char value, int layer, int x, int y) {
  this->pixels.assign(height, std::vector<char>(width, value));
  this->width = width;
  this->height = height;
  this->layer = layer;
  this->_x = x;
  this->_y = x;
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
  width -= 1;
  height -= 1;
  // Top line
  this->drawLine(x, y, x + width, y, value);
  // Left line
  this->drawLine(x, y, x, y + height, value);
  // Right line
  this->drawLine(x + width, y, x + width, y + height, value);
  // Bottom line
  this->drawLine(x, y + height, x + width, y + height, value);
}

// Source: https://www.geeksforgeeks.org/bresenhams-circle-drawing-algorithm/
void RenderBuffer::drawCircle(int centerX, int centerY, int radius, char value) {
  int x = 0, y = radius;
  int d = 3 - 2 * radius;
  this->drawCircleEightPoints(centerX, centerY, x, y, value);
  while (y >= x) {
    // for each pixel we will
    // draw all eight pixels

    x++;

    // check for decision parameter
    // and correspondingly
    // update d, x, y
    if (d > 0) {
      y--;
      d = d + 4 * (x - y) + 10;
    } else
      d = d + 4 * x + 6;
    this->drawCircleEightPoints(centerX, centerY, x, y, value);
  }
}

void RenderBuffer::drawCircleEightPoints(int centerX, int centerY, int x, int y, char value) {
  this->setPixel(centerX + x, centerY + y, value);
  this->setPixel(centerX - x, centerY + y, value);
  this->setPixel(centerX + x, centerY - y, value);
  this->setPixel(centerX - x, centerY - y, value);
  this->setPixel(centerX + y, centerY + x, value);
  this->setPixel(centerX - y, centerY + x, value);
  this->setPixel(centerX + y, centerY - x, value);
  this->setPixel(centerX - y, centerY - x, value);
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
        size_t render_x = j + r._x - 1;
        size_t render_y = i + r._y + 1;
        this->pixels[render_y][render_x] = r.pixels[i][j];
      }
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
