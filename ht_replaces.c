#include "hashtable.h"
#include "str.h"

int ht_replaces_ext(struct hashtable *h, const void *k, const void *x,
                    ht_callback *cb, void *udat)
{
  return ht_replaceb_ext(h, k, str_len((const char *) k),
                            x, str_len((const char *) x), cb, udat);
}
int ht_replaces(struct hashtable *h, const void *k, const void *x)
{
  return ht_replaceb_ext(h, k, str_len((const char *) k),
                            x, str_len((const char *) x), 0, 0);
}
