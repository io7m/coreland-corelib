#include <stdio.h>
#include "../squeue.h"
#include "t_assert.h"

#define QUEUE_SIZE 8

struct object {
  unsigned long num;
};

char buf[QUEUE_SIZE * sizeof(struct object)];
struct squeue sq;

void dump()
{
  printf("%lu %lu %lu\n", sq.hpos, sq.tpos, sq.u);
}

int main(void)
{
  struct object obj;
  struct object *obp;
  const void *vp;
  unsigned long num;
  unsigned long cmp;

  squeue_init(&sq, buf, QUEUE_SIZE, sizeof(struct object));

  printf("h t u\n");
  dump();

  /* check size is zero */
  test_assert(squeue_size(&sq) == 0);
  test_assert(squeue_SIZE(&sq) == 0);
  printf("\n");

  /* check enq works */
  for (num = 0; num < QUEUE_SIZE; ++num) {
    obj.num = num << 1;
    test_assert(squeue_enq(&sq, &obj) == 1);
    dump();
  }
  printf("\n");

  /* check size is correct */
  test_assert(squeue_bytes(&sq) == QUEUE_SIZE * sizeof(struct object));
  test_assert(squeue_BYTES(&sq) == QUEUE_SIZE * sizeof(struct object));
  test_assert(squeue_size(&sq) == QUEUE_SIZE);
  test_assert(squeue_SIZE(&sq) == QUEUE_SIZE);

  /* check deny overflow */
  test_assert(squeue_enq(&sq, 0) == 0);
  dump();
  printf("\n");

  /* check deq works */
  for (num = 0; num < QUEUE_SIZE; ++num) {
    test_assert(squeue_peek(&sq, (void **) &obp) == 1);
    cmp = obp->num;
    test_assert(cmp == num << 1);
    test_assert(squeue_deq(&sq, (void **) &obp));
    cmp = obp->num;
    test_assert(cmp == num << 1);
    dump();
  }
  printf("\n");

  /* check deny underflow */
  test_assert(squeue_deq(&sq, 0) == 0);
  dump();
  printf("\n");

  /* check enq works */
  for (num = 0; num < QUEUE_SIZE; ++num) {
    obj.num = num << 1;
    test_assert(squeue_enq(&sq, &obj) == 1);
    dump();
  }
  printf("\n");

  /* check size is correct */
  test_assert(squeue_bytes(&sq) == QUEUE_SIZE * sizeof(struct object));
  test_assert(squeue_BYTES(&sq) == QUEUE_SIZE * sizeof(struct object));
  test_assert(squeue_size(&sq) == QUEUE_SIZE);
  test_assert(squeue_SIZE(&sq) == QUEUE_SIZE);

  /* check deny overflow */
  test_assert(squeue_enq(&sq, 0) == 0);
  dump();
  printf("\n");

  /* check deq works */
  for (num = 0; num < QUEUE_SIZE; ++num) {
    test_assert(squeue_peek(&sq, (void **) &obp) == 1);
    cmp = obp->num;
    test_assert(cmp == num << 1);
    test_assert(squeue_deq(&sq, (void **) &obp));
    cmp = obp->num;
    test_assert(cmp == num << 1);
    dump();
  }
  printf("\n");

  /* check data works */
  vp = squeue_data(&sq);
  test_assert(vp == buf);
  vp = squeue_DATA(&sq);
  test_assert(vp == buf);

  return 0;
}
