#include "fmt.h"

unsigned int fmt_uintb(char *str, unsigned int uib)
{
  return fmt_ulongb(str, (unsigned long) uib);
}

unsigned int fmt_intb(char *str, int ib)
{
  return fmt_longb(str, (long) ib);
}
