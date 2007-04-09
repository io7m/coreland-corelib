#include "alloc.h"
#include "chashtable.h"

int cht_init(struct chashtable *ch)
{
  struct cht_node *t1 = 0;
  struct cht_node *t2 = 0;

  t1 = alloc_zero(2 * sizeof(struct cht_node));
  if (!t1) goto FAIL;
  t2 = alloc_zero(2 * sizeof(struct cht_node));
  if (!t2) goto FAIL;

  ch->mask = 1;
  ch->table1 = t1;
  ch->table2 = t2;
  return 1;

  FAIL:
  if (t1) dealloc(t1);
  if (t2) dealloc(t2);
  return 0;
}
