#include <stdio.h>
#include "../dqueue.h"
#include "t_assert.h"

int main(void)
{
  struct dqueue dq;

  /* overflow 1, a * es */
  dqueue_zero(&dq);
  dq.a = (unsigned long) -1;
  dq.es = 2;
  test_assert(dqueue_enq(&dq, 0) == 0);

  /* overflow 2, cur_alloc */
  dqueue_zero(&dq);
  dq.a = (unsigned long) -1;
  dq.es = 1;
  test_assert(dqueue_enq(&dq, 0) == 0);

  return 0;
}
