#include "alloc.h"
#include "bin.h"
#include "str.h"

int str_dup(const char *s, char **d)
{
  unsigned int n;
  char *x;

  n = str_len(s);
  if (!n) return 0;
  x = alloc(n + 1);
  if (!x) return 0;
  bin_copy(s, x, n);
  x[n] = 0;
  *d = x;
  return 1;
}
