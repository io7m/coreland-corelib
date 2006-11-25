
#include <stdio.h>
#include "t_iarray.h"
#include "../iarray.h"

#define ITERS 20

int main()
{
  struct iarray ia;
  struct iarray_node *in;
  unsigned long ind;
  unsigned long *iptr;
  unsigned long old_a;
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

  /* CASE 1: insert new node */
  old_a = ia.a;
  old_u = ia.u;
  ind = 5 << 5;
  if (!iarray_insert(&ia, 5, &ind, sizeof(ind))) {
    printf("fail: iarray_insert at %lu\n", 5UL);
    return 1;
  }
  if (!iarray_integrity(&ia)) return 1;
  if (ia.a <= old_a) {
    printf("fail: unexpected a value %lu\n", ia.a);
    return 1;
  }
  if (ia.u <= old_u) {
    printf("fail: unexpected u value %lu\n", ia.u);
    return 1;
  }
  if (!iarray_index(&ia, 5, (void **) &iptr, &sz)) {
    printf("fail: iarray_index at %lu\n", 0UL);
    return 1;
  }
  if (*iptr != 5 << 5) {
    printf("fail: index 5 - %lu != %lu\n", *iptr, 5UL << 5);
    return 1;
  }
  if (!iarray_index(&ia, 6, (void **) &iptr, &sz)) {
    printf("fail: iarray_index at %lu\n", 0UL);
    return 1;
  }
  if (*iptr != 5) {
    printf("fail: index 6 - %lu != %lu\n", *iptr, 5UL);
    return 1;
  }

  /* CASE 2: re-use removed node */
  iarray_remove(&ia, 5);

  old_u = ia.u;
  old_a = ia.a;
  ind = 5 << 10;
  if (!iarray_insert(&ia, 5, &ind, sizeof(ind))) {
    printf("fail: iarray_insert at %lu\n", 5UL);
    return 1;
  }
  if (!iarray_integrity(&ia)) return 1;
  if (old_a != ia.a) {
    printf("fail: iarray_insert allocated %lu -> %lu - expected reuse\n",
            old_a, ia.a);
    return 1;
  }
  if (ia.u <= old_u) {
    printf("fail: unexpected u value %lu\n", ia.u);
    return 1;
  }
  if (!iarray_index(&ia, 5, (void **) &iptr, &sz)) {
    printf("fail: iarray_index at %lu\n", 0UL);
    return 1;
  }
  if (*iptr != 5 << 10) {
    printf("fail: index 5 - %lu != %lu\n", *iptr, 5UL << 10);
    return 1;
  }

  /* CASE 3: insert new head node */
  old_u = ia.u;
  old_a = ia.a;
  ind = 32768;
  if (!iarray_insert(&ia, 0, &ind, sizeof(ind))) {
    printf("fail: iarray_insert at %lu\n", 0UL);
    return 1;
  }
  if (!iarray_integrity(&ia)) return 1;
  if (ia.a <= old_a) {
    printf("fail: iarray_insert did not reallocate (%lu)\n", ia.a);
    return 1;
  }
  if (ia.u <= old_u) {
    printf("fail: unexpected u value %lu\n", ia.u);
    return 1;
  }
  if (!iarray_index(&ia, 0, (void **) &iptr, &sz)) {
    printf("fail: iarray_index at %lu\n", 0UL);
    return 1;
  }
  if (*iptr != 32768) {
    printf("fail: index 0 - %lu != %lu\n", *iptr, 32768UL);
    return 1;
  }

  /* CASE 4: reject out of bounds node */
  if (iarray_insert(&ia, 1000, &ind, sizeof(ind))) {
    printf("fail: iarray_insert did not reject index 1000\n");
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
