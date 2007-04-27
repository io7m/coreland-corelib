#include "fd_seek.h"

long fd_seek_cur(int fd, long pos)
{
  return lseek(fd, pos, 1);
}
