#include "hashtable.h"

unsigned long ht_hash(const void *x, unsigned long len)
{
  const char *xc = x;
  unsigned long h = 5381;
  unsigned long c;
  while (len) {
    c = *xc;
    h = ((h << 5) + h) ^ c;
    --len; ++xc;
  }
  return h;
}
