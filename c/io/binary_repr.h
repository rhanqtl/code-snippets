#include <stdint.h>
#include <stdio.h>

char *to_binary_i(uint64_t v, char *bin, const int width) {
  for (int i = 0; i < width; i++) {
    bin[width - 1 - i] = ((v >> i) & 1) + '0';
  }
  bin[width] = '\0';
  return bin;
}
