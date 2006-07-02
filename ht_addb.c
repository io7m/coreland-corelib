#include "alloc.h"
#include "bin.h"
#include "hashtable.h"

/* 0 on no memory, 1 otherwise */

static int make_node(table_node **tnew,
                     const char *k, uint32 klen,
                     const char *x, uint32 xlen)
{
  register table_node *tmp;

  tmp = alloc(sizeof(table_node));
  if (!tmp) return 0;
  tmp->key = alloc(klen);
  if (!tmp->key)  { dealloc((char *) tmp); return 0; }
  tmp->data = alloc(xlen);
  if (!tmp->data) { dealloc(tmp->key); dealloc((char *) tmp); return 0; }
  tmp->keylen = klen;
  tmp->datalen = xlen;
  tmp->next = 0;
  tmp->state = SLOT_USED;

  bin_copy(k, tmp->key, klen);
  bin_copy(x, tmp->data, xlen);
  *tnew = tmp;
  return 1;
}

/* 
   -1 hard error (out of memory)
   0 duplicate key error
   1 ok
 */

int ht_addb(hashtable *h, const char *k, uint32 klen, 
                          const char *x, uint32 xlen)
{
  uint32 pos;
  uint32 max;
  uint32 allocd;
  uint32 used;
  table_node *tnew;
  table_node *fu;    /* pointer to first unused node */
  table_head *th;
  table_node *p;

  max = h->size;
  pos = ht_hash(k, klen) % max;
  th = &(h->slots[pos]);
  used = th->used;
  allocd = th->allocd;
  p = th->head;

  /* no head? */
  if (!allocd) {
    if (!make_node(&tnew, k, klen, x, xlen)) return -1;
    th->head = tnew;
    ++th->allocd;
    ++th->used;
    return 1;
  }
 
  /* key already taken? (also try to mark first unused node here) */ 
  fu = 0;
  if (used) {
    for (;;) {
      if (p->state == SLOT_UNUSED) {
        if (!fu) fu = p;
        if (p->next)
          p = p->next;
        else
          break; /* no matching node */
      } else {
        if (bin_same(p->key, k, klen)) return 0; /* matching node */
        if (p->next)
          p = p->next;
        else
          break; /* no matching node */
      }
    }
  } else {
    /* allocated but not used, use first node */
    fu = th->head;
  }

  /* detect int overflow */
  if ((used + 1) < used) return -1;

  /* if there was an unused node, use that */
  if (fu) {
    fu->key = alloc(klen);
    if (!fu->key) return -1;
    fu->data = alloc(xlen);
    if (!fu->data) { dealloc(fu->key); return -1; }
    bin_copy(k, fu->key, klen);
    bin_copy(x, fu->data, xlen);
    fu->keylen = klen;
    fu->datalen = xlen;
    fu->state = SLOT_USED;
    ++th->used;
  } else {
    /* need new node */
    if (!make_node(&tnew, k, klen, x, xlen)) return -1;
    p->next = tnew;
    ++th->used;
    ++th->allocd;
  }
  return 1;
}

/* algo note:

  if (none_allocated)
    return new
  
  if (some_used)
    first_unused = get_first_unused
  else
    first_unused = head
  
  if (first_unused)
    return fill_node
  else
    return add_new_node

*/
