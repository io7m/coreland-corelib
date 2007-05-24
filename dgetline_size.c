#include "dgetline.h"
#include "dstring.h"

unsigned long dgetline_size(const struct dgetline *dg)
{
  return dstring_size(&dg->d);
}
