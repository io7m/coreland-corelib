#include "fmt.h"

unsigned int fmt_ushort(char *str, unsigned short ui)
{
  return fmt_ulong(str, (unsigned long) ui);
}

