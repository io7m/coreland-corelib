#include "alloc.h"
#include "bin.h"
#include "hashtable.h"

int ht_deleteb(struct hashtable *h, const void *k, unsigned long len)
{
  unsigned long pos;
  struct ht_table_node *np;
  struct ht_table_head *th;
  const char *key;

  key = (const char *) k;
  pos = ht_hash(key, len) & (HT_HASH_BUCKETS - 1);
  th = &(h->slots[pos]);
  np = th->head;

  if (!th->used) return 0;

  for (;;) {
    if (np->key) {
      if (bin_same(np->key, key, len)) {
        dealloc(np->data);
        dealloc(np->key);
        np->key = 0;
        np->data = 0;
        np->datalen = 0;
        np->keylen = 0;
        --th->used;
        return 1;
      }
    }
    if (np->next)
      np = np->next;
    else
      return 0;
  }
}
