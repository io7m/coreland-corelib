#include <unistd.h>
#include <stdio.h>
#include "t_hashtable.h"
#include "../alloc.h"
#include "../hashtable.h"

struct data {
  unsigned int *x;
  unsigned int *y;
  unsigned int *z;
};

void datafree(void *vp)
{
  struct data *dp = (struct data *) vp;
  dealloc(dp->x);
  dealloc(dp->y);
  dealloc(dp->z);
}

int main(void)
{
  struct hashtable ht;
  struct data d;
  unsigned int ind;

  ht_init(&ht);

  for (ind = 0; ind < 100; ++ind) {
    d.x = alloc(sizeof(unsigned int));
    d.y = alloc(sizeof(unsigned int));
    d.z = alloc(sizeof(unsigned int));
    if (!d.x || !d.y || !d.z) {
      printf("could not allocate memory\n");
      return 2;
    }
    switch (ht_addb(&ht, &ind, sizeof(unsigned int), &d, sizeof(struct data))) {
      case 0:
        printf("fail: key %u returned 0\n", ind);
        return 1;
      case -1:
        printf("fail: key %u returned -1\n", ind);
        return 1;
      default:
        break;
    }
  }

  ht_free_ext(&ht, datafree);
  return 0;
}
