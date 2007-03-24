#include "../buffer.h"
#include <stdio.h>
#include <unistd.h>

static char pwbuf[256];
static char prbuf[256];
static struct buffer buffer_pw;
static struct buffer buffer_pr;

int main(void)
{
  int pfds1[2];
  long r;

  if (pipe(pfds1) == -1) { perror("pipe"); return 2; }

  buffer_init(&buffer_pr, (buffer_op) read, pfds1[0], prbuf, sizeof(prbuf));
  buffer_init(&buffer_pw, (buffer_op) write, pfds1[1], pwbuf, sizeof(pwbuf));
 
  if (write(pfds1[1], prbuf, 128) == -1) { perror("write"); return 2; }

  r = buffer_feed(&buffer_pr);
  if (r == -1) { perror("read"); return 2; }
 
  buffer_seek(&buffer_pr, r);
  if (buffer_pr.pos != 0) {
    printf("fail: unexpected pos value %lu\n", buffer_pr.pos);
    return 1;
  }

  /* try to seek too much */
  buffer_seek(&buffer_pr, 1);
  if (buffer_pr.pos != 0) {
    printf("fail: unexpected pos value %lu\n", buffer_pr.pos);
    return 1;
  }

  return 0;
}
