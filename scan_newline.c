#include "scan.h"

unsigned int scan_newline(const char *s)
{
  return scan_charset(s, "\n");
}
