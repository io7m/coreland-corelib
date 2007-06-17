#include "fmt.h"

unsigned int fmt_ucharx(char *str, unsigned char ucx)
{
  return fmt_ulongx(str, (unsigned long) ucx);
}

unsigned int fmt_charx(char *str, signed char cx)
{
  return fmt_longx(str, (long) cx);
}
