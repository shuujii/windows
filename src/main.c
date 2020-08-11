#include <stdio.h>

static_assert(1 == 0, "sa");

int
main(int argc, char **argv)
{
  printf("_MSC_VER: %d\n", (int)_MSC_VER);
  return 0;
}
