#ifndef INPUT_INPUT_BUS_HPP
#define INPUT_INPUT_BUS_HPP

#include "util/util.hpp"

class InputBus {
public:
  std::vector<char> keys;

  void clear();
  void update();
};

#endif // INPUT_INPUT_BUS_HPP
