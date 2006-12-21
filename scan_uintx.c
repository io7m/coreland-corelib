#include "scan.h"

unsigned int scan_uintx(const char *str, unsigned int *ul)
{
  return scan_ulongx(str, (unsigned long *) ul);
}

