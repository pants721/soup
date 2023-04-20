#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "../gfx/render_buffer.hpp"
#include <string>

class GameObject {
private:
public:
  int x;
  int y;
  int width;
  int height;
  int layer;
  RenderBuffer render_buffer;

  GameObject();
  GameObject(int width, int height);
  GameObject(int width, int height, int layer);

  void loadSprite(std::string path);

  void update();
  void tick(uint64_t tick_count);

  // Movement
  void moveUp(int amount);
  void moveDown(int amount);
  void moveLeft(int amount);
  void moveRight(int amount);
};

#endif // GAME_OBJECT_H
