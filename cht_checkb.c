#include "chashtable.h"

int cht_checkb(const struct chashtable *ch, const void *key, unsigned long klen)
{
  return cht_getb(ch, key, klen, 0, 0);
}
