#include "chashtable.h"
#include "str.h"

int cht_adds(struct chashtable *ch, const void *key, const void *dat)
{
  return cht_addb(ch, key, str_len(key), dat, str_len(dat));
}
