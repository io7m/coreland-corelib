#include <unistd.h>
#include <stdio.h>
#include "t_hashtable.h"
#include "../hashtable.h"

int main()
{
  hashtable ht;
  ht_init(&ht);

  ht_free(&ht);
  return 0;
}
