#include "int64.h"
#include "seek.h"

int64 seek_start(int fd)
{
  return lseek(fd, 0, SET);
}
