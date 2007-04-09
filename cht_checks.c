#include "chashtable.h"

int cht_checks(const struct chashtable *ch, const void *key)
{
  return cht_gets(ch, key, 0, 0);
}
