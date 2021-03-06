#include "hashtable.h"
#include "str.h"

int ht_gets(const struct hashtable *h, const void *k,
                                             void **data, unsigned long *len)
{
  return ht_getb(h, k, str_len((const char *) k), data, len);
}
