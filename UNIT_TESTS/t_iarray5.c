#include <stdio.h>
#include "t_iarray.h"
#include "t_assert.h"
#include "../iarray.h"

/* test iarray_chop() */

#define ITERS 20

int main(void)
{
  struct iarray ia;
  struct iarray_node *in;
  unsigned long ind;
  unsigned long old_a;
  unsigned long old_u;

  test_assert(iarray_init(&ia, 2));

  for (ind = 0; ind < ITERS; ++ind)
    test_assert(iarray_cat(&ia, &ind, sizeof(ind)));

  old_a = ia.a;
  old_u = ia.u;
  iarray_chop(&ia, 10);
  test_assert(iarray_integrity(&ia));
  test_assert(old_u > ia.u);
  test_assert(old_a == ia.a);

  old_a = ia.a;
  old_u = ia.u;
  iarray_trunc(&ia);
  test_assert(iarray_integrity(&ia));
  test_assert(ia.u == 0);
  test_assert(old_a == ia.a);

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
