#include "scan.h"

unsigned int scan_ucharo(const char *s, unsigned char *ul)
{
  return scan_ulongo(s, (unsigned long *) ul);
}
