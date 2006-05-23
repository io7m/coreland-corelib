#include "bin.h"
#include "base_name.h"
#include "str.h"

static char path[BASE_NAME_MAX];

int base_name(const char *dir, char **out)
{
  const char *s;
  const char *t;
  const char *u;
  unsigned int len;
  unsigned int nlen;

  len = str_len(dir); 

  if (!len) {
    path[0] = '.';
    path[1] = 0;
    *out = path;
    return 1;
  }

  if (len >= BASE_NAME_MAX) return 0;

  s = dir;
  t = s;

  t = s + (len - 1);
  while ((t > s) && (t[0] == '/')) --t;

  if ((t == s) && (t[0] == '/')) {
    path[0] = '/';
    path[1] = 0;
    *out = path;
    return 1;
  }

  u = t;
  while ((u > s) && (*(u - 1) != '/')) --u;

  nlen = (t - u) + 1;
  bin_copy(u, path, nlen);
  path[nlen] = 0;

  *out = path;
  return 1;
}
