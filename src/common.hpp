#ifndef COMMON_HPP
#define COMMON_HPP

#define WIDTH 150
#define HEIGHT 30

#define FPS 60
#define DELTA_TIME (1.0f / FPS)

#define CENTER_X (WIDTH / 2)
#define CENTER_Y (HEIGHT / 2)
#define MAX_X (WIDTH - 1)
#define MAX_Y (HEIGHT - 1)

#define DEBUG(...) fprintf(stderr, __VA_ARGS__)

#define UNIMPLEMENTED(...)                                                     \
  do {                                                                         \
    printf("%s:%d: UNIMPLEMENTED: %s \n", __FILE__, __LINE__, __VA_ARGS__);    \
    exit(1);                                                                   \
  } while (0)

#define UNREACHABLE(...)                                                       \
  do {                                                                         \
    printf("%s:%d: UNREACHABLE: %s \n", __FILE__, __LINE__, __VA_ARGS__);      \
    exit(1);                                                                   \
  } while (0)

#define UNUSED(x) (void)(x)

#endif // COMMON_HPP
