#include <stdio.h>
#include "t_iarray.h"
#include "../iarray.h"

int comp(const void *ap, unsigned long asize,
         const void *bp, unsigned long bsize)
{
  unsigned long a = (ap) ? * (unsigned long *) ap : 0;
  unsigned long b = (bp) ? * (unsigned long *) bp : 0;
  return (a - b);
}

struct iarray ia;

int main()
{
  unsigned long ind;

  if (!iarray_init(&ia, 10)) {
    printf("fail: iarray_init\n");
    return 1;
  }

  for (ind = 10; ind; --ind) {
    if (!iarray_cat(&ia, &ind, sizeof(unsigned long))) {
      printf("fail: iarray_cat %lu\n", ind);
      return 1;
    }
  }

  iarray_dump(&ia, IARRAY_DUMP_INT);
  iarray_sort(&ia, comp);
  iarray_dump(&ia, IARRAY_DUMP_INT);

  if (!iarray_integrity(&ia)) return 1;

  iarray_free(&ia);
  return 0;
}
