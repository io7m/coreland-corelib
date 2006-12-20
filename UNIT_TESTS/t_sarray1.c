#include "../sarray.h"

#define ARRAY_SIZE 8

struct object {
  unsigned long num;
};

char buf[ARRAY_SIZE * sizeof(struct object)];
struct sarray sa;

int main()
{
  struct object obj;
  struct object *obp;
  void *vp;
  unsigned long num;
  unsigned long cmp;

  sarray_init(&sa, buf, ARRAY_SIZE, sizeof(struct object));

  /* check size is zero */
  if (sarray_size(&sa) != 0) {
    printf("fail: sarray_size: %u != 0\n", sarray_size(&sa));
    return 1;
  }
  if (sarray_SIZE(&sa) != 0) {
    printf("fail: sarray_SIZE: %u != 0\n", sarray_SIZE(&sa));
    return 1;
  }

  /* check cat works */
  for (num = 0; num < ARRAY_SIZE; ++num) {
    obj.num = num;
    if (!sarray_cat(&sa, &obj)) {
      printf("fail: sarray_cat: failed at %lu\n", num);
      return 1;
    }
  }

  /* check size is correct */
  if (sarray_bytes(&sa) != ARRAY_SIZE * sizeof(struct object)) {
    printf("fail: sarray_bytes: %u != %u\n", sarray_bytes(&sa),
            ARRAY_SIZE * sizeof(struct object));
    return 1;
  }
  if (sarray_BYTES(&sa) != ARRAY_SIZE * sizeof(struct object)) {
    printf("fail: sarray_bytes: %u != %u\n", sarray_BYTES(&sa),
            ARRAY_SIZE * sizeof(struct object));
    return 1;
  }
  if (sarray_size(&sa) != ARRAY_SIZE) {
    printf("fail: sarray_size: %u != %u\n", sarray_size(&sa), ARRAY_SIZE);
    return 1;
  }
  if (sarray_SIZE(&sa) != ARRAY_SIZE) {
    printf("fail: sarray_SIZE: %u != %u\n", sarray_SIZE(&sa), ARRAY_SIZE);
    return 1;
  }

  /* check index works */
  for (num = 0; num < ARRAY_SIZE; ++num) {
    obp = sarray_index(&sa, num);
    if (!obp) {
      printf("fail: sarray_index: failed at %lu\n", num);
      return 1;
    }
    cmp = obp->num;
    if (cmp != num) {
      printf("fail: sarray_index: %lu != %lu\n", cmp, num);
      return 1;
    }
  }

  /* check chop works */
  sarray_chop(&sa, ARRAY_SIZE >> 1);
  if (sa.a != ARRAY_SIZE) {
    printf("fail: sa.a == %u expected %u\n", sa.a, ARRAY_SIZE);
    return 1;
  }
  if (sa.u != ARRAY_SIZE >> 1) {
    printf("fail: sa.a == %u expected %u\n", sa.u, ARRAY_SIZE >> 1);
    return 1;
  }

  for (num = 0; num < ARRAY_SIZE; ++num) {
    obp = sarray_index(&sa, num);
    if (!obp) {
      if (num != ARRAY_SIZE >> 1) {
        printf("fail: sarray_index: failed at %lu\n", num);
        return 1;
      } else break;
    }
    cmp = obp->num;
    if (cmp != num) {
      printf("fail: sarray_index: %lu != %lu\n", cmp, num);
      return 1;
    }
  }

  /* check truncation works */
  sarray_trunc(&sa);
  if (sarray_size(&sa) != 0) {
    printf("fail: sarray_trunc: %u != 0\n", sarray_size(&sa));
    return 1;
  }
 
  for (num = 0; num < ARRAY_SIZE; ++num) {
    obj.num = num;
    if (!sarray_cat(&sa, &obj)) {
      printf("fail: sarray_cat: failed at %lu\n", num);
      return 1;
    }
  }

  sarray_TRUNC(&sa);
  if (sarray_size(&sa) != 0) {
    printf("fail: sarray_TRUNC: %u != 0\n", sarray_size(&sa));
    return 1;
  }
 
  /* check data works */
  vp = sarray_data(&sa);
  if (vp != buf) {
    printf("fail: sarray_data: %p != %p\n", vp, buf);
    return 1;
  }
  vp = sarray_DATA(&sa);
  if (vp != buf) {
    printf("fail: sarray_DATA: %p != %p\n", vp, buf);
    return 1;
  }

  return 0;
}
