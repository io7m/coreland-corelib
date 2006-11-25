#include "hashtable.h"
#include "str.h"

int ht_adds(struct hashtable *h, const void *k, const void *x)
{
  return ht_addb(h, k, str_len((const char *) k),
                    x, str_len((const char *) x));
}
