#ifndef RENDER_STACK_H
#define RENDER_STACK_H

#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

// TODO
// Implement a priority system like player tag, enviroment tag, etc.
class RenderBuffer {

private:
  std::vector<std::vector<char> > pixels;

public:
  size_t width;
  size_t height;

  RenderBuffer();
  explicit RenderBuffer(char value);
  RenderBuffer(size_t width, size_t height);
  RenderBuffer(size_t width, size_t height, char value);

  char getPixel(size_t x, size_t y);
  void setPixel(size_t x, size_t y, char value);
  void clearPixel(size_t x, size_t y);
  void setAll(char value);

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

};

#endif // RENDER_STACK_H
