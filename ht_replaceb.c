#include "alloc.h"
#include "bin.h"
#include "hashtable.h"
#include "uint32.h"

/*
 -1 on error
 0 on not found
 1 on ok
 */

int ht_replaceb(hashtable *h, const char *k, uint32 klen,
                              const char *x, uint32 xlen)
{
  if (!ht_deleteb(h, k, klen)) return 0;
  return ht_addb(h, k, klen, x, xlen);
}
