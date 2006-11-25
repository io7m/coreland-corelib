#include "alloc.h"
#include "iarray.h"

int iarray_copy(struct iarray *ia, const struct iarray *ib)
{
  unsigned long ind;
  unsigned long max;
  unsigned long dlen;
  void *data;

  max = ib->u;
  if (ia->a)
    iarray_free(ia);

  if (!iarray_init(ia, max)) return 0;

  max = ib->u;
  for (ind = 0; ind < max; ++ind) {
    if (!iarray_index(ib, ind, &data, &dlen)) {
      iarray_free(ia);
      return 0;
    }
    if (!iarray_cat(ia, data, dlen)) {
      iarray_free(ia);
      return 0;
    }
  }
  return 1;
}
