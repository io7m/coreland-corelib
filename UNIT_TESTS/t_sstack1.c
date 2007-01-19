#include <stdio.h>
#include "../sstack.h"

#define STACK_SIZE 8

struct object {
  unsigned long num;
};

char buf[STACK_SIZE * sizeof(struct object)];
struct sstack st;

int main()
{
  struct object obj;
  struct object *obp;
  const void *vp;
  unsigned long num;
  unsigned long cmp;

  sstack_init(&st, buf, STACK_SIZE, sizeof(struct object));

  /* check size is zero */
  if (sstack_size(&st) != 0) {
    printf("fail: sstack_size: %lu != 0\n", sstack_size(&st));
    return 1;
  }
  if (sstack_SIZE(&st) != 0) {
    printf("fail: sstack_SIZE: %lu != 0\n", sstack_SIZE(&st));
    return 1;
  }

  /* check push works */
  for (num = 0; num < STACK_SIZE; ++num) {
    obj.num = num;
    if (!sstack_push(&st, &obj)) {
      printf("fail: sstack_push: failed at %lu\n", num);
      return 1;
    }
  }

  /* check size is correct */
  if (sstack_bytes(&st) != STACK_SIZE * sizeof(struct object)) {
    printf("fail: sstack_bytes: %lu != %lu\n", sstack_bytes(&st),
            STACK_SIZE * sizeof(struct object));
    return 1;
  }
  if (sstack_BYTES(&st) != STACK_SIZE * sizeof(struct object)) {
    printf("fail: sstack_bytes: %lu != %lu\n", sstack_BYTES(&st),
            STACK_SIZE * sizeof(struct object));
    return 1;
  }
  if (sstack_size(&st) != STACK_SIZE) {
    printf("fail: sstack_size: %lu != %lu\n", sstack_size(&st), STACK_SIZE);
    return 1;
  }
  if (sstack_SIZE(&st) != STACK_SIZE) {
    printf("fail: sstack_SIZE: %lu != %lu\n", sstack_SIZE(&st), STACK_SIZE);
    return 1;
  }

  /* check pop and peek work */
  for (num = 0; num < STACK_SIZE; ++num) {
    sstack_peek(&st, (void **) &obp);
    if (!obp) {
      printf("fail: sstack_peek: failed at %lu\n", num);
      return 1;
    }
    cmp = obp->num;
    if (cmp != STACK_SIZE - 1 - num) {
      printf("fail: sstack_peek: %lu != %lu\n", cmp, STACK_SIZE - 1 - num);
      return 1;
    }
    sstack_pop(&st, (void **) &obp);
    if (!obp) {
      printf("fail: sstack_pop: failed at %lu\n", num);
      return 1;
    }
    cmp = obp->num;
    if (cmp != STACK_SIZE - 1 - num) {
      printf("fail: sstack_pop: %lu != %lu\n", cmp, STACK_SIZE - 1 - num);
      return 1;
    }
  }

  /* check data works */
  vp = sstack_data(&st);
  if (vp != buf) {
    printf("fail: sstack_data: %p != %p\n", vp, buf);
    return 1;
  }
  vp = sstack_DATA(&st);
  if (vp != buf) {
    printf("fail: sstack_DATA: %p != %p\n", vp, buf);
    return 1;
  }

  return 0;
}
