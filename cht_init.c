#include "alloc.h"
#include "chashtable.h"

int cht_init(struct chashtable *ch)
{
  struct cht_node *t1 = 0;
  struct cht_node *t2 = 0;
  struct cht_node *of = 0;

  t1 = alloc_zero(2 * sizeof(struct cht_node));
  if (!t1) goto FAIL;
  t2 = alloc_zero(2 * sizeof(struct cht_node));
  if (!t2) goto FAIL;
  of = alloc_zero(2 * sizeof(struct cht_node));
  if (!of) goto FAIL;

  ch->len = 2;
  ch->table1 = t1;
  ch->table2 = t2;
  ch->oflow = of;
  ch->oflow_a = 2;
  ch->oflow_len = 0;
  return 1;

  FAIL:
  if (t1) dealloc(t1);
  if (t2) dealloc(t2);
  if (of) dealloc(of);
  return 0;
}
