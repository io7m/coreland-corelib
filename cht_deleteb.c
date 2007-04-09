#include "alloc.h"
#include "chashtable.h"

int cht_deleteb(struct chashtable *ch, const void *key, unsigned long klen)
{
  unsigned long hash;
  unsigned long ind;
  struct cht_node *node;

  hash = cht_hash1(key, klen);
   ind = hash & ch->mask;
  node = &ch->table1[ind];

  if (node->data)
    if (node->hash == hash) {
      dealloc(node->data);
      node->hash = 0;
      node->data = 0;
      node->dlen = 0;
      return 1;
    }

  hash = cht_hash2(key, klen);
   ind = hash & ch->mask;
  node = &ch->table2[ind];

  if (node->data)
    if (node->hash == hash) {
      dealloc(node->data);
      node->hash = 0;
      node->data = 0;
      node->dlen = 0;
      return 1;
    }

  return 0;
}
