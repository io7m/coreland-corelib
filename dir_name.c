#include "bin.h"
#include "dir_name.h"
#include "str.h"

static char path[DIR_NAME_MAX];

int dir_name_r(const char *file, char *buf, unsigned long buf_len)
{
  unsigned int len;
  char *s;

  len = str_len(file);
  if (len >= buf_len) return 0;

  bin_zero(buf, buf_len);
  bin_copy(file, buf, len);
  s = buf;

  if (!len) {
    buf[0] = '.';
    buf[1] = 0;
    return 1;
  }

  for (;;) {
    if (!len) break;
    if (s[len - 1] == '/')
      --len;
    else
      break;
  }

  if (!len) {
    buf[0] = '/';
    buf[1] = 0;
    return 1;
  }

  s[len] = 0;

  for (;;) {
    if (!len) break;
    if (s[len] == '/') break;
    --len;
  }

  if (!len) {
    buf[0] = '.';
    buf[1] = 0;
    return 1;
  }

  for (;;) {
    if (!len) break;
    if (s[len] != '/') break;
    --len;
  }

  s[++len] = 0;
  
  if (!len) {
    buf[0] = '/';
    buf[1] = 0;
    return 1;
  }

  return 1;
}

int dir_name(const char *file, char **out)
{
  if (!dir_name_r(file, path, sizeof(path))) return 0;
  *out = path;
  return 1;
}
