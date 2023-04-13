#ifndef RENDER_STACK_H
#define RENDER_STACK_H

#include <cstddef>
#include <cstdlib>
#include <vector>

class RenderBuffer {
private:
  std::vector<std::vector<char> > pixels;
  int layer;
  void drawLineLow(int x1, int y1, int x2, int y2, char value);
  void drawLineHigh(int x1, int y1, int x2, int y2, char value);

public:
  size_t width;
  size_t height;

  int _x;
  int _y;

  RenderBuffer();
  explicit RenderBuffer(char value);
  RenderBuffer(size_t width, size_t height);
  RenderBuffer(size_t width, size_t height, char value);
  RenderBuffer(size_t width, size_t height, char value, int layer);
  RenderBuffer(size_t width, size_t height, char value, int layer, int x, int y);

  char getPixel(size_t x_coord, size_t y_coord);
  void setPixel(size_t x_coord, size_t y_coord, char value);
  void clearPixel(size_t x_coord, size_t y_coord);
  void setAll(char value);
  void setLayer(int val);

  // Drawing
  void drawLine(int x1, int y1, int x2, int y2, char value);
  void drawRect(int x, int y, int width, int height, char value);
  void drawCircle(int centerX, int centerY, int radius, char value);
  void drawCircleEightPoints(int centerX, int centerY, int x, int y, char value);

  // Rendering
  void draw();
  void overlay(RenderBuffer r);

  // Debug
  void display();
  void debug();

  // Comp
  // Primarily for rendering layers
  // If on the same layer, the most recently added one will render on top
  bool operator < (const RenderBuffer &render_buffer) const {
    return (this->layer < render_buffer.layer);
  }

  bool operator > (const RenderBuffer &render_buffer) const {
    return (this->layer > render_buffer.layer);
  }

};

#endif // RENDER_STACK_H
