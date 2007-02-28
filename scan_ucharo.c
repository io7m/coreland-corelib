#include "scan.h"

unsigned int scan_ucharo(const char *s, unsigned char *up)
{
  unsigned long ul;
  unsigned char uc;
  unsigned int len;

  len = scan_ulongo(s, &ul); uc = (unsigned char) ul; *up = ul;
  return len;
}
