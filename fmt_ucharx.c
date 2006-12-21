#include "fmt.h"

unsigned int fmt_ucharx(char *str, unsigned char uix)
{
  return fmt_ulongx(str, (unsigned long) uix);
}
