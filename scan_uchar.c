#include "scan.h"

unsigned int scan_uchar(const char *s, unsigned char *ul)
{
  return scan_ulong(s, (unsigned long *) ul);
}

unsigned int scan_ucharx(const char *s, unsigned char *ul)
{
  return scan_ulongx(s, (unsigned long *) ul);
}

unsigned int scan_ucharo(const char *s, unsigned char *ul)
{
  return scan_ulongo(s, (unsigned long *) ul);
}
