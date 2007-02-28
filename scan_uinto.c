#include "scan.h"

unsigned int scan_uinto(const char *s, unsigned int *up)
{
  unsigned long ul;
  unsigned int ui;
  unsigned int len;

  len = scan_ulongo(s, &ul); ui = (unsigned int) ul; *up = ul;
  return len;
}
