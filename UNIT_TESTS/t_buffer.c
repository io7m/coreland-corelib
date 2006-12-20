#include "../buffer.h"
#include <stdio.h>
#include <unistd.h>

static char pwbuf[1024];
static char prbuf[1024];
static struct buffer buffer_pw;
static struct buffer buffer_pr;

int main()
{
  static char buf[16];
  static char buf2[16];
  int pfds1[2];
  int pfds2[2];
  int r;
  const char *str = "ABCD1234";

  if (pipe(pfds1) == -1) { perror("pipe"); return 2; }
  if (pipe(pfds2) == -1) { perror("pipe"); return 2; }

  buffer_init(&buffer_pr, (buffer_op) read, pfds1[0], prbuf, sizeof(prbuf));
  buffer_init(&buffer_pw, (buffer_op) write, pfds1[1], pwbuf, sizeof(pwbuf));
 
  if (write(pfds1[1], str, 8) == -1) { perror("write"); return 2; }
  if (read(pfds1[0], buf, 8) == -1)  { perror("read"); return 2; }
  if (buf[0] != 'A') { printf("fail: buf[0] == %c\n", buf[0]); return 1; }

  r = buffer_puts(&buffer_pw, str);
  if (r == -1) { perror("buffer_puts"); return 1; }
 
  r = buffer_flush(&buffer_pw);
  if (r == -1) { perror("buffer_flush"); return 1; }

  r = buffer_get(&buffer_pr, buf2, 8);
  if (r == -1) { perror("buffer_get"); return 1; }

  if (buf2[0] != 'A') { printf("fail: buf2[0] == %c\n", buf2[0]); return 1; }
  if (buf2[1] != 'B') { printf("fail: buf2[1] == %c\n", buf2[1]); return 1; }
  if (buf2[2] != 'C') { printf("fail: buf2[2] == %c\n", buf2[2]); return 1; }
  if (buf2[3] != 'D') { printf("fail: buf2[3] == %c\n", buf2[3]); return 1; }

  buffer_init(&buffer_pr, (buffer_op) read, pfds2[0], prbuf, sizeof(prbuf));
  buffer_init(&buffer_pw, (buffer_op) write, pfds1[1], pwbuf, sizeof(pwbuf));

  if (write(pfds2[1], "WXYZ1234", 8) == -1) { perror("write"); return 2; }
  if (close(pfds2[1]) == -1) { perror("close"); return 2; }
  if (buffer_copy(&buffer_pw, &buffer_pr)) {
    perror("buffer_copy"); return 2;
  }

  return 0;
}
