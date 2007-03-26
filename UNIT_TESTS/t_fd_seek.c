/* DO NOT EDIT THIS LINE - required for test */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../fd_seek.h"
#include "../int64.h"

void readchar(int fd, char *c)
{
  static unsigned long n = 0;
  int r;
  r = read(fd, c, 1);
  if (r == -1) { perror("read"); exit(2); }
  if (r == 0) { printf("fail: %lu unexpected end of file\n", n); exit(2); }
  ++n;
}

int main(void)
{
  int fd;
  int64 s;
  char c;
  struct stat sb;

  fd = open("t_fd_seek.c", O_RDONLY);
  if (fd == -1) { perror("open"); return 2; }

  s = fd_seek_start(fd);
  if (s != 0) { printf("fail: 1 fd_seek_start: s == %ld\n", s); return 1; }

  s = fd_seek_cur(fd, 4);
  if (s != 4) { printf("fail: 2 fd_seek_cur: s == %ld\n", s); return 1; }
  readchar(fd, &c);
  if (c != 'O') { printf("fail: 3 fd_seek_cur: c == %c\n", c); return 1; }

  s = fd_seek_start(fd);
  if (s != 0) { printf("fail: 4 fd_seek_start: s == %ld\n", s); return 1; }

  s = fd_seek_pos(fd, 8);
  if (s != 8) { printf("fail: 5 fd_seek_pos: s == %ld\n", s); return 1; }
  readchar(fd, &c);
  if (c != 'T') { printf("fail: 6 fd_seek_pos: c == %c\n", c); return 1; }
 
  if (fstat(fd, &sb) == -1) { perror("fstat"); return 2; }
  s = fd_seek_end(fd);
  if (s != sb.st_size) {
    printf("fail: 7 fd_seek_end: s == %ld expected %ld\n", s, (sb.st_size));
    return 1;
  }
 
  s = fd_seek_cur(fd, -2);
  if (s != (sb.st_size - 2)) {
    printf("fail: 9 fd_seek_cur: s == %ld expected %ld\n", s, (sb.st_size - 2));
    return 1;
  }
  readchar(fd, &c);
  if (c != '/') { printf("fail: 10 fd_seek_cur: c == %c\n", c); return 1; }
 
  if (close(fd) == -1) perror("close");
  return 0;
}

/* DO NOT EDIT THIS LINE - required for test */
