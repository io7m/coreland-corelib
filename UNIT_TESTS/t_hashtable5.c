#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "t_hashtable.h"
#include "t_assert.h"
#include "../str.h"
#include "../hashtable.h"
#include "../error.h"
#include "../bin.h"
#include "../alloc.h"

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
  test_assert(errno == error_overflow);

  ht_free(h);
  test_assert(ht_init(h));
  test_assert(h->slots[1].used == 0);
}

int main(void)
{
  struct hashtable ht;

  set_alloc(count_malloc);

  test_assert(ht_init(&ht));
  except1(&ht);
  ht_free(&ht);
  return 0;
}
