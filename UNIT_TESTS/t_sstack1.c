#include <stdio.h>
#include "../sstack.h"
#include "t_assert.h"

#define STACK_SIZE 8

struct object {
  unsigned long num;
};

char buf[STACK_SIZE * sizeof(struct object)];
struct sstack st;

int main(void)
{
  struct object obj;
  struct object *obp;
  const void *vp;
  unsigned long num;
  unsigned long cmp;

  sstack_init(&st, buf, STACK_SIZE, sizeof(struct object));

  /* check size is zero */
  test_assert(sstack_size(&st) == 0);
  test_assert(sstack_SIZE(&st) == 0);

  /* check push works */
  for (num = 0; num < STACK_SIZE; ++num) {
    obj.num = num;
    test_assert(sstack_push(&st, &obj));
  }

  /* check size is correct */
  test_assert(sstack_bytes(&st) == STACK_SIZE * sizeof(struct object));
  test_assert(sstack_BYTES(&st) == STACK_SIZE * sizeof(struct object));

  test_assert(sstack_size(&st) == STACK_SIZE);
  test_assert(sstack_SIZE(&st) == STACK_SIZE);

  /* check pop and peek work */
  for (num = 0; num < STACK_SIZE; ++num) {
    sstack_peek(&st, (void **) &obp);
    test_assert(obp);

    cmp = obp->num;
    test_assert(cmp == STACK_SIZE - 1 - num);

    sstack_pop(&st, (void **) &obp);
    test_assert(obp);

    cmp = obp->num;
    test_assert(cmp == STACK_SIZE - 1 - num);
  }

  /* check data works */
  vp = sstack_data(&st);
  test_assert(vp == buf);

  vp = sstack_DATA(&st);
  test_assert(vp == buf);
  return 0;
}
