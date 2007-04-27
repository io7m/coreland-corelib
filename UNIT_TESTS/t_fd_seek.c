/* DO NOT EDIT THIS LINE - required for test */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../fd_seek.h"
#include "t_assert.h"

void readchar(int fd, char *c)
{
  static unsigned long n = 0;
  int r;
  r = read(fd, c, 1);
  test_assert(r != -1);
  test_assert(r != 0);
  ++n;
}

int main(void)
{
  fd_seek_int tmp;
  struct stat sb;
  int fd;
  char c;

  fd = open("t_fd_seek.c", O_RDONLY);
  test_assert(fd != -1);

  test_assert(fd_seek_start(fd) == 0);

  tmp = 4;
  test_assert(fd_seek_cur(fd, tmp) == tmp);
  readchar(fd, &c);
  test_assert(c == 'O');

  test_assert(fd_seek_start(fd) == 0);
  tmp = 8;
  test_assert(fd_seek_pos(fd, tmp) == tmp);
  readchar(fd, &c);
  test_assert(c == 'T');
 
  test_assert(fstat(fd, &sb) != -1);
  test_assert(fd_seek_end(fd) == sb.st_size);
 
  test_assert(fd_seek_cur(fd, -2) == sb.st_size - 2);
  readchar(fd, &c);
  test_assert(c == '/');
 
  test_assert(close(fd) != -1);
  return 0;
}

/* DO NOT EDIT THIS LINE - required for test */
