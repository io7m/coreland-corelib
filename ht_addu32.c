#include "hashtable.h"
#include "uint32.h"

int ht_addu32(hashtable *h, const char *k, uint32 klen, uint32 n)
{
  return ht_addb(h, k, klen, (char *) &n, 4);
}
