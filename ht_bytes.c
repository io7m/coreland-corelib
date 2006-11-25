#include "hashtable.h"

unsigned long ht_bytes(const struct hashtable *h)
{
  unsigned long ind;
  unsigned long b;
  struct ht_table_node *np;

  b = sizeof(struct hashtable);

  for (ind = 0; ind < HT_HASH_BUCKETS; ++ind) {
    if (h->slots[ind].allocd) {
      np = h->slots[ind].head;
      while (np) {
        if (np->state == HT_SLOT_USED) {
          b += np->keylen;
          b += np->datalen;
        }
        np = np->next;
      }
    }
  }
  return b;
}
