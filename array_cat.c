#include "array.h"

int array_cat(struct array *a, const void *dat)
{
  return array_catb(a, dat, a->es);
}
