#include <limits.h>

#include "binary_repr.h"

int main() {
    char bin[65];

    to_binary_i(INT_MAX, bin, sizeof(int) * 8);
    printf("%s\n", bin);

    to_binary_i(INT_MIN, bin, sizeof(int) * 8);
    printf("%s\n", bin);
}
