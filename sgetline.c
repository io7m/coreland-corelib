#include "sgetline.h"

void sgetline_init(sgetline *s,
                   char *sbuf,
                   unsigned long slen,
                   char *bbuf,
                   unsigned long blen,
                   long (*op)(int, char *, unsigned long),
                   int fd)
{
  s->s = sbuf;
  s->len = 0;
  s->line_nr = 0;
  s->a = slen;
  s->b.buf = bbuf;
  s->b.fd = fd;
  s->b.op = op;
  s->b.size = blen;
  s->b.pos = 0;
}

void sgetline_initbuf(sgetline *s, char *sbuf, unsigned long slen, buffer *b)
{
  s->s = sbuf;
  s->len = 0;
  s->line_nr = 0;
  s->a = slen;
  s->b.buf = b->buf;
  s->b.fd = b->fd;
  s->b.op = b->op;
  s->b.size = b->size;
  s->b.pos = 0;
}
