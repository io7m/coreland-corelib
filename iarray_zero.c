#include "iarray.h"

void iarray_zero(struct iarray *ia)
{
  ia->a = 0;
  ia->u = 0;
  ia->head = 0;
  ia->tail = 0;
}
