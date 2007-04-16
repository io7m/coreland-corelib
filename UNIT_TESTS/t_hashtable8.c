#include <unistd.h>
#include <stdio.h>
#include "t_hashtable.h"
#include "t_assert.h"
#include "../hashtable.h"

/*
 * ht_clear_ext accidentally called free()
 * regression test
 */

struct hashtable ht;

unsigned long count()
{
  unsigned long ind;
  unsigned long max = 0;
  for (ind = 0; ind < HT_HASH_BUCKETS; ++ind)
    max += ht.slots[ind].allocd;
  return max;
}

int X(void *kptr, unsigned long klen,
      void *xptr, unsigned long xlen, void *udat)
{
  xptr = 0;
  xlen = 0;
  udat = 0;
  printf("info: X called\n");
  return 1;
}

int main(void)
{
  unsigned long al1;
  unsigned long al2;

  test_assert(ht_init(&ht));

  add(&ht, "AAAAAAAAAAAA", "AAAAAAAAAAAA", 1);
  add(&ht, "BBBBBBBBBBBB", "BBBBBBBBBBBB", 1);
  add(&ht, "CCCCCCCCCCCC", "CCCCCCCCCCCC", 1);
  add(&ht, "DDDDDDDDDDDD", "DDDDDDDDDDDD", 1);
  add(&ht, "EEEEEEEEEEEE", "EEEEEEEEEEEE", 1);
  add(&ht, "FFFFFFFFFFFF", "FFFFFFFFFFFF", 1);
  add(&ht, "HHHHHHHHHHHH", "HHHHHHHHHHHH", 1);
  add(&ht, "IIIIIIIIIIII", "IIIIIIIIIIII", 1);
  add(&ht, "JJJJJJJJJJJJ", "JJJJJJJJJJJJ", 1);
  add(&ht, "KKKKKKKKKKKK", "KKKKKKKKKKKK", 1);
  add(&ht, "LLLLLLLLLLLL", "LLLLLLLLLLLL", 1);
  add(&ht, "MMMMMMMMMMMM", "MMMMMMMMMMMM", 1);

  al1 = count();
  test_assert(al1 == 12);

  ht_clear_ext(&ht, X, 0);

  al2 = count();
  test_assert(al1 == al2);

  ht_free(&ht);
  return 0;
}
