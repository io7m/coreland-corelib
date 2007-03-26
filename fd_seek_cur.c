#include "int64.h"
#include "fd_seek.h"

int64 fd_seek_cur(int fd, int64 pos)
{
  return lseek(fd, pos, 1);
}
