#include "fmt.h"

unsigned int fmt_ushortb(char *str, unsigned short uib)
{
  return fmt_ulongb(str, (unsigned long) uib);
}

