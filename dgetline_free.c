#include "dgetline.h"
#include "dstring.h"

void dgetline_free(struct dgetline *dg)
{
  dstring_free(&dg->d);
}
