#include <stdio.h>
#include "t_iarray.h"
#include "../iarray.h"

#define ITERS 20

int main(void)
{
  struct iarray ia;
  struct iarray ib;
  struct iarray_node *in_a;
  struct iarray_node *in_b;
  unsigned long ind;

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

  /* remove some nodes to show effect of rebuild */

  iarray_remove(&ia, 0);
  iarray_remove(&ia, ITERS - 1);
  iarray_remove(&ia, ITERS / 5);
  iarray_remove(&ia, ITERS / 4);
  iarray_remove(&ia, ITERS / 2);

  iarray_zero(&ib);
  if (!iarray_copy(&ib, &ia)) {
    printf("fail: iarray_copy\n");
    return 1;
  }

  if (ib.u != ia.u) {
    printf("fail: unexpected u value %lu != %lu\n", ib.u, ia.u);
    return 1;
  }

  if (!iarray_integrity(&ib)) {
    printf("fail: iarray_integrity\n");
    return 1;
  }

  ind = 0;
  in_a = ia.head;
  in_b = ib.head;
  for (;;) {
    printf("[%lu] ", ind);

    if (in_a->data)
      printf("%lu ", * (unsigned long *) in_a->data);
    else
      printf("X ");

    if (in_b->data)
      printf("%lu ", * (unsigned long *) in_b->data);
    else
      printf("X ");
 
    printf("\n");
    if (in_a->next) in_a = in_a->next; else break;
    if (in_b->next) in_b = in_b->next; else break;

    ++ind;
  }

  iarray_free(&ia);
  iarray_free(&ib);
  return 0;
}
