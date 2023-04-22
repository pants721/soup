#ifndef GFX_RENDER_BUFFER_HPP
#define GFX_RENDER_BUFFER_HPP

#include "util/util.hpp"

class RenderBuffer {
private:
  std::vector<std::vector<char> > pixels;
  int layer;
  void drawLineLow(int x1, int y1, int x2, int y2, char value);
  void drawLineHigh(int x1, int y1, int x2, int y2, char value);

public:
  usize width;
  usize height;

  int _x;
  int _y;

  RenderBuffer();
  explicit RenderBuffer(char value);
  RenderBuffer(usize width, usize height);
  RenderBuffer(usize width, usize height, char value);
  RenderBuffer(usize width, usize height, char value, int layer);
  RenderBuffer(usize width, usize height, char value, int layer, int x, int y);

  char getPixel(usize x_coord, usize y_coord);
  void setPixel(usize x_coord, usize y_coord, char value);
  void clearPixel(usize x_coord, usize y_coord);
  void setAll(char value);
  void setLayer(int val);

  void fromFile(std::string path);

  // Drawing
  void writeText(int x, int y, std::string text);
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
    return (layer < render_buffer.layer);
  }

  bool operator > (const RenderBuffer &render_buffer) const {
    return (layer > render_buffer.layer);
  }

};

#endif // GFX_RENDER_BUFFER_HPP
