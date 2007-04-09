#include <stdio.h>
#include <unistd.h>
#include "../open.h"
#include "t_assert.h"

int main(void)
{
  int fd;

  fd = open_ro("./t_open.c");
  test_assert(fd != -1);
  test_assert(close(fd) != -1);

  fd = open_creat("./abcxyz.tmp");
  test_assert(fd != -1);
  test_assert(close(fd) != -1);

  fd = open_append("./abcxyz.tmp");
  test_assert(fd != -1);
  test_assert(close(fd) != -1);
  test_assert(unlink("./abcxyz.tmp") != -1);
  
  fd = open_trunc("./abcxyz.tmp");
  test_assert(fd != -1);
  test_assert(close(fd) != -1);
  fd = open_excl("./abcxyz.tmp");
  test_assert(fd == -1);

  fd = open_rw("./abcxyz.tmp");
  test_assert(fd != -1);
  test_assert(close(fd) != -1);
  fd = open_wo("./abcxyz.tmp");
  test_assert(fd != -1);
  test_assert(close(fd) != -1);

  test_assert(unlink("./abcxyz.tmp") != -1);
  return 0;
}
