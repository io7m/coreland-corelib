#include "scan.h"

/*
  skip over spaces, tabs
 */

unsigned int scan_space(const char *s)
{
  return scan_chars(s, " \t");
}
