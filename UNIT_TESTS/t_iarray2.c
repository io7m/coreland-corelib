#include <stdio.h>
#include "t_iarray.h"
#include "../iarray.h"

#define ITERS 20UL

int main()
{
  struct iarray ia;
  unsigned long *iptr;
  unsigned long ind;
  unsigned long old_a;
  unsigned long old_u;
  unsigned long sz;

  if (!iarray_init(&ia, 2)) {
    printf("fail: iarray_init\n");
    return 1;
  }

  for (ind = 0; ind < ITERS; ++ind) {
    old_a = ia.a;
    old_u = ia.u;
    if (!iarray_cat(&ia, &ind, sizeof(ind))) {
      printf("fail: iarray_cat at %lu\n", ind);
      return 1;
    }
    if (ia.a != old_a) {
      printf("info: realloc %lu -> %lu\n", old_a, ia.a);
    }
    if (ia.u <= old_u) {
      printf("fail: unexpected value u %lu\n", ia.u);
      return 1;
    }
  }

  if (!iarray_integrity(&ia)) return 1;

  for (ind = 0; ind < ITERS; ++ind) {
    if (!iarray_index(&ia, ind, (void **) &iptr, &sz)) {
      printf("fail: iarray_index at %lu\n", ind);
      return 1;
    }
    if (*iptr != ind) {
      printf("fail: iarray_index ind %lu != %lu\n", *iptr, ind);
      return 1;
    }
  }

  if (iarray_size(&ia) != ITERS) {
    printf("fail: iarray_size %lu != %lu\n", ia.u, ITERS);
    return 1;
  }
  if (iarray_bytes(&ia) != ITERS * sizeof(unsigned long)) {
    printf("fail: iarray_bytes %lu != %lu\n",
            iarray_bytes(&ia), ITERS * sizeof(unsigned long));
    return 1;
  }

  iarray_free(&ia);
  return 0;
}
