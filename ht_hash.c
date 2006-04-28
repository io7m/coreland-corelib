#include "hashtable.h"

uint32 ht_hash(const char *x, uint32 len)
{
  uint32 h = 5381;
  uint32 c;
  while (len) {
    c = *x;
    h = ((h << 5) + h) ^ c;
    --len; ++x;
  }
  return h;
}
