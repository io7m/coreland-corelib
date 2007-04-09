#include "bin.h"
#include "chashtable.h"
#include "str.h"

int cht_gets(const struct chashtable *ch,
             const void *key, void **data, unsigned long *dlen)
{
  return cht_getb(ch, key, str_len(key), data, dlen);
}
