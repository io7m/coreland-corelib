#include "close.h"
#include "fd.h"
#include <fcntl.h>

int fd_dup(int src, int dst)
{
  if (src == dst) return 0;
  if (fcntl(src, F_GETFL, 0) == -1) return -1;
  close(dst);
  if (fcntl(src, F_DUPFD, dst) == -1) return -1;
  return 1;
}
