#include <stdio.h>
#include "t_iarray.h"
#include "t_assert.h"
#include "../iarray.h"

/* test array insertion */

#define ITERS 20

int main(void)
{
  struct iarray ia;
  struct iarray_node *in;
  unsigned long ind;
  unsigned long *iptr;
  unsigned long old_a;
  unsigned long old_u;
  unsigned long sz;

  test_assert(iarray_init(&ia, 2));

  for (ind = 0; ind < ITERS; ++ind)
    test_assert(iarray_cat(&ia, &ind, sizeof(ind)));

  /* CASE 1: insert new node */
  old_a = ia.a;
  old_u = ia.u;
  ind = 5 << 5;
  test_assert(iarray_insert(&ia, 5, &ind, sizeof(ind)));
  test_assert(iarray_integrity(&ia));
  test_assert(ia.a > old_a);
  test_assert(ia.u > old_u);

  test_assert(iarray_index(&ia, 5, (void **) &iptr, &sz));
  test_assert(*iptr == 5 << 5);
  test_assert(iarray_index(&ia, 6, (void **) &iptr, &sz));
  test_assert(*iptr == 5);

  /* CASE 2: re-use removed node */
  iarray_remove(&ia, 5);

  old_u = ia.u;
  old_a = ia.a;
  ind = 5 << 10;
  test_assert(iarray_insert(&ia, 5, &ind, sizeof(ind)));
  test_assert(iarray_integrity(&ia));
  test_assert(old_a == ia.a);
  test_assert(ia.u > old_u);
  test_assert(iarray_index(&ia, 5, (void **) &iptr, &sz));
  test_assert(*iptr == 5 << 10);

  /* CASE 3: insert new head node */
  old_u = ia.u;
  old_a = ia.a;
  ind = 32768;
  test_assert(iarray_insert(&ia, 0, &ind, sizeof(ind)));
  test_assert(iarray_integrity(&ia));
  test_assert(ia.a > old_a);
  test_assert(ia.u > old_u);
  test_assert(iarray_index(&ia, 0, (void **) &iptr, &sz));
  test_assert(*iptr == 32768);

  /* CASE 4: reject out of bounds node */
  test_assert(!iarray_insert(&ia, 1000, &ind, sizeof(ind)));

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
