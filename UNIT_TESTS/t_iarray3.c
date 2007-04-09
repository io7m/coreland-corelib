#include <stdio.h>
#include "t_iarray.h"
#include "t_assert.h"
#include "../iarray.h"

/* test array index removal */

#define ITERS 20

int main(void)
{
  struct iarray ia;
  struct iarray_node *in;
  unsigned long ind;
  unsigned long *iptr;
  unsigned long old_u;
  unsigned long sz;

  test_assert(iarray_init(&ia, 2));

  for (ind = 0; ind < ITERS; ++ind)
    test_assert(iarray_cat(&ia, &ind, sizeof(ind)));

  /* removing N indices will 'move' values N steps forward */
  old_u = ia.u;

  iarray_remove(&ia, 0);
  test_assert(iarray_integrity(&ia));

  test_assert(ia.u < old_u);

  test_assert(iarray_index(&ia, 0, (void **) &iptr, &sz));
  test_assert(*iptr == 1);

  iarray_remove(&ia, 10);
  test_assert(iarray_integrity(&ia));

  test_assert(iarray_index(&ia, 10, (void **) &iptr, &sz));
  test_assert(*iptr == 12);

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
