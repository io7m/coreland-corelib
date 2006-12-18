#include "fmt.h"

unsigned int fmt_ushortb(char *s, unsigned short uib)
{
  return fmt_ulongb(s, (unsigned long) uib);
}

