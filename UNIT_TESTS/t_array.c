#include "../array.h"
#include <stdio.h>

#define LOOPS 1000

struct thing {
  unsigned long num;
  char buf[8];
};

int init_test(struct array *arr)
{
  unsigned long x;

  if (!array_init(arr, 10, sizeof(struct thing))) {
    printf("fail: init_test: array_init\n");
    return 0;
  }
  x = array_bytes(arr);
  if (x != 0) {
    printf("fail: init_test: array_bytes == %lu\n", x);
    return 0;
  }
  x = array_size(arr);
  if (x != 0) {
    printf("fail: init_test: array_size == %lu\n", x);
    return 0;
  }

  return 1;
}
int cat_test1(struct array *arr)
{
  unsigned long i;
  struct thing t;

  for (i = 0; i < LOOPS; ++i) {
    t.num = i;
    if (!array_cat(arr, &t)) {
      printf("fail: cat_test1: array_cat at %lu\n", i);
      return 0;
    }
  }

  return 1;
}
int index_test1(struct array *arr)
{
  unsigned long i;
  unsigned long max;
  struct thing *t;

  max = array_size(arr);
  if (max != LOOPS) {
    printf("fail: index_test1: max == %lu\n", max);
    return 0;
  }
  for (i = 0; i < max; ++i) {
    t = (struct thing *) array_index(arr, i);
    if (t->num != i) {
      printf("fail: index_test1: arr[%lu].num == %lu\n", i, t->num);
      return 0;
    }
  }

  return 1;
}
int copy_test(struct array *arr)
{
  static struct array brr;

  if (!array_copy(&brr, arr)) {
    printf("fail: copy_test: array_copy\n");
    return 0; 
  }
  if (arr->u != brr.u) {
    printf("fail: copy_test: u %lu != %lu\n", arr->u, brr.es); return 0;
  }
  if (arr->es != brr.es) {
    printf("fail: copy_test: es %lu != %lu\n", arr->es, brr.es); return 0;
  }

  array_free(&brr);
  return 1;
}
int chop_test(struct array *arr)
{
  unsigned long u;

  array_chop(arr, 10);
  u = array_size(arr);
  if (u != 10) {
    printf("fail: chop_test: chop u == %lu\n", u);
    return 0;
  }

  array_trunc(arr);
  u = array_size(arr);
  if (u != 0) {
    printf("fail: chop_test: trunc u == %lu\n", u);
    return 0;
  }
  return 1;
}
int free_test(struct array *arr)
{
  unsigned long u;

  array_free(arr);
  u = array_size(arr);
  if (u != 0) {
    printf("fail: free_test: u == %lu\n", u);
    return 0;
  }
  return 1;
}
int retrieve_test(struct array *arr)
{
  unsigned long i;
  unsigned long j;
  unsigned long *k;
  static struct array barr;

  if (!array_init(arr, 1, sizeof(unsigned long))) {
    printf("fail: retrieve_test: array_init\n");
    return 0;
  }
  for (i = 0; i < LOOPS; ++i) {
    j = i;
    if (!array_cat(arr, &j)) {
      printf("fail: retrieve_test: array_cat\n");
      return 0;
    }
  }
  for (i = 0; i < LOOPS; ++i) {
    k = (unsigned long *) array_index(arr, i);
    if (*k != i) {
      printf("fail: retrieve_test: k == %lu != %lu\n", *k, i);
      return 0;
    }
  }
  if (!array_copy(&barr, arr)) {
    printf("fail: retrieve_test: array_copy\n");
    return 0;
  }
  for (i = 0; i < LOOPS; ++i) {
    k = (unsigned long *) array_index(&barr, i);
    if (*k != i) {
      printf("fail: retrieve_test: (2) k == %lu != %lu\n", *k, i);
      return 0;
    }
  }

  array_free(&barr);
  return 1;
}
int overflow_test(struct array *arr)
{
  char ch;

  if (!array_init(arr, 1, 1)) {
    printf("fail: overflow_test: array_init\n");
    return 0;
  }
  arr->a = (unsigned long) -1;
  arr->u = (unsigned long) -1;

  ch = 'z';
  if (array_cat(arr, &ch)) {
    printf("fail: overflow_test: array_cat did not prevent overflow\n");
    printf("fail: arr.a: %llu\narr.u: %llu\n", arr->a, arr->u);
    return 0;
  }
  return 1;
}

int main()
{
  static struct array arr;

  if (!init_test(&arr)) return 1;
  if (!cat_test1(&arr)) return 1;
  if (!index_test1(&arr)) return 1;
  if (!copy_test(&arr)) return 1;
  if (!chop_test(&arr)) return 1;
  if (!free_test(&arr)) return 1;

  if (!retrieve_test(&arr)) return 1;
  if (!free_test(&arr)) return 1;

  if (!overflow_test(&arr)) return 1;
  return 0;
}
