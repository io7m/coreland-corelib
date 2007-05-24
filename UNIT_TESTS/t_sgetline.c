#include <fcntl.h>
#include <stdio.h>
#include "../buffer.h"
#include "../close.h"
#include "../read.h"
#include "../sgetline.h"
#include "t_assert.h"

static char fbuf[BUFFER_INSIZE];
static char linebuf[1024]; /* very short line buffer */
static struct buffer inbuf;
static struct sgetline sg;

int main(void)
{
  int fd;
  int r;
  int toolong = 0;

  fd = open("./t_sgetline.txt", O_RDONLY);
  test_assert(fd != -1);

  buffer_init(&inbuf, (buffer_op) read, fd, fbuf, sizeof(fbuf));
  sgetline_initbuf(&sg, linebuf, sizeof(linebuf), &inbuf);

  for (;;) {
    r = sgetline_get(&sg);
    switch (r) {
      case 0: goto END; break;
      case 1: break;
      case -1: perror("read"); return 2; break;
      case -2: toolong = 1; break;
      default: break;
    }
    if (toolong) {
      printf("skipped line %lu, line too long\n", sg.line_nr);
      toolong = 0;
      continue;
    } 
    printf("%lu %lu %s\n", sg.line_nr, sgetline_size(&sg), sgetline_data(&sg));
  }

  END:

  test_assert(close(fd) != -1);
  return 0;
}
