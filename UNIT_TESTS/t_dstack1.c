#include <stdio.h>
#include "../dstack.h"
#include "t_assert.h"

#define STACK_SIZE 8

struct object {
  unsigned long num;
};

struct dstack st;

int main(void)
{
  struct object obj;
  struct object *obp;
  const void *vp;
  unsigned long num;
  unsigned long cmp;

  test_assert(dstack_init(&st, STACK_SIZE, sizeof(struct object)));

  /* check size is zero */
  test_assert(dstack_size(&st) == 0);
  test_assert(dstack_SIZE(&st) == 0);

  /* check pop on empty is no-op */
  test_assert(dstack_pop(&st, &obp) == 0);

  /* check push works */
  for (num = 0; num < STACK_SIZE; ++num) {
    obj.num = num;
    test_assert(dstack_push(&st, &obj));
  }

  /* check size is correct */
  test_assert(dstack_bytes(&st) == STACK_SIZE * sizeof(struct object));
  test_assert(dstack_BYTES(&st) == STACK_SIZE * sizeof(struct object));

  test_assert(dstack_size(&st) == STACK_SIZE);
  test_assert(dstack_SIZE(&st) == STACK_SIZE);

  /* check pop and peek work */
  for (num = 0; num < STACK_SIZE; ++num) {
    dstack_peek(&st, (void **) &obp);
    test_assert(obp);

    cmp = obp->num;
    test_assert(cmp == STACK_SIZE - 1 - num);

    dstack_pop(&st, (void **) &obp);
    test_assert(obp);

    cmp = obp->num;
    test_assert(cmp == STACK_SIZE - 1 - num);
  }

  return 0;
}
