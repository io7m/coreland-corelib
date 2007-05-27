#include "fmt.h"

unsigned int fmt_ushortx(char *str, unsigned short us)
{
  return fmt_ulongx(str, (unsigned long) us);
}

unsigned int fmt_shortx(char *str, short s)
{
  return fmt_longx(str, (long) s);
}
