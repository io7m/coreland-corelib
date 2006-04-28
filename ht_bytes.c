#include "hashtable.h"
#include "uint64.h"

uint64 ht_bytes(hashtable *h)
{
  uint64 b;
  uint32 n;
  table_node *p;

  n = h->size - 1;
  b = sizeof(hashtable);

  while (n) {
    if (h->slots[n].allocd) {
      p = h->slots[n].head;
      while (p) {
        if (p->state == SLOT_USED) {
          b += p->keylen;
          b += p->datalen;
        }
        p = p->next;
      }
    }
    --n;
  }

  return b;
}
