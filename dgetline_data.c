#include "dgetline.h"
#include "dstring.h"

const char *dgetline_data(const struct dgetline *dg)
{
  return dstring_data(&dg->d);
}
