#include "gfx/renderer.hpp"

#include "util/util.hpp"
#include "gfx/render_buffer.hpp"
#include "common.hpp"

Renderer::Renderer() : frame(WIDTH, HEIGHT, ' ', 100), width(WIDTH), height(HEIGHT) {};
Renderer::Renderer(usize width, usize height) : frame(width, height, ' ', 100), width(width), height(height) {};

void Renderer::addRenderBuffer(RenderBuffer &r) {
  stack.push_back(r);
}

void Renderer::clear() {
  frame.setAll(' ');
}

void Renderer::update() {
  std::vector<RenderBuffer> buffers;

  // Known issue: Render buffers wont be derendered until they are completley
  // out of bounds on the right and left, which is desired, but on the top and
  // bottom, they will be derendered the moment any part of them goes out of
  // bounds
  // If render buffer goes out of bounds, remove from stack
  // Fucking spaghetti code jesus christ
  int max_width = (int)frame.width;
  int max_height = (int)frame.height;

  // This line just finds the position of render buffer that exceeds bounds
  // Good luck if someone else tries maintaining this
  auto it = std::find_if(stack.begin(), stack.end(),
                         [&max_width, &max_height](
                             const std::reference_wrapper<RenderBuffer> obj) {
                           return obj.get()._x >
                                      max_width || // Obj goes out the right
                                  obj.get()._x + (int)obj.get().width <
                                      0 || // Obj goes out the left
                                  obj.get()._y + (int)obj.get().height >
                                      max_height ||  // Obj goes out the bottom
                                  obj.get()._y < 0; // Obj goes out the top
                         });

  if (it != stack.end()) {
    stack.erase(it);
  }

  for (auto buffer : stack) {
    buffers.push_back(buffer.get());
  }

  std::sort(buffers.begin(), buffers.end());

  for (auto buffer : buffers) {
    frame.overlay(buffer);
  }
}

void Renderer::draw() { frame.draw(); }
