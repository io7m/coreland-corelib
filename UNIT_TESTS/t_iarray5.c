
#include <stdio.h>
#include "t_iarray.h"
#include "../iarray.h"

#define ITERS 20

int main(void)
{
  struct iarray ia;
  struct iarray_node *in;
  unsigned long ind;
  unsigned long old_a;
  unsigned long old_u;

  if (!iarray_init(&ia, 2)) {
    printf("fail: iarray_init\n");
    return 1;
  }

  for (ind = 0; ind < ITERS; ++ind) {
    if (!iarray_cat(&ia, &ind, sizeof(ind))) {
      printf("fail: iarray_cat at %lu\n", ind);
      return 1;
    }
  }

  old_a = ia.a;
  old_u = ia.u;
  iarray_chop(&ia, 10);
  if (!iarray_integrity(&ia)) return 0;
  if (old_u <= ia.u) {
    printf("fail: iarray_chop unexpected u value %lu\n", ia.u);
    return 1;
  }
  if (old_a != ia.a) {
    printf("fail: iarray_chop unexpected a value %lu\n", ia.a);
    return 1;
  }

  old_a = ia.a;
  old_u = ia.u;
  iarray_trunc(&ia);
  if (!iarray_integrity(&ia)) return 0;
  if (ia.u != 0) {
    printf("fail: iarray_chop unexpected u value %lu\n", ia.u);
    return 1;
  }
  if (old_a != ia.a) {
    printf("fail: iarray_chop unexpected a value %lu\n", ia.a);
    return 1;
  }

  ind = 0;
  in = ia.head;
  for (;;) {
    if (in->data)
      printf("[%lu] %lu\n", ind, * (unsigned long *) in->data);
    else
      printf("[%lu] X\n", ind);
    if (in->next)
      in = in->next;
    else
      break;
    ++ind;
  }

  iarray_free(&ia);
  return 0;
}
