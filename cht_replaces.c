#include "chashtable.h"
#include "str.h"

int cht_replaces_ext(struct chashtable *ch, const void *key, const void *dat,
                     cht_callback *cb, void *udat)
{
  return cht_replaceb_ext(ch, key, str_len(key), dat, str_len(dat), cb, udat);
}

int cht_replaces(struct chashtable *ch, const void *key, const void *dat)
{
  return cht_replaceb_ext(ch, key, str_len(key), dat, str_len(dat), 0, 0);
}
