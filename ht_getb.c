#include "bin.h"
#include "hashtable.h"

int ht_getb(const struct hashtable *h, const void *k, unsigned long klen,
            void **dat, unsigned long *dlen)
{
  struct ht_table_head *th;
  struct ht_table_node *np;
  unsigned long pos;
  unsigned long len;
  const char *key = (const char *) k;

  pos = ht_hash(key, klen) & (HT_HASH_BUCKETS - 1);
  th = (struct ht_table_head *) &h->slots[pos];
  np = th->head;

  if (!th->used) return 0;

  for (;;) {
    if (np->state == HT_SLOT_USED) {
      if (klen >= np->keylen)
        len = klen;
      else
        len = np->keylen;
      if (bin_same(np->key, key, len)) {
        *dat = np->data;
        *dlen = np->datalen;
        return 1;
      }
    }
    if (np->next)
      np = np->next;
    else
      return 0;
  }
}
