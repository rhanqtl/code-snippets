#include <stdint.h>
#include <stdio.h>

char *to_binary_i(uint64_t v, char *bin, const int width) {
  for (int i = 0; i < width; i++) {
    bin[width - 1 - i] = ((v >> i) & 1) + '0';
  }
  bin[width] = '\0';
  return bin;
}

char *to_binary_f(float v, char *bin) {
  union f2i {
    float fval;
    uint32_t uval;
  } u;
  u.fval = v;
  to_binary_i(u.uval, bin, sizeof(float) * 8);
  return bin;
}

char *to_binary_d(double v, char *bin) {
  union d2i {
    double fval;
    uint64_t uval;
  } u;
  u.fval = v;
  to_binary_i(u.uval, bin, sizeof(double) * 8);
  return bin;
}
