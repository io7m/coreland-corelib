#include <stdio.h>
#include "../dqueue.h"
#include "t_assert.h"

#define QUEUE_SIZE 64

struct object {
  unsigned long num;
};

struct dqueue dq;

void dump()
{
  printf("%lu\t%lu\t%lu\t%lu\n", dq.hpos, dq.tpos, dq.a, dq.u);
}

int main(void)
{
  struct object obj;
  struct object *obp;
  unsigned long num;
  unsigned long cmp;

  dqueue_init(&dq, QUEUE_SIZE >> 4, sizeof(struct object));

  printf("h\tt\ta\tu\n");
  dump();

  /* check size is zero */
  test_assert(dqueue_size(&dq) == 0);
  test_assert(dqueue_SIZE(&dq) == 0);
  printf("\n");

  /* check enq works */
  for (num = 0; num < QUEUE_SIZE; ++num) {
    obj.num = num << 1;
    test_assert(dqueue_enq(&dq, &obj) == 1);
    dump();
  }
  printf("\n");

  /* check size is correct */
  test_assert(dqueue_bytes(&dq) == QUEUE_SIZE * sizeof(struct object));
  test_assert(dqueue_BYTES(&dq) == QUEUE_SIZE * sizeof(struct object));
  test_assert(dqueue_size(&dq) == QUEUE_SIZE);
  test_assert(dqueue_SIZE(&dq) == QUEUE_SIZE);

  dump();
  printf("\n");

  /* check deq works */
  for (num = 0; num < QUEUE_SIZE; ++num) {
    test_assert(dqueue_peek(&dq, (void **) &obp));

    cmp = obp->num;
    test_assert(cmp == num << 1);
    test_assert(dqueue_deq(&dq, (void **) &obp));

    cmp = obp->num;
    test_assert(cmp == num << 1);
    dump();
  }
  printf("\n");

  /* check deny underflow */
  test_assert(dqueue_deq(&dq, 0) == 0);

  dump();
  printf("\n");

  /* check enq works */
  for (num = 0; num < QUEUE_SIZE; ++num) {
    obj.num = num << 1;
    test_assert(dqueue_enq(&dq, &obj));
    dump();
  }
  printf("\n");

  /* check size is correct */
  test_assert(dqueue_bytes(&dq) == QUEUE_SIZE * sizeof(struct object));
  test_assert(dqueue_BYTES(&dq) == QUEUE_SIZE * sizeof(struct object));
  test_assert(dqueue_size(&dq) == QUEUE_SIZE);
  test_assert(dqueue_SIZE(&dq) == QUEUE_SIZE);

  dump();
  printf("\n");

  /* check deq works */
  for (num = 0; num < QUEUE_SIZE; ++num) {
    test_assert(dqueue_peek(&dq, (void **) &obp));

    cmp = obp->num;
    test_assert(cmp == num << 1);
    test_assert(dqueue_deq(&dq, (void **) &obp));

    cmp = obp->num;
    test_assert(cmp == num << 1);
    dump();
  }

  printf("\n");
  return 0;
}
