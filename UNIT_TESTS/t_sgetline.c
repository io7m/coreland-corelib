#include <fcntl.h>
#include <stdio.h>
#include "../buffer.h"
#include "../close.h"
#include "../read.h"
#include "../sgetline.h"

static char fbuf[BUFFER_INSIZE];
static char linebuf[1024]; /* very short line buffer */
static buffer inbuf;
static sgetline sg;

int main()
{
  int fd;
  int r;
  int toolong = 0;

  fd = open("./t_sgetline.txt", O_RDONLY);
  if (fd == -1) { perror("open"); return 1; }

  buffer_init(&inbuf, read, fd, fbuf, sizeof(fbuf));
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
      printf("skipped line %u, line too long\n", sg.line_nr);
      toolong = 0;
      continue;
    } 
    printf("[%u](%u): %s\n", sg.line_nr, sg.len, sg.s);
  }

  END:

  if (close(fd) == -1) perror("close");
  return 0;
}
