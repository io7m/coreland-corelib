#include "hashtable.h"

int ht_checkb(const struct hashtable *h, const void *k, unsigned long klen)
{
  return ht_getb(h, k, klen, 0, 0);
}
