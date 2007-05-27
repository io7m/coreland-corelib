#include "fmt.h"

unsigned int fmt_uintx(char *str, unsigned int uix)
{
  return fmt_ulongx(str, (unsigned long) uix);
}

unsigned int fmt_intx(char *str, int ix)
{
  return fmt_longx(str, (long) ix);
}
