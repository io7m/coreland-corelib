#include <fcntl.h>
#include <stdio.h>
#include "../fd.h"
#include "t_assert.h"

int main(void)
{
  int fd0;
  int fd1;
  int fd2;
  int fd02;
  int fd03;

  fd0 = 0;
  fd1 = 1;
  fd2 = 2;
  fd02 = 0;

  test_assert(fd_dup(fd0, fd02) == 0);

  fd02 = 3;
  test_assert(fd_dup(fd0, fd02) == 1);

  fd03 = open("./t_fd.c", O_RDONLY);
  test_assert(fd03 != -1);
  fd02 = open("./t_fd.ld", O_RDONLY);
  test_assert(fd02 != -1);

  test_assert(fd_move(fd03, fd02) == 1);
  return 0;
}
