#include "alloc.h"
#include "bin.h"
#include "chashtable.h"

int cht_getb(const struct chashtable *ch, const void *key, unsigned long klen,
                                              void **data, unsigned long *dlen)
{
  unsigned long ind;
  unsigned long len;
  struct cht_node *node;

   ind = cht_hash1(key, klen) & ch->mask;
  node = &ch->table1[ind];

  if (node->key) {
    len = (klen >= node->klen) ? klen : node->klen;
    if (bin_same(node->key, key, len)) {
      if (data) *data = node->data;
      if (dlen) *dlen = node->dlen;
      return 1;
    }
  }

   ind = cht_hash2(key, klen) & ch->mask;
  node = &ch->table2[ind];

  if (node->key) {
    len = (klen >= node->klen) ? klen : node->klen;
    if (bin_same(node->key, key, len)) {
      if (data) *data = node->data;
      if (dlen) *dlen = node->dlen;
      return 1;
    }
  }

  return 0;
}
