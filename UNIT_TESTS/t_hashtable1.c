#include <unistd.h>
#include <stdio.h>
#include "t_hashtable.h"
#include "../hashtable.h"

int main()
{
  struct hashtable ht;
  ht_init(&ht);

  ht_free(&ht);
  return 0;
}
