#include "buffer.h"
#include "uint32.h"

void buffer_init(buffer *b, int (*op)(int, char *, unsigned int),
                 int fd, char *s, uint32 len)
{
  b->size = len;
  b->pos = 0;
  b->fd = fd;
  b->op = op;
  b->buf = s;
}
