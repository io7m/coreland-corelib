#include "int64.h"
#include "seek.h"

int64 seek_cur(int fd, int64 pos)
{
  return lseek(fd, pos, 1);
}
