#ifndef RENDER_STACK_H
#define RENDER_STACK_H

#include <cstdlib>
#include <vector>

// TODO
// Implement a priority system like player tag, enviroment tag, etc.
class RenderBuffer {
private:
  std::vector<std::vector<char> > pixels;
  int layer;

public:
  size_t width;
  size_t height;

  RenderBuffer();
  explicit RenderBuffer(char value);
  RenderBuffer(size_t width, size_t height);
  RenderBuffer(size_t width, size_t height, char value);
  RenderBuffer(size_t width, size_t height, char value, int layer);

  char getPixel(size_t x, size_t y);
  void setPixel(size_t x, size_t y, char value);
  void clearPixel(size_t x, size_t y);
  void setAll(char value);
  void setLayer(int val);

  // Rendering
  void draw();
  void overlay(RenderBuffer r);

  // Movement
  void moveUp(size_t amount);
  void moveDown(size_t amount);
  void moveLeft(size_t amount);
  void moveRight(size_t amount);
  void transform(int x, int y);

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
