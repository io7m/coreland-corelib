#include <stdio.h>
#include "t_iarray.h"
#include "t_assert.h"
#include "../iarray.h"

/* test iarray_sort() with various sorting functions */

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

  test_assert(iarray_init(&ia, 10));
  for (ind = 10; ind; --ind)
    test_assert(iarray_cat(&ia, &ind, sizeof(unsigned long)));

  iarray_dump(&ia, IARRAY_DUMP_INT);
  iarray_sort(&ia, sort_numeric);
  iarray_dump(&ia, IARRAY_DUMP_INT);
  test_assert(iarray_integrity(&ia));

  nptr = ia.head;
  for (ind = 0; ind < 10; ++ind) {
    data = * (unsigned long *) nptr->data;
    test_assert(data == ind + 1);
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

  test_assert(iarray_init(&ia, 10));
  for (ind = 10; ind; --ind)
    test_assert(iarray_cat(&ia, &ind, sizeof(unsigned long)));

  for (ind = 10; ind; --ind)
    if (ind % 2 == 0)
      iarray_remove(&ia, ind);
 
  iarray_dump(&ia, IARRAY_DUMP_INT);
  iarray_sort(&ia, sort_numeric);
  iarray_dump(&ia, IARRAY_DUMP_INT);
  test_assert(iarray_integrity(&ia));

  nptr = ia.head;
  for (ind = 0; ind < 5; ++ind) {
    data = * (unsigned long *) nptr->data;
    test_assert(data == ind * 2 + 1);
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

  test_assert(iarray_init(&ia, 10));
  for (ind = 10; ind; --ind)
    test_assert(iarray_cat(&ia, &ind, sizeof(unsigned long)));

  iarray_dump(&ia, IARRAY_DUMP_INT);
  iarray_sort(&ia, sort_numeric_rev);
  iarray_dump(&ia, IARRAY_DUMP_INT);
  test_assert(iarray_integrity(&ia));

  nptr = ia.head;
  for (ind = 0; ind < 10; ++ind) {
    data = * (unsigned long *) nptr->data;
    test_assert(data == 10 - ind);
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

  test_assert(iarray_init(&ia, 10));
  for (ind = 0; ind < sizeof(unsorted) / sizeof(unsorted[0]); ++ind)
    test_assert(iarray_cat(&ia, &unsorted[ind], sizeof(unsigned long)));

  iarray_dump(&ia, IARRAY_DUMP_INT);
  iarray_sort(&ia, sort_numeric);
  iarray_dump(&ia, IARRAY_DUMP_INT);
  test_assert(iarray_integrity(&ia));

  nptr = ia.head;
  for (ind = 0; ind < sizeof(sorted) / sizeof(sorted[0]); ++ind) {
    data = * (unsigned long *) nptr->data;
    test_assert(data == sorted[ind]);
    nptr = nptr->next;
    if (!nptr) break;
  }

  iarray_free(&ia);
  return 1;
}

int main(void)
{
  test1();
  test2();
  test3();
  test4();

  return 0;
}
