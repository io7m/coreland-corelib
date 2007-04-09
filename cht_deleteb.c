#include "alloc.h"
#include "bin.h"
#include "chashtable.h"

int cht_deleteb(struct chashtable *ch, const void *key, unsigned long klen)
{
  unsigned long ind;
  unsigned long len;
  struct cht_node *node;

   ind = cht_hash1(key, klen) & ch->mask;
  node = &ch->table1[ind];

  if (node->key) {
    len = (klen >= node->klen) ? klen : node->klen;
    if (bin_same(node->key, key, len)) {
      dealloc(node->key);
      dealloc(node->data);
      node->key = 0;
      node->data = 0;
      node->klen = 0;
      node->dlen = 0;
      return 1;
    }
  }

   ind = cht_hash2(key, klen) & ch->mask;
  node = &ch->table2[ind];

  if (node->key) {
    len = (klen >= node->klen) ? klen : node->klen;
    if (bin_same(node->key, key, len)) {
      dealloc(node->key);
      dealloc(node->data);
      node->key = 0;
      node->data = 0;
      node->klen = 0;
      node->dlen = 0;
      return 1;
    }
  }

  return 0;
}
