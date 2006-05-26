#include "fmt.h"

unsigned int fmt_uchar(char *s, unsigned char ui)
{
  return fmt_ulong(s, (unsigned long) ui);
}

unsigned int fmt_ucharx(char *s, unsigned char uix)
{
  return fmt_ulongx(s, (unsigned long) uix);
}

unsigned int fmt_ucharo(char *s, unsigned char uio)
{
  return fmt_ulongo(s, (unsigned long) uio);
}
