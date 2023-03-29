#include "renderer.hpp"

#include <algorithm>
#include <vector>
#include "render_buffer.hpp"

Renderer::Renderer(size_t width, size_t height) {
  // NEED to initialize this with ' '
  frame = RenderBuffer(width, height, ' ');
  stack = std::vector<std::reference_wrapper<RenderBuffer> >();
}

void Renderer::addRenderBuffer(RenderBuffer &r) {
  this->stack.push_back(r);
}

void Renderer::clear() {
  this->frame.setAll(' ');
}

void Renderer::render() {
  std::vector<RenderBuffer> buffers;

  for (auto buffer : this->stack) {
    buffers.push_back(buffer.get());
  }

  std::sort(buffers.begin(), buffers.end());

  for (auto buffer : buffers) {
    this->frame.overlay(buffer);
  }
}

void Renderer::draw() { this->frame.draw(); }
