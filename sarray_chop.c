#include "sarray.h"

void sarray_chop(struct sarray *sa, unsigned long ind)
{
  if (sa->u <= ind) return;
  sa->u = ind;
}
