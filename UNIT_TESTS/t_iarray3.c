#include <stdio.h>
#include "t_iarray.h"
#include "../iarray.h"

#define ITERS 20

int main(void)
{
  struct iarray ia;
  struct iarray_node *in;
  unsigned long ind;
  unsigned long *iptr;
  unsigned long old_u;
  unsigned long sz;

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

  /* removing N indices will 'move' values N steps forward */
  old_u = ia.u;

  iarray_remove(&ia, 0);
  if (!iarray_integrity(&ia)) return 1;

  if (ia.u >= old_u) {
    printf("fail: unexpected u value %lu\n", ia.u);
    return 1;
  }

  if (!iarray_index(&ia, 0, (void **) &iptr, &sz)) {
    printf("fail: iarray_index at %lu\n", 0UL);
    return 1;
  }
  if (*iptr != 1) {
    printf("fail: index 0 - %lu != %lu\n", *iptr, 1UL);
    return 1;
  } 

  iarray_remove(&ia, 10);
  if (!iarray_integrity(&ia)) return 1;

  if (!iarray_index(&ia, 10, (void **) &iptr, &sz)) {
    printf("fail: iarray_index at %lu\n", 0UL);
    return 1;
  }
  if (*iptr != 12) {
    printf("fail: index 0 - %lu != %lu\n", *iptr, 1UL);
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
