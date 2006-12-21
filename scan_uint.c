#include "scan.h"

unsigned int scan_uint(const char *str, unsigned int *ul)
{
  return scan_ulong(str, (unsigned long *) ul);
}

