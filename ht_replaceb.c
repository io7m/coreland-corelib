#include "alloc.h"
#include "bin.h"
#include "hashtable.h"

int ht_replaceb_ext(struct hashtable *h, const void *k, unsigned long klen,
                                         const void *x, unsigned long dlen,
                                         ht_callback *callback, void *udat)
{
  struct ht_table_head *th;
  struct ht_table_node *np;
  unsigned long pos;
  unsigned long len;
  const char *key = (const char *) k;
  const char *dat = (const char *) x;
  unsigned char *tmpkey;
  unsigned char *tmpdat;

  pos = ht_hash(key, klen) & (HT_HASH_BUCKETS - 1);
  th = &(h->slots[pos]);
  np = th->head;
  tmpkey = 0;
  tmpdat = 0;

  if (!th->used) return 0;

  for (;;) {
    if (np->key) {
      if (klen >= np->keylen)
        len = klen;
      else
        len = np->keylen;
      if (bin_same(np->key, key, klen)) {
        if (callback) callback(np->key, np->keylen, np->data, np->datalen, udat);
        if (klen > np->keylen) {
          tmpkey = alloc(klen);
          if (!tmpkey) return -1;
        } else
          tmpkey = np->key;
        if (dlen > np->datalen) {
          tmpdat = alloc(dlen);
          if (!tmpdat) {
            if (tmpkey) dealloc(tmpkey);
            return -1;
          }
        } else tmpdat = np->data;
        bin_copy(key, tmpkey, klen);
        bin_copy(dat, tmpdat, dlen);
        np->keylen = klen;
        np->datalen = dlen;
        return 1;
      }
    }
    if (np->next)
      np = np->next;
    else
      return 0;
  }
}

int ht_replaceb(struct hashtable *h, const void *k, unsigned long klen,
                                     const void *x, unsigned long dlen)
{
  return ht_replaceb_ext(h, k, klen, x, dlen, 0, 0);
}
