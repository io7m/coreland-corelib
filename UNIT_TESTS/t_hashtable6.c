#include <unistd.h>
#include <stdio.h>
#include "t_hashtable.h"
#include "t_assert.h"
#include "../hashtable.h"
#include "../alloc.h"

struct data {
  unsigned int *x;
  unsigned int *y;
  unsigned int *z;
};

int datafree(void *key, unsigned long klen,
             void *vp, unsigned long dlen, void *udata)
{
  struct data *dp = (struct data *) vp;
  dealloc(dp->x);
  dealloc(dp->y);
  dealloc(dp->z);
  return 1;
}

int main(void)
{
  struct hashtable ht;
  struct data d;
  unsigned int ind;
  int r;

  test_assert(ht_init(&ht));

  for (ind = 0; ind < 100; ++ind) {
    d.x = alloc(sizeof(unsigned int));
    d.y = alloc(sizeof(unsigned int));
    d.z = alloc(sizeof(unsigned int));

    test_assert(d.x);
    test_assert(d.y);
    test_assert(d.z);

    r = ht_addb(&ht, &ind, sizeof(unsigned int), &d, sizeof(struct data));
    test_assert(r != 0);
    test_assert(r != -1);
  }

  ht_free_ext(&ht, datafree, 0);
  return 0;
}
