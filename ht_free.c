#include "alloc.h"
#include "hashtable.h"

void ht_free(struct hashtable *h)
{
  ht_free_ext(h, 0);
}

void ht_free_ext(struct hashtable *h, void (*cleanup)(void *))
{
  unsigned long ind;
  struct ht_table_head *th;
  struct ht_table_node *tn;
  struct ht_table_node *tn_next;

  for (ind = 0; ind < HT_HASH_BUCKETS; ++ind) {
    th = &h->slots[ind];
    if (th->allocd) {
      tn = th->head;
      while (tn) {
        tn_next = tn->next;
        if (tn->state == HT_SLOT_USED) {
          if (cleanup)
            cleanup(tn->data);
          dealloc(tn->key);
          dealloc(tn->data);
        }
        dealloc(tn);
        --th->allocd;
        --th->used;
        tn = tn_next;
      }
      th->head = 0;
    }
  }
}
