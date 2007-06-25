#include <stdio.h>
#include "../array.h"
#include "t_assert.h"

int main(void)
{
  struct array arr;
  int i = 256;

  test_assert(array_init(&arr, 10, sizeof(int)));
  test_assert(array_bytes(&arr) == 0);
  test_assert(array_size(&arr) == 0);
  test_assert(array_catn(&arr, &i, 0) == 0);

  array_free(&arr);
  test_assert(array_bytes(&arr) == 0);
  test_assert(array_size(&arr) == 0);
  return 0;
}
