#include <fcntl.h>
#include <stdio.h>
#include "../buffer.h"
#include "../close.h"
#include "../read.h"
#include "../dgetline.h"
#include "t_assert.h"

static char fbuf[BUFFER_INSIZE];

int main(void)
{
  struct dgetline dg;
  int fd;
  int r;

  fd = open("./t_dgetline.txt", O_RDONLY);
  test_assert(fd != -1);
  test_assert(dgetline_init(&dg, (buffer_op) read, fd, fbuf, sizeof(fbuf)) != 0);

  for (;;) {
    r = dgetline_get(&dg);
    switch (r) {
      case 0: goto END; break;
      case 1: break;
      case -1: perror("read"); return 2; break;
      default: break;
    }
    printf("%lu %lu %s\n",
            dgetline_linenum(&dg),
            dgetline_size(&dg),
            dgetline_data(&dg));
  }

  END:
  test_assert(close(fd) != -1);
  return 0;
}
