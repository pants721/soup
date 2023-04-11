#ifndef RENDERER_H
#define RENDERER_H

#include <functional>
#include <stddef.h>
#include <vector>
#include "render_buffer.hpp"

class Renderer {
private:
  std::vector<std::reference_wrapper<RenderBuffer> > stack;

public:
  RenderBuffer frame;
  size_t width;
  size_t height;

  Renderer(size_t width, size_t height);
  Renderer(size_t width, size_t height, std::vector<std::reference_wrapper<RenderBuffer> > stack);

  void addRenderBuffer(RenderBuffer &r);

  void clear();
  void render();
  void draw();
};

#endif // RENDERER_H