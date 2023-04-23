#include "input_bus.hpp"

#include "input/keys.hpp"
#include "util/util.hpp"
#include <cstdlib>

void InputBus::clear() {
  keys.clear();
}

void InputBus::update() {
  int char_code = getchar();
  if (char_code != EOF) {
    char ch = keys::keycodeToChar(char_code);
    if (ch == 'q') {
      exit(0);
    }
    keys.push_back(ch);
  }
}
