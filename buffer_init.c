#include "buffer.h"

void buffer_init(buffer *b, int (*op)(int, char *, unsigned long),
                 int fd, char *s, unsigned long len)
{
  b->size = len;
  b->pos = 0;
  b->fd = fd;
  b->op = op;
  b->buf = s;
}
