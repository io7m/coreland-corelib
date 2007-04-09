#include "hashtable.h"
#include "str.h"

int ht_checks(const struct hashtable *h, const void *k)
{
  return ht_getb(h, k, str_len(k), 0, 0);
}
