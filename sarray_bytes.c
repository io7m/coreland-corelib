#include "sarray.h"

unsigned long sarray_bytes(const struct sarray *sa)
{
  return sa->u * sa->es;
}
