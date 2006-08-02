#include "hashtable.h"
#include "str.h"

int ht_replaces(hashtable *h, const void* k, const void *x)
{
  return ht_replaceb(h, k, str_len((const char *) k),
                        x, str_len((const char *) x));
}
