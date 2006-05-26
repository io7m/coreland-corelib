#include "scan.h"

unsigned int scan_uintx(const char *s, unsigned int *ul)
{
  return scan_ulongx(s, (unsigned long *) ul);
}

