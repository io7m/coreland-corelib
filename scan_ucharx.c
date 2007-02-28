#include "scan.h"

unsigned int scan_ucharx(const char *s, unsigned char *up)
{
  unsigned long ul;
  unsigned char uc;
  unsigned int len;

  len = scan_ulongx(s, &ul); uc = (unsigned char) ul; *up = ul;
  return len;
}
