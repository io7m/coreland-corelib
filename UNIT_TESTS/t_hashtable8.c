#include <unistd.h>
#include <stdio.h>
#include "t_hashtable.h"
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

void X(void *x)
{
  printf("info: X called\n");
}

int main()
{
  unsigned long al1;
  unsigned long al2;

  ht_init(&ht);

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
  if (al1 != 12) {
    printf("fail: %lu != 12\n", al1);
    return 1;
  }

  ht_clear_ext(&ht, X);

  al2 = count();
  if (al1 != al2) {
    printf("fail: %lu != %lu\n", al1, al2);
    return 1;
  }

  ht_free(&ht);
  return 0;
}
