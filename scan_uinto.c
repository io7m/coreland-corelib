#include "scan.h"

unsigned int scan_uinto(const char *s, unsigned int *ul)
{
  return scan_ulongo(s, (unsigned long *) ul);
}

