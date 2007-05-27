#include "scan.h"

unsigned int scan_ucharo(const char *s, unsigned char *up)
{
  unsigned long ul;
  unsigned int len;
  unsigned char uc;

  len = scan_ulongo(s, &ul);
  if (!len) return 0;

  uc = (unsigned char) ul; *up = uc;
  return len;
}

unsigned int scan_charo(const char *s, char *p)
{
  long lo;
  unsigned int len;
  char c;

  len = scan_longo(s, &lo);
  if (!len) return 0;

  c = (char) lo; *p = c;
  return len;
}

