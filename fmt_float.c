#include <float.h>
#include "fmt.h"

unsigned int fmt_float(char *str, float f, unsigned int prec)
{
  unsigned int len = 0;

  if (!prec || prec > FLT_DIG) prec = FLT_DIG;

  return len;
}
