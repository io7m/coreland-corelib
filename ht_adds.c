#include "hashtable.h"
#include "str.h"

int ht_adds(hashtable *h, const char *k, const char *x)
{
  return ht_addb(h, k, str_len(k), x, str_len(x));
}
