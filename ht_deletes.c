#include "hashtable.h"
#include "str.h"

int ht_deletes(struct hashtable *h, const void *k)
{
  return ht_deleteb(h, k, str_len((const char *) k));
}
