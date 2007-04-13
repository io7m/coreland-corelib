#include "chashtable.h"

unsigned long cht_bytes(const struct chashtable *ch)
{
  return (ch->len * 2 * sizeof(struct cht_node)) +
         (ch->oflow_a * sizeof(struct cht_node)); 
}
