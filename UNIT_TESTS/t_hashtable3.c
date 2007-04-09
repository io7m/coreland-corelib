#include <unistd.h>
#include <stdio.h>
#include "t_hashtable.h"
#include "../hashtable.h"
#include "../bin.h"
#include "../str.h"
#include "t_assert.h"

void get1(struct hashtable *h)
{
  unsigned int ind;
  unsigned long len;
  char *str;

  for (ind = 0; ind < ch1str_len; ++ind)
    add(h, ch1str[ind], ch1str[ind], 1);

  for (ind = 0; ind < ch1str_len; ++ind) {
    get(h, ch1str[ind], &str, &len, 1);
    test_assert(len == str_len(ch1str[ind]));
    test_assert(bin_same(str, ch1str[ind], len));
  }

  for (ind = 0; ind < ch1str_len; ++ind)
    delete_key(h, ch1str[ind], 1);
}

struct test {
  unsigned int x;
  unsigned int y;
  unsigned int z;
};

void get2(struct hashtable *h)
{
  struct test t;
  struct test *tp;
  unsigned int ind;
  unsigned long len;

  for (ind = 0; ind < ch1str_len; ++ind) {
    t.x = ind;
    t.y = ind + 1;
    t.z = ind + 2;
    addb(h, (char *) &ind, sizeof(ind), (char *) &t, sizeof(t), 1);
  }

  for (ind = 0; ind < ch1str_len; ++ind) {
    getb(h, (char *) &ind, sizeof(ind), (char **) &tp, &len, 1);
    test_assert(len == sizeof(struct test));
    test_assert(tp->x == ind);
    test_assert(tp->y == ind + 1);
    test_assert(tp->z == ind + 2);
  }

  for (ind = 0; ind < ch1str_len; ++ind)
    delete_keyb(h, (char *) &ind, sizeof(ind), 1);
}

int main(void)
{
  struct hashtable ht;
  test_assert(ht_init(&ht));

  get1(&ht);
  get2(&ht);

  ht_free(&ht);
  return 0;
}
