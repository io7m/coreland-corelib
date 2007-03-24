#include <stdio.h>
#include "t_iarray.h"
#include "../iarray.h"

int sort_numeric(const void *ap, unsigned long asize,
                 const void *bp, unsigned long bsize)
{
  unsigned long a = * (unsigned long *) ap;
  unsigned long b = * (unsigned long *) bp;
  return (a - b);
}
int sort_numeric_rev(const void *ap, unsigned long asize,
                     const void *bp, unsigned long bsize)
{
  unsigned long a = * (unsigned long *) ap;
  unsigned long b = * (unsigned long *) bp;
  return (b - a);
}

struct iarray ia;
struct iarray_node *nptr;
unsigned long ind;
unsigned long data;

/* reverse numeric -> numeric */
int test1()
{
  printf("--\n");

  if (!iarray_init(&ia, 10)) {
    printf("fail: iarray_init\n");
    return 1;
  }
  for (ind = 10; ind; --ind) {
    if (!iarray_cat(&ia, &ind, sizeof(unsigned long))) {
      printf("fail: iarray_cat %lu\n", ind);
      return 0;
    }
  }
  iarray_dump(&ia, IARRAY_DUMP_INT);
  iarray_sort(&ia, sort_numeric);
  iarray_dump(&ia, IARRAY_DUMP_INT);
  if (!iarray_integrity(&ia)) return 0;

  nptr = ia.head;
  for (ind = 0; ind < 10; ++ind) {
    data = * (unsigned long *) nptr->data;
    if (data != ind + 1) {
      printf("[%lu] fail: expected %lu got %lu\n", ind, ind + 1, data);
      return 0;
    }
    nptr = nptr->next;
    if (!nptr) break;
  }

  iarray_free(&ia);
  return 1;
}

/* reverse numeric odd -> numeric odd */
int test2()
{
  printf("--\n");

  if (!iarray_init(&ia, 10)) {
    printf("fail: iarray_init\n");
    return 1;
  }
  for (ind = 10; ind; --ind) {
    if (!iarray_cat(&ia, &ind, sizeof(unsigned long))) {
      printf("fail: iarray_cat %lu\n", ind);
      return 0;
    }
  }
  for (ind = 10; ind; --ind)
    if (ind % 2 == 0)
      iarray_remove(&ia, ind);
 
  iarray_dump(&ia, IARRAY_DUMP_INT);
  iarray_sort(&ia, sort_numeric);
  iarray_dump(&ia, IARRAY_DUMP_INT);
  if (!iarray_integrity(&ia)) return 0;

  nptr = ia.head;
  for (ind = 0; ind < 5; ++ind) {
    data = * (unsigned long *) nptr->data;
    if (data != ind * 2 + 1) {
      printf("[%lu] fail: expected %lu got %lu\n", ind, ind * 2 + 1, data);
      return 0;
    }
    nptr = nptr->next;
    if (!nptr) break;
  }

  iarray_free(&ia);
  return 1;
}

/* reverse numeric -> reverse numeric */
int test3()
{
  printf("--\n");

  if (!iarray_init(&ia, 10)) {
    printf("fail: iarray_init\n");
    return 1;
  }
  for (ind = 10; ind; --ind) {
    if (!iarray_cat(&ia, &ind, sizeof(unsigned long))) {
      printf("fail: iarray_cat %lu\n", ind);
      return 0;
    }
  }

  iarray_dump(&ia, IARRAY_DUMP_INT);
  iarray_sort(&ia, sort_numeric_rev);
  iarray_dump(&ia, IARRAY_DUMP_INT);
  if (!iarray_integrity(&ia)) return 0;

  nptr = ia.head;
  for (ind = 0; ind < 10; ++ind) {
    data = * (unsigned long *) nptr->data;
    if (data != 10 - ind) {
      printf("[%lu] fail: expected %lu got %lu\n", ind, 10 - ind, data);
      return 0;
    }
    nptr = nptr->next;
    if (!nptr) break;
  }

  iarray_free(&ia);
  return 1;
}

int test4()
{
  unsigned long unsorted[] = {
    49130,
    16616,
    77590,
    18428,
    5456,
    59622,
    46486,
    64587,
    71369,
    1574,
  };
  unsigned long sorted[] = {
    1574,
    5456,
    16616,
    18428,
    46486, 
    49130,
    59622,
    64587, 
    71369,
    77590,
  };

  printf("--\n");

  if (!iarray_init(&ia, 10)) {
    printf("fail: iarray_init\n");
    return 1;
  }
  for (ind = 0; ind < sizeof(unsorted) / sizeof(unsorted[0]); ++ind) {
    if (!iarray_cat(&ia, &unsorted[ind], sizeof(unsigned long))) {
      printf("fail: iarray_cat %lu\n", ind);
      return 0;
    }
  }

  iarray_dump(&ia, IARRAY_DUMP_INT);
  iarray_sort(&ia, sort_numeric);
  iarray_dump(&ia, IARRAY_DUMP_INT);
  if (!iarray_integrity(&ia)) return 0;

  nptr = ia.head;
  for (ind = 0; ind < sizeof(sorted) / sizeof(sorted[0]); ++ind) {
    data = * (unsigned long *) nptr->data;
    if (data != sorted[ind]) {
      printf("[%lu] fail: expected %lu got %lu\n", ind, sorted[ind], data);
      return 0;
    }
    nptr = nptr->next;
    if (!nptr) break;
  }

  iarray_free(&ia);
  return 1;
}

int main(void)
{
  if (!test1()) return 1;
  if (!test2()) return 1;
  if (!test3()) return 1;
  if (!test4()) return 1;

  return 0;
}
