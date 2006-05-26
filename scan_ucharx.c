#include "scan.h"

unsigned int scan_ucharx(const char *s, unsigned char *ul)
{
  return scan_ulongx(s, (unsigned long *) ul);
}

