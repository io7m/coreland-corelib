#include "hashtable.h"
#include "str.h"

int ht_gets(hashtable *h, const char* k, char **x, uint32 *xlen)
{
  return ht_getb(h, k, str_len(k), x, xlen);
}
