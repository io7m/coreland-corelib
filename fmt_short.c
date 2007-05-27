#include "fmt.h"

unsigned int fmt_ushort(char *str, unsigned short us)
{
  return fmt_ulong(str, (unsigned long) us);
}

unsigned int fmt_short(char *str, short s)
{
  return fmt_long(str, (long) s);
}
