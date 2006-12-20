#include "sarray.h"

void sarray_init(struct sarray *sa, void *x, unsigned long sz, unsigned int es)
{
  sa->x = x;
  sa->a = sz;
  sa->u = 0;
  sa->es = es;
}
