#include "alloc.h"
#include "hashtable.h"

static void ht_free_core(struct hashtable *h, void (*cleanup)(void *),
                         unsigned int node_free)
{
  unsigned long ind;
  struct ht_table_head *th;
  struct ht_table_node *tn;
  struct ht_table_node *tn_next;

  for (ind = 0; ind < HT_HASH_BUCKETS; ++ind) {
    th = &h->slots[ind];
    if (!th->used && !node_free) continue;
    if (th->allocd) {
      tn = th->head;
      while (tn) {
        tn_next = tn->next;
        if (tn->state == HT_SLOT_USED) {
          if (cleanup)
            cleanup(tn->data);
          dealloc(tn->key);
          dealloc(tn->data);
          tn->state = HT_SLOT_UNUSED;
        }
        if (node_free) {
          dealloc(tn);
          --th->allocd;
        }
        --th->used;
        tn = tn_next;
      }
      if (node_free) th->head = 0;
    }
  }
}

void ht_free(struct hashtable *h)
{
  ht_free_core(h, 0, 1);
}
void ht_free_ext(struct hashtable *h, void (*cb)(void *))
{
  ht_free_core(h, cb, 1);
}
void ht_clear(struct hashtable *h)
{
  ht_free_core(h, 0, 0);
}
void ht_clear_ext(struct hashtable *h, void (*cb)(void *))
{
  ht_free_core(h, cb, 0);
}
