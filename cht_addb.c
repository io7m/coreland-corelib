#include "alloc.h"
#include "bin.h"
#include "chashtable.h"

int cht_addb(struct chashtable *ch, const void *key, unsigned long klen,
                                    const void *dat, unsigned long dlen)
{
  unsigned long ind;
  unsigned long hash;
  unsigned int tries;
  struct cht_node ntmp1;
  struct cht_node ntmp2;
  struct cht_node *node;

  if (cht_checkb(ch, key, klen)) return 0;

  return 1;
}
