#include <stdio.h>
#include "../array.h"
#include "t_assert.h"

int main(void)
{
  struct array arr;
  int x[20];
  int i;

  test_assert(array_init(&arr, 10, sizeof(int)));
  test_assert(array_bytes(&arr) == 0);
  test_assert(array_size(&arr) == 0);

  for (i = 0; i < 20; ++i)
    x[i] = i;

  test_assert(array_catn(&arr, x, 20) == 1);
  test_assert(array_bytes(&arr) == sizeof(int) * 20);
  test_assert(array_size(&arr) == 20);

  array_free(&arr);
  test_assert(array_bytes(&arr) == 0);
  test_assert(array_size(&arr) == 0);
  return 0;
}
