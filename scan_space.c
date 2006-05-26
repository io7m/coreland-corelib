#include "scan.h"

unsigned int scan_whitespace(const char *s)
{
  return scan_charset(s, " \t");
}
