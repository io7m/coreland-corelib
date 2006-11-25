#include "iarray.h"

unsigned long iarray_bytes(const struct iarray *ls)
{
  struct iarray_node *ln;
  unsigned long b;

  b = 0;
  ln = ls->head;

  if (!ln) return 0;

  for (;;) {
    b += ln->len;
    if (ln->next)
      ln = ln->next;
    else
      break;
  }
  return b;
}
