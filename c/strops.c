#include "strops.h"

size_t width_of_i(int i) {
  size_t ans = i < 0 ? 1 : 0;
  while (i != 0) {
    ans++;
    i /= 10;
  }
  return ans;
}