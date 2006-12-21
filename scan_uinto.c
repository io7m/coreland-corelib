#include "scan.h"

unsigned int scan_uinto(const char *str, unsigned int *ul)
{
  return scan_ulongo(str, (unsigned long *) ul);
}

