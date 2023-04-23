#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <cstdio>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

#define SET_RAW_MODE()                                                         \
  struct termios old_settings, new_settings;                                   \
  tcgetattr(STDIN_FILENO, &old_settings);                                      \
  new_settings = old_settings;                                                 \
  new_settings.c_lflag &= ~(ICANON | ECHO);                                    \
  tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);                             \
  fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);

#define RESTORE_MODE() tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);

#endif // TERMINAL_HPP
