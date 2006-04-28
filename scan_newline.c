#include "scan.h"

/*
 if newline return 1, if not return 0
 */

unsigned int scan_newline(const char *s)
{
  return scan_chars(s, "\n");
}
