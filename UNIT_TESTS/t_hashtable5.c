#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "t_hashtable.h"
#include "../hashtable.h"
#include "../bin.h"
#include "../error.h"
#include "../alloc.h"
#include "../str.h"

static unsigned long num_allocs = 0;

static void *count_malloc(unsigned long n)
{
  ++num_allocs;
  return malloc(n);
}

void except1(struct hashtable *h)
{
  /* try to trigger overflow condition */
  h->slots[1].used = -1;

  add(h, ch1str[0], ch1str[0], -1);
  if (errno != error_overflow) {
    printf("fail: 1 except1 errno == %d\n", errno); _exit(1);
  }

  ht_free(h);
  ht_init(h);

  if (h->slots[1].used != 0) {
    printf("fail: 1 except1 slots[1].used == %lu\n", h->slots[1].used); _exit(1);
  }
}

int main()
{
  struct hashtable ht;

  set_alloc(count_malloc);

  ht_init(&ht);

  except1(&ht);

  ht_free(&ht);
  return 0;
}
