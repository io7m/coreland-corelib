#include "fmt.h"

unsigned int fmt_ushorto(char *str, unsigned short us)
{
  return fmt_ulongo(str, (unsigned long) us);
}

unsigned int fmt_shorto(char *str, short s)
{
  return fmt_longo(str, (long) s);
}
