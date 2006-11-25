#include <stdio.h>
#include "t_iarray.h"
#include "../iarray.h"

int main()
{
  struct iarray ia;
  unsigned long x;

  if (!iarray_init(&ia, 2)) {
    printf("fail: iarray_init\n");
    return 1;
  }

  if (ia.tail->next) {
    printf("fail: ia.tail->next != 0\n");
    return 1;
  }
  if (ia.head->prev) {
    printf("fail: ia.tail->head != 0\n");
    return 1;
  }
  if (ia.u != 0) {
    printf("fail: ia.len != 0\n");
    return 1;
  }
  if (ia.a != 2 + IARRAY_OVERALLOC) {
    printf("fail: ia.len != %lu\n", 2UL + IARRAY_OVERALLOC);
    return 1;
  }
  x = iarray_bytes(&ia);
  if (x != 0) {
    printf("fail: iarray_bytes == %lu\n", x);
    return 1;
  }
  x = iarray_size(&ia);
  if (x != 0) {
    printf("fail: iarray_size == %lu\n", x);
    return 1;
  }

  if (!iarray_integrity(&ia)) return 1;

  iarray_free(&ia);
  return 0;
}
