#include "alloc.h"
#include "bin.h"
#include "hashtable.h"

/*
  0: no such key
  1: ok
*/

int ht_deleteb(hashtable *h, const char *k, uint32 klen)
{
  uint32 pos;
  uint32 max;
  uint32 used;
  table_node *p;
  table_head *th;

  max = h->size;
  pos = ht_hash(k, klen) % max;
  th = &(h->slots[pos]);
  used = th->used;
  p = th->head;

  if (used) {
    for (;;) {
      if (p->state == SLOT_USED) {
        if (bin_same(p->key, k, klen)) {
          dealloc(p->data);
          dealloc(p->key);
          p->datalen = 0;
          p->keylen = 0;
          p->state = SLOT_UNUSED;
          th->used--;
          return 1;
        }
      }
      if (p->next)
        p = p->next;
      else
        return 0;
    }
  }

  return 0;
}
