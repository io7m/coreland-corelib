#include <sys/types.h>
#include <sys/stat.h>
#include "bin.h"
#include "error.h"
#include "rmkdir.h"
#include "str.h"

int rmkdir(const char *dir, unsigned int perm)
{
  char pbuf[RMKDIR_MAX];
  unsigned long len;
  unsigned long pos;
  unsigned long buflen;
  unsigned long bufpos;
  int end;
  const char *ptr;

  buflen = RMKDIR_MAX;
  bufpos = 0;
  end = 0;
  len = str_len(dir);
  ptr = dir;

  if (len >= RMKDIR_MAX) { errno = error_nametoolong; return -1; }

  for (;;) {
    if (!len) break;
    if (!str_char(ptr, '/', &pos)) { pos = len; end = 1; }
    if (buflen <= pos + 1) break;
    bin_copy(ptr, pbuf + bufpos, pos);
    bufpos += pos;
    buflen -= pos;
    pbuf[bufpos] = '/';
    ++bufpos;
    --buflen;
    pbuf[bufpos] = 0;
    if (mkdir(pbuf, perm) == -1) {
      if (!end) {
        if (errno != error_exist && errno != error_isdir) return -1;
      } else
        return -1;
    }
    ptr += pos;
    len -= pos;
    if (len) {
      ++ptr;
      --len;
      if (!len) break;
    }
  }
  return 0;
}
