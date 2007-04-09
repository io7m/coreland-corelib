#include <stdio.h>
#include "../sarray.h"
#include "t_assert.h"

#define ARRAY_SIZE 8

struct object {
  unsigned long num;
};

char buf[ARRAY_SIZE * sizeof(struct object)];
struct sarray sa;

int main(void)
{
  struct object obj;
  struct object *obp;
  const void *vp;
  unsigned long num;
  unsigned long cmp;

  sarray_init(&sa, buf, ARRAY_SIZE, sizeof(struct object));

  /* check size is zero */
  test_assert(sarray_size(&sa) == 0);
  test_assert(sarray_SIZE(&sa) == 0);

  /* check cat works */
  for (num = 0; num < ARRAY_SIZE; ++num) {
    obj.num = num;
    test_assert(sarray_cat(&sa, &obj));
  }

  /* check size is correct */
  test_assert(sarray_bytes(&sa) == ARRAY_SIZE * sizeof(struct object));
  test_assert(sarray_BYTES(&sa) == ARRAY_SIZE * sizeof(struct object));

  test_assert(sarray_size(&sa) == ARRAY_SIZE);
  test_assert(sarray_SIZE(&sa) == ARRAY_SIZE);

  /* check index works */
  for (num = 0; num < ARRAY_SIZE; ++num) {
    obp = sarray_index(&sa, num);
    test_assert(obp);
    cmp = obp->num;
    test_assert(cmp == num);
  }

  /* check chop works */
  sarray_chop(&sa, ARRAY_SIZE >> 1);
  test_assert(sa.a == ARRAY_SIZE);
  test_assert(sa.u == ARRAY_SIZE >> 1);

  for (num = 0; num < ARRAY_SIZE; ++num) {
    obp = sarray_index(&sa, num);

    if (!obp) {
      test_assert(!obp && num == ARRAY_SIZE >> 1);
      break;
    }
    cmp = obp->num;
    test_assert(cmp == num);
  }

  /* check truncation works */
  sarray_trunc(&sa);
  test_assert(sarray_size(&sa) == 0);
 
  for (num = 0; num < ARRAY_SIZE; ++num) {
    obj.num = num;
    test_assert(sarray_cat(&sa, &obj));
  }

  sarray_TRUNC(&sa);
  test_assert(sarray_size(&sa) == 0);
 
  /* check data works */
  vp = sarray_data(&sa);
  test_assert(vp == buf);

  vp = sarray_DATA(&sa);
  test_assert(vp == buf);

  return 0;
}
