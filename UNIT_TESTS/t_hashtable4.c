#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "t_hashtable.h"
#include "../hashtable.h"
#include "../bin.h"
#include "../alloc.h"
#include "../str.h"

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

  if (num_allocs != 3) {
    printf("fail: replace1: 1 num_allocs == %lu\n", num_allocs); _exit(1);
  }

  dat = "123456";
  replace(h, key, dat, 1);
  get(h, key, &dat, &nlen, 1);

  if (num_allocs != 4) {
    printf("fail: replace1: 2 num_allocs == %lu\n", num_allocs); _exit(1);
  }
  if (nlen == len) {
    printf("fail: replace1: 3 nlen == len\n"); _exit(1);
  }
}

int main()
{
  struct hashtable ht;

  set_alloc(count_malloc);

  ht_init(&ht);

  replace1(&ht);

  ht_free(&ht);
  return 0;
}
