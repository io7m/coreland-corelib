#include "hashtable.h"

void ht_init(hashtable *h)
{
  uint32 p;
  register table_head *th;

  h->size = HASH_BUCKETS;
  p = HASH_BUCKETS - 1;
  
  while (p) {
    th = &(h->slots[p]);
    th->allocd = 0;
    th->used = 0;
    th->head = 0;
    --p;
  }
}
