#include "alloc.h"
#include "chashtable.h"

int cht_getb(const struct chashtable *ch, const void *key, unsigned long klen,
                                              void **data, unsigned long *dlen)
{
  unsigned long hash;
  unsigned long ind;
  unsigned long len;
  struct cht_node *node;

  hash = cht_hash1(key, klen);
   ind = hash & ch->mask;
  node = &ch->table1[ind];

  if (node->data)
    if (node->hash == hash) {
      if (data) *data = node->data;
      if (dlen) *dlen = node->dlen;
      return 1;
    }

  hash = cht_hash2(key, klen);
   ind = hash & ch->mask;
  node = &ch->table2[ind];

  if (node->data)
    if (node->hash == hash) {
      if (data) *data = node->data;
      if (dlen) *dlen = node->dlen;
      return 1;
    }

  return 0;
}
