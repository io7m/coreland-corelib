#include "fmt.h"

unsigned int fmt_ushortb(char *str, unsigned short us)
{
  return fmt_ulongb(str, (unsigned long) us);
}

unsigned int fmt_shortb(char *str, short s)
{
  return fmt_longb(str, (long) s);
}
