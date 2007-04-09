#include "hashtable.h"

void ht_iter(struct hashtable *h, ht_callback *cb, void *udat)
{
  unsigned long ind;
  struct ht_table_head *th;
  struct ht_table_node *tn;

  for (ind = 0; ind < HT_HASH_BUCKETS; ++ind) {
    th = &h->slots[ind];
    if (!th->used) continue;
    if (th->allocd) {
      tn = th->head;
      while (tn) {
        if (tn->key) 
          if (cb(tn->data, tn->datalen, udat) == 0) return;
        tn = tn->next;
      }
    }
  }
}
