#include "close.h"
#include "fd.h"

int fd_move(int src, int dst)
{
  if (src == dst) return 0;
  if (fd_dup(src, dst) == -1) return -1;
  close(src);
  return 1;
}
