#include "sarray.h"

void *sarray_data(const struct sarray *sa)
{
  return sa->x;
}
