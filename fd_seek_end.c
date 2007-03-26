#include "int64.h"
#include "fd_seek.h"

int64 fd_seek_end(int fd)
{
  return lseek(fd, 0, FD_SEEK_END);
}
