#include "scan.h"

unsigned int scan_ucharx(const char *s, unsigned char *up)
{
  unsigned long ul;
  unsigned int len;
  unsigned char uc;

  len = scan_ulongx(s, &ul);
  if (!len) return 0;

  uc = (unsigned char) ul; *up = uc;
  return len;
}

unsigned int scan_charx(const char *s, char *p)
{
  long lo;
  unsigned int len;
  char c;

  len = scan_longx(s, &lo);
  if (!len) return 0;

  c = (char) lo; *p = c;
  return len;
}
