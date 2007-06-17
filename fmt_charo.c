#include "fmt.h"

unsigned int fmt_ucharo(char *str, unsigned char uco)
{
  return fmt_ulongo(str, (unsigned long) uco);
}

unsigned int fmt_charo(char *str, signed char co)
{
  return fmt_longo(str, (long) co);
}
