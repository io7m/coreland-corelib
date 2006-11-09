#include "../array.h"
#include <stdio.h>

#define LOOPS 1000

struct thing {
  unsigned int num;
  char buf[8];
};

int init_test(array *arr)
{
  unsigned int x;

  if (!array_init(arr, 10, sizeof(struct thing))) {
    printf("init_test: array_init\n");
    return 0;
  }
  x = array_bytes(arr);
  if (x != 0) {
    printf("init_test: array_bytes == %u\n", x);
    return 0;
  }
  x = array_size(arr);
  if (x != 0) {
    printf("init_test: array_size == %u\n", x);
    return 0;
  }

  return 1;
}
int cat_test1(array *arr)
{
  unsigned int i;
  struct thing t;

  for (i = 0; i < LOOPS; ++i) {
    t.num = i;
    if (!array_cat(arr, &t)) {
      printf("cat_test1: array_cat at %u\n", i);
      return 0;
    }
  }

  return 1;
}
int index_test1(array *arr)
{
  unsigned int i;
  unsigned int max;
  struct thing *t;

  max = array_size(arr);
  if (max != LOOPS) {
    printf("index_test1: max == %u\n", max);
    return 0;
  }
  for (i = 0; i < max; ++i) {
    t = (struct thing *) array_index(arr, i);
    if (t->num != i) {
      printf("index_test1: arr[%u].num == %u\n", i, t->num);
      return 0;
    }
  }

  return 1;
}
int copy_test(array *arr)
{
  static array brr;

  if (!array_copy(&brr, arr)) {
    printf("copy_test: array_copy\n");
    return 0; 
  }
  if (arr->u != brr.u) {
    printf("copy_test: u %u != %u\n", arr->u, brr.es); return 0;
  }
  if (arr->es != brr.es) {
    printf("copy_test: es %u != %u\n", arr->es, brr.es); return 0;
  }

  array_free(&brr);
  return 1;
}
int chop_test(array *arr)
{
  unsigned int u;

  array_chop(arr, 10);
  u = array_size(arr);
  if (u != 10) {
    printf("chop_test: u == %u\n", u);
    return 0;
  }
  return 1;
}
int free_test(array *arr)
{
  unsigned int u;

  array_free(arr);
  u = array_size(arr);
  if (u != 0) {
    printf("free_test: u == %u\n", u);
    return 0;
  }
  return 1;
}
int retrieve_test(array *arr)
{
  unsigned int i;
  unsigned int j;
  unsigned int *k;
  static array barr;

  if (!array_init(arr, 1, sizeof(unsigned int))) {
    printf("retrieve_test: array_init\n");
    return 0;
  }
  for (i = 0; i < LOOPS; ++i) {
    j = i;
    if (!array_cat(arr, &j)) {
      printf("retrieve_test: array_cat\n");
      return 0;
    }
  }
  for (i = 0; i < LOOPS; ++i) {
    k = (unsigned int *) array_index(arr, i);
    if (*k != i) {
      printf("retrieve_test: k == %u != %u\n", *k, i);
      return 0;
    }
  }
  if (!array_copy(&barr, arr)) {
    printf("retrieve_test: array_copy\n");
    return 0;
  }
  for (i = 0; i < LOOPS; ++i) {
    k = (unsigned int *) array_index(&barr, i);
    if (*k != i) {
      printf("retrieve_test: (2) k == %u != %u\n", *k, i);
      return 0;
    }
  }

  array_free(&barr);
  return 1;
}
int overflow_test(array *arr)
{
  char ch;

  if (!array_init(arr, 1, 1)) {
    printf("overflow_test: array_init\n");
    return 0;
  }
  arr->a = (unsigned long) -1;
  arr->u = (unsigned long) -1;

  ch = 'z';
  if (array_cat(arr, &ch)) {
    printf("overflow_test: array_cat did not prevent overflow\n");
    printf("arr.a: %llu\narr.u: %llu\n", arr->a, arr->u);
    return 0;
  }
  return 1;
}

int main()
{
  static array arr;

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
