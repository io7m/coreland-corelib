#include "scan.h"

unsigned int scan_uint(const char *s, unsigned int *ul)
{
  return scan_ulong(s, (unsigned long *) ul);
}

