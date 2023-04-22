#ifndef GFX_RENDERER_HPP
#define GFX_RENDERER_HPP

#include "util/util.hpp"
#include "gfx/render_buffer.hpp"

class Renderer {
private:
  std::vector<std::reference_wrapper<RenderBuffer> > stack;

public:
  RenderBuffer frame;
  usize width;
  usize height;

  Renderer();
  Renderer(usize width, usize height);
  Renderer(usize width, usize height, std::vector<std::reference_wrapper<RenderBuffer> > stack);

  void addRenderBuffer(RenderBuffer &r);

  void clear();
  void update();
  void draw();
};

#endif // GFX_RENDERER_HPP
