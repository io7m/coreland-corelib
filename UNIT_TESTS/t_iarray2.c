#include <stdio.h>
#include "t_iarray.h"
#include "t_assert.h"
#include "../iarray.h"

/* test indexing and concatenation */

#define ITERS 20UL

int main(void)
{
  struct iarray ia;
  unsigned long *iptr;
  unsigned long ind;
  unsigned long old_a;
  unsigned long old_u;
  unsigned long sz;

  test_assert(iarray_init(&ia, 2));

  for (ind = 0; ind < ITERS; ++ind) {
    old_a = ia.a;
    old_u = ia.u;
    test_assert(iarray_cat(&ia, &ind, sizeof(ind)));
    if (ia.a != old_a)
      printf("info: realloc %lu -> %lu\n", old_a, ia.a);
    test_assert(ia.u > old_u);
  }

  test_assert(iarray_integrity(&ia));

  for (ind = 0; ind < ITERS; ++ind) {
    test_assert(iarray_index(&ia, ind, (void **) &iptr, &sz));
    test_assert(*iptr == ind);
  }

  test_assert(iarray_size(&ia) == ITERS);
  test_assert(iarray_bytes(&ia) == ITERS * sizeof(unsigned long));

  iarray_dump(&ia, IARRAY_DUMP_INT);
  iarray_free(&ia);
  return 0;
}
