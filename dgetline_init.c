#include "buffer.h"
#include "dgetline.h"
#include "dstring.h"

int dgetline_init(struct dgetline *dg, long (*op)(int, char *, unsigned long),
                  int fd, char *buf, unsigned long len)
{
  dg->line_nr = 0;
  buffer_init(&dg->b, (buffer_op) op, fd, buf, len);
  return (dstring_init(&dg->d, 1) != 0);
}

int dgetline_initbuf(struct dgetline *dg, struct buffer *b)
{
  return dgetline_init(dg, b->op, b->fd, b->buf, b->size);
}
