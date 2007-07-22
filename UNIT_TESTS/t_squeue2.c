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

  /* fill queue */
  for (num = 0; num < QUEUE_SIZE; ++num) {
    obj.num = num;
    test_assert(squeue_enq(&sq, &obj) == 1);
    dump();
  }
  for (num = 0; num < QUEUE_SIZE / 2; ++num) {
    test_assert(squeue_deq(&sq, (void **) &obp) == 1);
    test_assert(obp->num == num % QUEUE_SIZE);
    dump();
  }
  for (num = 0; num < QUEUE_SIZE / 2; ++num) {
    obj.num = num;
    test_assert(squeue_enq(&sq, &obj) == 1);
    dump();
  }

  return 0;
}
