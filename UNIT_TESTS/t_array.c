#include <stdio.h>

#include "../array.h"
#include "t_assert.h"

#define LOOPS 30

struct thing {
  unsigned long num;
  char buf[8];
};

int init_test(struct array *arr)
{
  test_assert(array_init(arr, 10, sizeof(struct thing)));
  test_assert(array_bytes(arr) == 0);
  test_assert(array_size(arr) == 0);

  return 1;
}
int cat_test1(struct array *arr)
{
  unsigned long i;
  struct thing t;

  for (i = 0; i < LOOPS; ++i) {
    t.num = i;
    test_assert(array_cat(arr, &t));
  }

  return 1;
}
int index_test1(struct array *arr)
{
  unsigned long i;
  unsigned long max;
  struct thing *t;

  max = array_size(arr);
  test_assert(max == LOOPS);

  for (i = 0; i < max; ++i) {
    t = (struct thing *) array_index(arr, i);
    test_assert(t->num == i);
  }

  return 1;
}
int copy_test(struct array *arr)
{
  static struct array brr;

  test_assert(array_copy(&brr, arr));
  test_assert(arr->u == brr.u);
  test_assert(arr->es == brr.es);

  array_free(&brr);
  return 1;
}
int chop_test(struct array *arr)
{
  array_chop(arr, 10);
  test_assert(array_size(arr) == 10);

  array_trunc(arr);
  test_assert(array_size(arr) == 0);

  return 1;
}
int free_test(struct array *arr)
{
  array_free(arr);
  test_assert(array_size(arr) == 0);

  return 1;
}
int retrieve_test(struct array *arr)
{
  unsigned long i;
  unsigned long j;
  unsigned long *k;
  static struct array barr;

  test_assert(array_init(arr, 1, sizeof(unsigned long)));

  for (i = 0; i < LOOPS; ++i) {
    j = i;
    test_assert(array_cat(arr, &j));
  }
  for (i = 0; i < LOOPS; ++i) {
    k = (unsigned long *) array_index(arr, i);
    test_assert(*k == i);
  }

  test_assert(array_copy(&barr, arr));
  for (i = 0; i < LOOPS; ++i) {
    k = (unsigned long *) array_index(&barr, i);
    test_assert(*k == i);
  }

  array_free(&barr);
  return 1;
}
int overflow_test(struct array *arr)
{
  char ch;

  test_assert(array_init(arr, 1, 1));

  arr->a = (unsigned long) -1;
  arr->u = (unsigned long) -1;

  ch = 'z';
  test_assert(!array_cat(arr, &ch));
  return 1;
}

int main(void)
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
