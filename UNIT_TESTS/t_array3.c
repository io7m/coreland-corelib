#include <stdio.h>
#include "../array.h"
#include "t_assert.h"

int main(void)
{
  struct array arr;
  int i;

  test_assert(array_init(&arr, 10, sizeof(int)));
  test_assert(array_bytes(&arr) == 0);
  test_assert(array_size(&arr) == 0);

  for (i = 0; i < 20; ++i) {
    test_assert(array_size(&arr) == i);
    test_assert(array_bytes(&arr) == i * sizeof(int));
    test_assert(array_cat(&arr, &i) == 1);
  }

  test_assert(array_size(&arr) == 20);
  test_assert(array_bytes(&arr) == 20 * sizeof(int));
 
  array_free(&arr);
  test_assert(array_bytes(&arr) == 0);
  test_assert(array_size(&arr) == 0);
  return 0;
}
