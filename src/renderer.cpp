#include <cstdlib>
#include <functional>
#include <vector>

#include "render_buffer.hpp"
#include "renderer.hpp"

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
  for (auto buffer : this->stack) {
    this->frame.overlay(buffer);
  }
}

void Renderer::draw() { this->frame.draw(); }
