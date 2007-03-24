#include <stdio.h>
#include "../squeue.h"

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
  if (squeue_size(&sq) != 0) {
    printf("fail: squeue_size: %lu != 0\n", squeue_size(&sq));
    return 1;
  }
  if (squeue_SIZE(&sq) != 0) {
    printf("fail: squeue_SIZE: %lu != 0\n", squeue_SIZE(&sq));
    return 1;
  }

  printf("\n");

  /* check enq works */
  for (num = 0; num < QUEUE_SIZE; ++num) {
    obj.num = num << 1;
    if (!squeue_enq(&sq, &obj)) {
      printf("fail: squeue_enq: could not add ind %lu\n", num);
      return 1;
    }
    dump();
  }

  printf("\n");

  /* check size is correct */
  if (squeue_bytes(&sq) != QUEUE_SIZE * sizeof(struct object)) {
    printf("fail: squeue_bytes: %lu != %lu\n", squeue_bytes(&sq),
            QUEUE_SIZE * sizeof(struct object));
    return 1;
  }
  if (squeue_BYTES(&sq) != QUEUE_SIZE * sizeof(struct object)) {
    printf("fail: squeue_bytes: %lu != %lu\n", squeue_BYTES(&sq),
            QUEUE_SIZE * sizeof(struct object));
    return 1;
  }
  if (squeue_size(&sq) != QUEUE_SIZE) {
    printf("fail: squeue_size: %lu != %lu\n", squeue_size(&sq), QUEUE_SIZE);
    return 1;
  }
  if (squeue_SIZE(&sq) != QUEUE_SIZE) {
    printf("fail: squeue_SIZE: %lu != %lu\n", squeue_SIZE(&sq), QUEUE_SIZE);
    return 1;
  }

  /* check deny overflow */
  if (squeue_enq(&sq, 0)) {
    printf("fail: queue overflow\n");
    return 1;
  }

  dump();
  printf("\n");

  /* check deq works */
  for (num = 0; num < QUEUE_SIZE; ++num) {
    if (!squeue_peek(&sq, (void **) &obp)) {
      printf("fail: squeue_peek: could not get ind %lu\n", num);
      return 1;
    }
    cmp = obp->num;
    if (cmp != num << 1) {
      printf("fail: squeue_peek: %lu != %lu\n", cmp, num);
      return 1;
    }
    if (!squeue_deq(&sq, (void **) &obp)) {
      printf("fail: squeue_deq: could not get ind %lu\n", num);
      return 1;
    }
    cmp = obp->num;
    if (cmp != num << 1) {
      printf("fail: squeue_deq: %lu != %lu\n", cmp, num);
      return 1;
    }
    dump();
  }

  printf("\n");

  /* check deny underflow */
  if (squeue_deq(&sq, 0)) {
    printf("fail: queue underflow\n");
    return 1;
  }

  dump();
  printf("\n");

  /* check enq works */
  for (num = 0; num < QUEUE_SIZE; ++num) {
    obj.num = num << 1;
    if (!squeue_enq(&sq, &obj)) {
      printf("fail: squeue_enq: could not add ind %lu\n", num);
      return 1;
    }
    dump();
  }

  printf("\n");

  /* check size is correct */
  if (squeue_bytes(&sq) != QUEUE_SIZE * sizeof(struct object)) {
    printf("fail: squeue_bytes: %lu != %lu\n", squeue_bytes(&sq),
            QUEUE_SIZE * sizeof(struct object));
    return 1;
  }
  if (squeue_BYTES(&sq) != QUEUE_SIZE * sizeof(struct object)) {
    printf("fail: squeue_bytes: %lu != %lu\n", squeue_BYTES(&sq),
            QUEUE_SIZE * sizeof(struct object));
    return 1;
  }
  if (squeue_size(&sq) != QUEUE_SIZE) {
    printf("fail: squeue_size: %lu != %lu\n", squeue_size(&sq), QUEUE_SIZE);
    return 1;
  }
  if (squeue_SIZE(&sq) != QUEUE_SIZE) {
    printf("fail: squeue_SIZE: %lu != %lu\n", squeue_SIZE(&sq), QUEUE_SIZE);
    return 1;
  }

  /* check deny overflow */
  if (squeue_enq(&sq, 0)) {
    printf("fail: queue overflow\n");
    return 1;
  }

  dump();
  printf("\n");

  /* check deq works */
  for (num = 0; num < QUEUE_SIZE; ++num) {
    if (!squeue_peek(&sq, (void **) &obp)) {
      printf("fail: squeue_peek: could not get ind %lu\n", num);
      return 1;
    }
    cmp = obp->num;
    if (cmp != num << 1) {
      printf("fail: squeue_peek: %lu != %lu\n", cmp, num);
      return 1;
    }
    if (!squeue_deq(&sq, (void **) &obp)) {
      printf("fail: squeue_deq: could not get ind %lu\n", num);
      return 1;
    }
    cmp = obp->num;
    if (cmp != num << 1) {
      printf("fail: squeue_deq: %lu != %lu\n", cmp, num);
      return 1;
    }
    dump();
  }

  printf("\n");

  /* check data works */
  vp = squeue_data(&sq);
  if (vp != buf) {
    printf("fail: squeue_data: %p != %p\n", vp, buf);
    return 1;
  }
  vp = squeue_DATA(&sq);
  if (vp != buf) {
    printf("fail: squeue_DATA: %p != %p\n", vp, buf);
    return 1;
  }

  return 0;
}
