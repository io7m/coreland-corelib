#include "scan.h"

unsigned int scan_ucharx(const char *str, unsigned char *ul)
{
  return scan_ulongx(str, (unsigned long *) ul);
}

