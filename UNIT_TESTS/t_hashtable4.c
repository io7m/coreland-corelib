#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "t_hashtable.h"
#include "../hashtable.h"
#include "../bin.h"
#include "../alloc.h"
#include "../str.h"
#include "t_assert.h"

static unsigned long num_allocs = 0;

static void *count_malloc(unsigned long n)
{
  ++num_allocs;
  return malloc(n);
}

void replace1(struct hashtable *h)
{
  const char *key;
  char *dat;
  unsigned long len;
  unsigned long nlen;

  key = "1234";
  dat = "1234";
  add(h, key, dat, 1);
  get(h, key, &dat, &len, 1);

  test_assert(num_allocs == 3);

  dat = "123456";
  replace(h, key, dat, 1);
  get(h, key, &dat, &nlen, 1);

  test_assert(num_allocs == 4);
  test_assert(nlen != len);
}

int main(void)
{
  struct hashtable ht;

  alloc_set_alloc(count_malloc);

  test_assert(ht_init(&ht));
  replace1(&ht);
  ht_free(&ht);
  return 0;
}
