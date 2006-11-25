#include "bin.h"
#include "buffer.h"
#include "sgetline.h"
#include "sstring.h"

static int sub_sgetline_get(struct sgetline *s);

int sgetline_get(struct sgetline *s)
{
  return sub_sgetline_get(s);
}

static int sub_sgetline_get(struct sgetline *s)
{
  long n;
  char *x;
  struct buffer *b;
  struct sstring sb;
  int sep = '\n';
  unsigned long pos;

  b = &(s->b);
  s->len = 0;

  sstring_init(&sb, s->s, s->a);

  for (;;) {
    n = buffer_feed(b);
    if (n == 0) return 0;
    if (n == -1) return -1;
    x = buffer_peek(b);
    if (!bin_char(x, n, sep, &pos)) {
      if ((sb.len + n) >= s->a) {
        buffer_seek(b, n);
        return -2; /* line too long */
      }
      sstring_catb(&sb, x, n);
      buffer_seek(b, n);
      continue;
    }
    sstring_catb(&sb, x, pos);
    sstring_0(&sb);
    if (sb.len == s->a) return -2;
    s->len = sb.len;
    ++s->line_nr;
 
    buffer_seek(b, pos + 1); /* remove newline */
    return 1;
  }
}
