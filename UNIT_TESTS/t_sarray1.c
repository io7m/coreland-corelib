#include "../sarray.h"

#define ARRAY_SIZE 8

struct object {
  unsigned long num;
};

char buf[ARRAY_SIZE * sizeof(struct object)];
struct sarray sa;

int main()
{
  unsigned long num;
  unsigned long cmp;
  struct object obj;
  struct object *obp;

  sarray_init(&sa, buf, ARRAY_SIZE, sizeof(struct object));

  for (num = 0; num < ARRAY_SIZE; ++num) {
    obj.num = num;
    if (!sarray_cat(&sa, &obj)) {
      printf("fail: sarray_cat: failed at %lu\n", num);
      return 1;
    }
  }

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

  return 0;
}
