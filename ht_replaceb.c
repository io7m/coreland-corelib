#include "alloc.h"
#include "bin.h"
#include "hashtable.h"

int ht_replaceb(hashtable *h, const void *k, unsigned long klen,
                              const void *x, unsigned long dlen)
{
  struct ht_table_head *th;
  struct ht_table_node *np;
  unsigned long pos;
  const char *key = (const char *) k;
  const char *dat = (const char *) x;
  char *tmpkey;
  char *tmpdat;

  pos = ht_hash(key, klen) % HT_HASH_BUCKETS;
  th = &(h->slots[pos]);
  np = th->head;
  tmpkey = 0;
  tmpdat = 0;

  if (!th->used) return 0;

  for (;;) {
    if (np->state == HT_SLOT_USED)
      if (bin_same(np->key, key, klen)) {
        if (klen > np->keylen) {
          tmpkey = alloc(klen);
          if (!tmpkey) return -1;
        } else tmpkey = np->key;
        if (dlen > np->datalen) {
          tmpdat = alloc(dlen);
          if (!tmpdat) {
            if (tmpkey) dealloc(tmpkey);
            return -1;
          }
        } else tmpdat = np->data;
        bin_copy((char *) key, tmpkey, klen);
        bin_copy((char *) dat, tmpdat, dlen);
        np->keylen = klen;
        np->datalen = dlen;
        return 1;
      }
    if (np->next)
      np = np->next;
    else
      return 0;
  }
}
