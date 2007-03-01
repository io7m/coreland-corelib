#include "int64.h"
#include "seek.h"

int64 seek_pos(int fd, int64 pos)
{
  return lseek(fd, pos, _SEEK_SET);
}
