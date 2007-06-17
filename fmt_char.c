#include "fmt.h"

unsigned int fmt_uchar(char *str, unsigned char uc)
{
  return fmt_ulong(str, (unsigned long) uc);
}

unsigned int fmt_char(char *str, signed char c)
{
  return fmt_long(str, (long) c);
}
