#include "sgetline.h"

unsigned long sgetline_linenum(const struct sgetline *sg)
{
  return sg->line_nr;
}
