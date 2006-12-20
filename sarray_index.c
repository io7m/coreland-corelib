#include "sarray.h"

void *sarray_index(struct sarray *sa, unsigned long ind)
{
  if (ind >= sa->u) return 0;
  return sa->x + (ind * sa->es);
}
