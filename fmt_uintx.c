#include "fmt.h"

unsigned int fmt_uintx(char *s, unsigned int uix)
{
  return fmt_ulongx(s, (unsigned long) uix);
}

