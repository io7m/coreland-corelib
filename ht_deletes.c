#include "hashtable.h"
#include "str.h"

int ht_deletes(hashtable *h, const char *k)
{
  return ht_deleteb(h, k, str_len(k));
}
