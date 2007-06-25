#include <stdio.h>
#include "../array.h"
#include "t_assert.h"

/* This test is intimate with the internals of array_catb */

int main(void)
{
  struct array arr;

  /* overflow 1, a * es */
  array_zero(&arr);
  arr.a = (unsigned long) -1;
  arr.es = 2;
  test_assert(array_catb(&arr, 0, 1) == 0);

  /* overflow 2, cur_alloc */
  array_zero(&arr);
  arr.a = (unsigned long) -1;
  arr.es = 1;
  test_assert(array_catb(&arr, 0, 1) == 0);

  /* overflow 3, cur_alloc by param */
  array_zero(&arr);
  arr.a = ((unsigned long) -1) / 2;
  arr.es = 1;
  test_assert(array_catb(&arr, 0, (unsigned long) -1) == 0);

  return 0;
}
