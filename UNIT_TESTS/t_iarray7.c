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
}

int main()
{
  if (!test1()) return 1;

  {
    printf("fail: IARRAY SORTING IS BROKEN!\n");
    return 1;
  }

  return 0;
}
