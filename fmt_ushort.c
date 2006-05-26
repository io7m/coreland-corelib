#include "fmt.h"

unsigned int fmt_ushort(char *s, unsigned short ui)
{
  return fmt_ulong(s, (unsigned long) ui);
}

unsigned int fmt_ushortx(char *s, unsigned short uix)
{
  return fmt_ulongx(s, (unsigned long) uix);
}

unsigned int fmt_ushorto(char *s, unsigned short uio)
{
  return fmt_ulongo(s, (unsigned long) uio);
}
