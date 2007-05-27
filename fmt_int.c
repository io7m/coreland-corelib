#include "fmt.h"

unsigned int fmt_uint(char *str, unsigned int ui)
{
  return fmt_ulong(str, (unsigned long) ui);
}

unsigned int fmt_int(char *str, int i)
{
  return fmt_long(str, (long) i);
}
