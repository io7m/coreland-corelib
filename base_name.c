#include "bin.h"
#include "base_name.h"
#include "str.h"

static char path[BASE_NAME_MAX];

int base_name_r(const char *dir, char *buf, unsigned long buf_len)
{
  const char *s;
  const char *t;
  const char *u;
  unsigned int len;
  unsigned int nlen;

  len = str_len(dir); 

  if (!len) {
    buf[0] = '.';
    buf[1] = 0;
    return 1;
  }
  if (len >= buf_len) return 0;

  s = dir;
  t = s + (len - 1);
  while ((t > s) && (t[0] == '/')) --t;

  if ((t == s) && (t[0] == '/')) {
    buf[0] = '/';
    buf[1] = 0;
    return 1;
  }

  u = t;
  while ((u > s) && (*(u - 1) != '/')) --u;

  nlen = (t - u) + 1;
  bin_copy(u, buf, nlen);
  buf[nlen] = 0;

  return 1;
}

int base_name(const char *dir, char **out)
{
  if (!base_name_r(dir, path, sizeof(path))) return 0;
  *out = path;
  return 1;
}
