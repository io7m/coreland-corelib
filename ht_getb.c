#include "bin.h"
#include "hashtable.h"

/* 
   0 didn't find
   1 found
 */

int ht_getb(hashtable *h, const char* k, uint32 klen,
                               char **x, uint32 *xlen)
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
      if (p->state == SLOT_USED)
        if (bin_same(p->key, k, klen)) {
          *x = p->data;
          *xlen = p->datalen;
          return 1;
        }
      if (p->next)
        p = p->next;
      else
        return 0;
    }
  }

  return 0;
}
