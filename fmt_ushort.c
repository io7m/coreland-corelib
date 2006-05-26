#include "fmt.h"

unsigned int fmt_ushort(char *s, unsigned short ui)
{
  return fmt_ulong(s, (unsigned long) ui);
}

