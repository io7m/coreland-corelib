#include "alloc.h"
#include "array.h"
#include "bin.h"

int array_catb(struct array *a, const void *dat, unsigned long dsize)
{
  unsigned long new_alloc;
  unsigned long new_used;
  unsigned long cur_alloc;
  unsigned long cur_used;

  cur_used = a->u * a->es;
  cur_alloc = a->a * a->es;

  if (!dsize) return 0;
  if (cur_alloc / a->a != a->es) return 0; /* check wrap */

  /* need to reallocate? */
  new_alloc = cur_alloc + (a->es * ARRAY_OVERALLOC) + dsize;
  new_used = cur_used + dsize;
  if (cur_alloc + dsize < cur_alloc) return 0; /* check wrap */
  if (new_alloc < cur_alloc) return 0; /* check wrap */
  if (new_used >= cur_alloc) {
    if (!alloc_re(&a->x, cur_alloc, new_alloc)) return 0;
    cur_alloc = new_alloc;
  }

  bin_copy(dat, ((char *) a->x) + cur_used, dsize);
  cur_used += dsize;

  a->a = cur_alloc / a->es;
  a->u = cur_used / a->es;
  return 1;
}
