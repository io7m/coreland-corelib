#include "fd_seek.h"

long fd_seek_pos(int fd, long pos)
{
  return lseek(fd, pos, FD_SEEK_SET);
}
