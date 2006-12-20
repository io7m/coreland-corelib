#include "../squeue.h"

#define QUEUE_SIZE 4

struct object {
  unsigned long num;
};

char buf[QUEUE_SIZE * sizeof(struct object)];
struct squeue sq;

int main()
{
  unsigned long num;
  unsigned long cmp;
  struct object obj;
  struct object *obp;

  squeue_init(&sq, buf, QUEUE_SIZE, sizeof(struct object));

  for (num = 0; num < QUEUE_SIZE; ++num) {
    obj.num = num << 8;
    if (!squeue_enq(&sq, &obj)) {
      printf("fail: squeue_enq: could not add ind %lu\n", num);
      return 1;
    }
  }

  if (squeue_enq(&sq, 0)) {
    printf("fail: queue overflow\n");
    return 1;
  }

  for (num = 0; num < QUEUE_SIZE; ++num) {
    if (!squeue_deq(&sq, (void **) &obp)) {
      printf("fail: squeue_deq: could not get ind %lu\n", num);
      return 1;
    }
    cmp = obp->num;
    if (cmp != num << 8) {
      printf("fail: squeue_deq: %lu != %lu\n", cmp, num);
      return 1;
    }
  }

  if (squeue_deq(&sq, 0)) {
    printf("fail: queue underflow\n");
    return 1;
  }
  return 0;
}
