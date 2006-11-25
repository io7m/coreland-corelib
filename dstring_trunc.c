#include "dstring.h"

void dstring_trunc(struct dstring *d)
{
  dstring_chop(d, 0);
}
