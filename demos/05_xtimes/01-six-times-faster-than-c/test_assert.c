#include <limits.h>

#ifndef FOO
#define FOO 1
#endif /* ifndef FOO */

typedef char STATIC_ASSERTION__[FOO == 1 ? 1 : -1];
typedef char STATIC_ASSERTION__[CHAR_BIT == 8 ? 1 : -1];
typedef char STATIC_ASSERTION__[(CHAR_BIT - 1) == 7 ? 1 : -1];

int main(int argc, char *argv[])
{
  return 0;
}
