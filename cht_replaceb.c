#include "chashtable.h"

int cht_replaceb_ext(struct chashtable *ch,
                     const void *key, unsigned long klen,
                     const void *dat, unsigned long dlen,
                     cht_callback *cleanup, void *udat)
{
  return 0;
}

int cht_replaceb(struct chashtable *ch,
                 const void *key, unsigned long klen,
                 const void *dat, unsigned long dlen)
{
  return cht_replaceb_ext(ch, key, klen, dat, dlen, 0, 0);
}
