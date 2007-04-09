#include <stdio.h>
#include "t_iarray.h"
#include "t_assert.h"
#include "../iarray.h"

/* test initialization */

int main(void)
{
  struct iarray ia;
  unsigned long x;

  test_assert(iarray_init(&ia, 2));

  test_assert(ia.tail->next == 0);
  test_assert(ia.head->prev == 0);
  test_assert(ia.u == 0);
  test_assert(ia.a == 2 + IARRAY_OVERALLOC);

  x = iarray_bytes(&ia);
  test_assert(x == 0);

  x = iarray_size(&ia);
  test_assert(x == 0);

  test_assert(iarray_integrity(&ia));
  iarray_dump(&ia, IARRAY_DUMP_INT);

  iarray_free(&ia);
  return 0;
}
