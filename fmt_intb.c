#include "fmt.h"

unsigned int fmt_uintb(char *str, unsigned int uib)
{
  return fmt_ulongb(str, (unsigned long) uib);
}

