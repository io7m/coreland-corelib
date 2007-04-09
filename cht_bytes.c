#include "chashtable.h"

unsigned long cht_bytes(const struct chashtable *ch)
{
  return ((ch->mask + 1) * 2 * sizeof(struct cht_node)) + sizeof(*ch); 
}
