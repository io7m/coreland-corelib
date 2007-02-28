#include "scan.h"

unsigned int scan_uint(const char *s, unsigned int *up)
{
  unsigned long ul;
  unsigned int ui;
  unsigned int len;

  len = scan_ulong(s, &ul); ui = (unsigned int) ul; *up = ul;
  return len;
}
