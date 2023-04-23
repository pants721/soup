#ifndef ENTITY_GAME_OBJECT_HPP
#define ENTITY_GAME_OBJECT_HPP

#include "gfx/render_buffer.hpp"
#include "util/util.hpp"

class GameObject {
public:
  int x;
  int y;
  int width;
  int height;
  int layer;
  RenderBuffer render_buffer;

  GameObject();
  GameObject(int x, int y, int width, int height, int layer);

  bool isCollision(int change_x, int change_y);

  void loadSprite(std::string path);

  void update();
  virtual void tick(u64 tick_count);

  // Movement
  void moveUp(int amount);
  void moveDown(int amount);
  void moveLeft(int amount);
  void moveRight(int amount);
};

#endif // ENTITY_GAME_OBJECT_HPP
