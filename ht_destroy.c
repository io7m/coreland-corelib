#include "alloc.h"
#include "hashtable.h"

void ht_destroy(hashtable *h)
{
  uint32 n;
  table_head *th;
  table_node *np;
  table_node *np_next;
  n = h->size;

  if (n) --n;
  if (!n) return;

  for (;;) {
    th = &(h->slots[n]);
    if (th->allocd) {
      np = th->head;
      for (;;) {
        np_next = np->next;
        if (np->state == SLOT_USED) {
          dealloc(np->data);
          dealloc(np->key);
        }
        dealloc((char *) np);
        th->allocd--;
        th->used--;
        np = np_next;
        if (!np) break;
      }
      th->head = 0;
    }
    if (!n) return;
    --n;
  }
}
