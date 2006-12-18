#include "fmt.h"

unsigned int fmt_uintb(char *s, unsigned int uib)
{
  return fmt_ulongb(s, (unsigned long) uib);
}

