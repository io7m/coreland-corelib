#include "scan.h"

unsigned int scan_uint(const char *s, unsigned int *ul)
{
  return scan_ulong(s, (unsigned long *) ul);
}

unsigned int scan_uintx(const char *s, unsigned int *ul)
{
  return scan_ulongx(s, (unsigned long *) ul);
}

unsigned int scan_uinto(const char *s, unsigned int *ul)
{
  return scan_ulongo(s, (unsigned long *) ul);
}
