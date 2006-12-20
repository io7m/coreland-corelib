#include "sarray.h"

void sarray_trunc(struct sarray *sa)
{
  sarray_chop(sa, 0);
}
