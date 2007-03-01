#include "int64.h"
#include "seek.h"

int64 seek_end(int fd)
{
  return lseek(fd, 0, _SEEK_END);
}
