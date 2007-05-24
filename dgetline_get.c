#include "bin.h"
#include "buffer.h"
#include "dstring.h"
#include "dgetline.h"

static int sub_dgetline_get(struct dgetline *d);

int dgetline_get(struct dgetline *d)
{
  return sub_dgetline_get(d);
}

static int sub_dgetline_get(struct dgetline *dg)
{
  long n;
  char *x;
  struct buffer *b;
  struct dstring *ds;
  unsigned long pos;

  b = &dg->b;
  ds = &dg->d;

  dstring_trunc(&dg->d);
  for (;;) {
    n = buffer_feed(b);
    if (n == 0) return 0;
    if (n == -1) return -1;
    x = buffer_peek(b);
    if (!bin_char(x, n, '\n', &pos)) {
      if (!dstring_catb(ds, x, n)) return -1;
      buffer_seek(b, n);
      continue;
    }
    if (!dstring_catb(ds, x, pos)) return -1;
    dstring_0(ds);
    ++dg->line_nr;
    buffer_seek(b, pos + 1); /* remove newline */
    return 1;
  }
}
