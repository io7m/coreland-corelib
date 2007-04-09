#include "chashtable.h"
#include "str.h"

int cht_deletes(struct chashtable *ch, const void *key)
{
  return cht_deleteb(ch, key, str_len(key));
}
