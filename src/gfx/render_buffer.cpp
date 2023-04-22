#include "render_buffer.hpp"

#include "util/util.hpp"

// Constructors
RenderBuffer::RenderBuffer() : pixels(), width(), height() { }

RenderBuffer::RenderBuffer(char value) {
  setAll(value);
}

RenderBuffer::RenderBuffer(usize width, usize height)
  : layer(0), width(width), height(height), _x(0), _y(0) {}

RenderBuffer::RenderBuffer(usize width, usize height, char value)
    : layer(0), width(width), height(height), _x(0), _y(0) {
  pixels.assign(height, std::vector<char>(width, value));
}

RenderBuffer::RenderBuffer(usize width, usize height, char value, int layer)
    : layer(layer), width(width), height(height), _x(0), _y(0) {
  pixels.assign(height, std::vector<char>(width, value));
}

RenderBuffer::RenderBuffer(usize width, usize height, char value, int layer,
                           int x, int y)
    : layer(layer), width(width), height(height), _x(x), _y(y) {
  pixels.assign(height, std::vector<char>(width, value));
}

// Pixel manipulation
char RenderBuffer::getPixel(usize x_coord, usize y_coord) {
  return pixels[y_coord][x_coord];
}

void RenderBuffer::setPixel(usize x_coord, usize y_coord, char value) {
  pixels[y_coord][x_coord] = value;
}

void RenderBuffer::clearPixel(usize x_coord, usize y_coord) {
  pixels[y_coord][x_coord] = ' ';
}

void RenderBuffer::setAll(char value) {
  for (auto& row : pixels) {
    std::fill(row.begin(), row.end(), value);
  }
}

void RenderBuffer::setLayer(int val) {
  layer = val;
}

void RenderBuffer::fromFile(std::string path) {
  std::ifstream file(path);

  // Find length and width
  std::string line;

  int file_width = 0;
  int file_height = 0;

  // Find longest line
  while (std::getline(file, line)) {
    int line_length = line.length();
    if (line_length > file_width) {
      file_width = line_length;
    }
    file_height++;
  }

  width = file_width;
  height = file_height;

  int count = 0;
  file.clear();
  file.seekg(0, std::ios::beg);
  while (std::getline(file, line)) {
    // Fill in right whitespace
    if ((int)line.length() < file_width) {
      for (int i = 0; i <= file_width - (int)line.length(); i++) {
        line += " ";
      }
    }
    std::vector<char> v(line.begin(), line.end());
    pixels[count] = v;
    count++;
  }

}

void RenderBuffer::writeText(int x, int y, std::string text) {
  for (int i = 0; i < (int)text.length(); i++) {
    setPixel(x + i, y, text[i]);
  }
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
    setPixel(x, y, value);
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
    setPixel(x, y, value);
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
      setPixel(x1, i, value);
    }
  } else if (y1 == y2) {
    // Horizontal line
    for (int i = min(x1, x2); i <= max(x1, x2); i++) {
      setPixel(i, y1, value);
    }
  } else {
    // Diagonal line
    // Source: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm

    if (abs(y2 - y1) < abs(x2 - x1)) {
      if (x1 > x2) {
        drawLineLow(x2, y2, x1, y1, value);
      } else {
        drawLineLow(x1, y1, x2, y2, value);
      }
    } else {
      if (y1 > y2) {
        drawLineHigh(x2, y2, x1, y1, value);
      } else {
        drawLineHigh(x1, y1, x2, y2, value);
      }
    }
  }
}

void RenderBuffer::drawRect(int x, int y, int width, int height, char value) {
  width -= 1;
  height -= 1;
  // Top line
  drawLine(x, y, x + width, y, value);
  // Left line
  drawLine(x, y, x, y + height, value);
  // Right line
  drawLine(x + width, y, x + width, y + height, value);
  // Bottom line
  drawLine(x, y + height, x + width, y + height, value);
}

// Source: https://www.geeksforgeeks.org/bresenhams-circle-drawing-algorithm/
void RenderBuffer::drawCircle(int centerX, int centerY, int radius, char value) {
  int x = 0, y = radius;
  int d = 3 - 2 * radius;
  drawCircleEightPoints(centerX, centerY, x, y, value);
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
    drawCircleEightPoints(centerX, centerY, x, y, value);
  }
}

void RenderBuffer::drawCircleEightPoints(int centerX, int centerY, int x, int y, char value) {
  setPixel(centerX + x, centerY + y, value);
  setPixel(centerX - x, centerY + y, value);
  setPixel(centerX + x, centerY - y, value);
  setPixel(centerX - x, centerY - y, value);
  setPixel(centerX + y, centerY + x, value);
  setPixel(centerX - y, centerY + x, value);
  setPixel(centerX + y, centerY - x, value);
  setPixel(centerX - y, centerY - x, value);
}

// Rendering
void RenderBuffer::draw() {
  for (usize row = 0; row < height; row++) {
    for (usize col = 0; col < width; col++) {
      std::cout << pixels[row][col];
    }
    std::cout << std::endl;
  }
}

// Smaller buffer should be passed as r
void RenderBuffer::overlay(RenderBuffer r) {
  for (usize i = 0; i < r.height; i++) {
    for (usize j = 0; j < r.width; j++) {
      // Merge the two images by overwriting pixels of image1 with pixels of
      // image2
      if (r.pixels[i][j] != ' ') {
        usize render_x = j + r._x;
        usize render_y = i + r._y;
        pixels[render_y][render_x] = r.pixels[i][j];
      }
    }
  }
}

// Debug
void RenderBuffer::display() {
  for (usize a = 0; a < height; a++) {
    for (usize b = 0; b < width; b++) {
      std::cout << pixels[a][b] << " ";
    }
    std::cout << std::endl;
  }
}
