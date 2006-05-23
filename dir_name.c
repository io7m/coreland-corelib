#include "bin.h"
#include "dir_name.h"
#include "str.h"

static char path[DIR_NAME_MAX];

int dir_name(const char *file, char **out)
{
  unsigned int len;
  char *s;

  len = str_len(file);

  if (!len) return 0;
  if (len >= DIR_NAME_MAX) return 0;

  bin_copy(file, path, len);
  s = path;

  for (;;) {
    if (!len) break;
    if (s[len - 1] == '/')
      --len;
    else
      break;
  }

  if (!len) {
    path[0] = '/';
    path[1] = 0;
    *out = path;
    return 1;
  }

  s[len] = 0;

  for (;;) {
    if (!len) break;
    if (s[len] == '/') break;
    --len;
  }

  if (!len) {
    path[0] = '.';
    path[1] = 0;
    *out = path;
    return 1;
  }

  for (;;) {
    if (!len) break;
    if (s[len] != '/') break;
    --len;
  }

  s[++len] = 0;
  
  if (!len) {
    path[0] = '/';
    path[1] = 0;
    *out = path;
    return 1;
  }

  *out = s;
  return 1;
}
