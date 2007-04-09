#include <stdio.h>
#include <unistd.h>
#include "../buffer.h"
#include "t_assert.h"

static char pwbuf[1024];
static char prbuf[1024];
static struct buffer buffer_pw;
static struct buffer buffer_pr;

int main(void)
{
  static char buf[16];
  static char buf2[16];
  int pfds1[2];
  int pfds2[2];
  const char *str = "ABCD1234";

  test_assert(pipe(pfds1) != -1);
  test_assert(pipe(pfds2) != -1);

  buffer_init(&buffer_pr, (buffer_op) read, pfds1[0], prbuf, sizeof(prbuf));
  buffer_init(&buffer_pw, (buffer_op) write, pfds1[1], pwbuf, sizeof(pwbuf));
 
  test_assert(write(pfds1[1], str, 8) == 8);
  test_assert(read(pfds1[0], buf, 8) == 8);
  test_assert(buf[0] == 'A');
  test_assert(buf[1] == 'B');
  test_assert(buf[2] == 'C');
  test_assert(buf[3] == 'D');
  test_assert(buf[4] == '1');
  test_assert(buf[5] == '2');
  test_assert(buf[6] == '3');
  test_assert(buf[7] == '4');

  test_assert(buffer_puts(&buffer_pw, str) != -1);
  test_assert(buffer_flush(&buffer_pw) != -1);
  test_assert(buffer_get(&buffer_pr, buf2, 8) != -1);
  test_assert(buf2[0] == 'A');
  test_assert(buf2[1] == 'B');
  test_assert(buf2[2] == 'C');
  test_assert(buf2[3] == 'D');
  test_assert(buf2[4] == '1');
  test_assert(buf2[5] == '2');
  test_assert(buf2[6] == '3');
  test_assert(buf2[7] == '4');

  buffer_init(&buffer_pr, (buffer_op) read, pfds2[0], prbuf, sizeof(prbuf));
  buffer_init(&buffer_pw, (buffer_op) write, pfds1[1], pwbuf, sizeof(pwbuf));

  test_assert(write(pfds2[1], "WXYZ1234", 8) != -1);
  test_assert(close(pfds2[1]) != -1);
  test_assert(buffer_copy(&buffer_pw, &buffer_pr) == 0);

  return 0;
}
