#include <stdio.h>

/*
 * `static_assert` 少なくとも MSVC 2013 以上で (2010 から?) C/C++ 両方で使え
 * る。 ただし、エラーメッセージは "static_assert failed ..." のようにはなら
 * ず、"error C2338: ..." のように `C2338` のエラーとなる。
 */

#define static_assert1(exp) static_assert(exp, #exp)

static_assert1(sizeof(int) == 2);

int
main(int argc, char **argv)
{
  printf("_MSC_VER: %d\n", (int)_MSC_VER);
  return 0;
}
