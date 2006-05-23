#include "buffer.h"

void buffer_init(buffer *b, int (*op)(int, char *, unsigned int),
                 int fd, char *s, unsigned int len)
{
  b->size = len;
  b->pos = 0;
  b->fd = fd;
  b->op = op;
  b->buf = s;
}
