#include "fmt.h"

unsigned int fmt_ucharx(char *s, unsigned char uix)
{
  return fmt_ulongx(s, (unsigned long) uix);
}


