#include "hashtable.h"
#include "str.h"

int ht_replaces(hashtable *h, const char* k, const char *x)
{
  return ht_replaceb(h, k, str_len(k), x, str_len(x));
}
