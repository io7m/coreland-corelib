#include "bin.h"
#include "hashtable.h"

void ht_init(struct hashtable *h)
{
  bin_zero(&h->slots, HT_HASH_BUCKETS * sizeof(struct ht_table_head));
}
