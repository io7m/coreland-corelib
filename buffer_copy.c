#include "buffer.h"

int buffer_copy(buffer *to, buffer *from)
{
  int r;
  int w;
  char *x;

  for (;;) {
    r = buffer_feed(from);
    if (r == 0) break;
    if (r == -1) return -1;
    x = buffer_peek(from);
    w = buffer_put(to, x, r);
    if (w == -1) return -2;
    buffer_seek(from, r);
  }
  if (buffer_flush(to) == -1) return -2;
  return 0;
}
