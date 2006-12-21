#include "scan.h"

unsigned int scan_ucharo(const char *str, unsigned char *ul)
{
  return scan_ulongo(str, (unsigned long *) ul);
}
