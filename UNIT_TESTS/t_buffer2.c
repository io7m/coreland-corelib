#include <stdio.h>
#include <unistd.h>
#include "../buffer.h"
#include "t_assert.h"

static char pwbuf[256];
static char prbuf[256];
static struct buffer buffer_pw;
static struct buffer buffer_pr;

int main(void)
{
  int pfds1[2];
  long r;

  test_assert(pipe(pfds1) != -1);

  buffer_init(&buffer_pr, (buffer_op) read, pfds1[0], prbuf, sizeof(prbuf));
  buffer_init(&buffer_pw, (buffer_op) write, pfds1[1], pwbuf, sizeof(pwbuf));
 
  test_assert(write(pfds1[1], prbuf, 128) != -1);

  r = buffer_feed(&buffer_pr);
  test_assert(r != -1);
 
  buffer_seek(&buffer_pr, r);
  test_assert(buffer_pr.pos == 0);

  /* try to seek too much */
  buffer_seek(&buffer_pr, 1);
  test_assert(buffer_pr.pos == 0);
  return 0;
}
