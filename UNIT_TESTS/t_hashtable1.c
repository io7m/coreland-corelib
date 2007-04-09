#include <unistd.h>
#include <stdio.h>
#include "t_hashtable.h"
#include "../hashtable.h"
#include "t_assert.h"

int main(void)
{
  struct hashtable ht;
  test_assert(ht_init(&ht));

  ht_free(&ht);
  return 0;
}
