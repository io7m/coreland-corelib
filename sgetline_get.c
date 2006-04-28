#include "bin.h"
#include "buffer.h"
#include "sgetline.h"
#include "sstring.h"

static int sub_sgetline_get(sgetline *s);

int sgetline_get(sgetline *s)
{
  int r;

  for (;;) {
    r = sub_sgetline_get(s);
    if ((s->len == 0) && (r > 0)) continue;
    return r;
  }
}

static int sub_sgetline_get(sgetline *s)
{
  int n;
  int i;
  char *x;
  buffer *b;
  sstring sb;
  int sep = '\n';

  b = &(s->b);
  s->len = 0;

  sstring_init(&sb, s->s, s->a);

  for (;;) {
    n = buffer_feed(b);
    if (n == 0) return 0;
    if (n == -1) return -1;
    x = buffer_peek(b);
    i = bin_chr(x, n, sep);
    if (i == -1) {
      if ((sb.len + n) >= s->a) {
        buffer_seek(b, n);
        return -2; /* line too long */
      }
      sstring_catb(&sb, x, n);
      buffer_seek(b, n);
      continue;
    }
    sstring_catb(&sb, x, i);
    sstring_0(&sb);
    if (sb.len == s->a) return -2;
    s->len = sb.len;
    ++s->line_nr;
 
    buffer_seek(b, i + 1); /* remove newline */

    return 1;
  }
}
