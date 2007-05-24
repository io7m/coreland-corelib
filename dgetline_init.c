#include "buffer.h"
#include "dgetline.h"
#include "dstring.h"
#include "read.h"

int dgetline_init(struct dgetline *dg, int fd, char *buf, unsigned long len)
{
  dg->line_nr = 0;
  buffer_init(&dg->b, (buffer_op) read, fd, buf, len);
  return (dstring_init(&dg->d, 1) != 0);
}
