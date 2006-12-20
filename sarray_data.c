#include "sarray.h"

const void *sarray_data(const struct sarray *sa)
{
  return sa->x;
}
