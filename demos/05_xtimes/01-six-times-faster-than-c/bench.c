#include <stdio.h>
#include <stdlib.h> // atoi, srand
#include <limits.h>
#include <time.h>

int run_switchs(char *input);

static const int LENGTH = 1000000; // 1 million

#define BITMASK(b) (1 << ((b) % CHAR_BIT)) // CHAR_BIT is the number of bits in a char, usually 8

int main(int argc, char *argv[]) {
  if (arc < 3) {
    printf("Usage: %s <iterations> <seed>\n", argv[0]);
    return 1;
  }
  rand();

  const int n = atoi(argv[1]);
  const int seed = atoi(argv[2]);
  srand(seed);
}

