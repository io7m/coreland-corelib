#include "int64.h"
#include "fd_seek.h"

int64 fd_seek_pos(int fd, int64 pos)
{
  return lseek(fd, pos, FD_SEEK_SET);
}
