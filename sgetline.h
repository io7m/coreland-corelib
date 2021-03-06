#ifndef CORELIB_SGETLINE_H
#define CORELIB_SGETLINE_H

#include "buffer.h"

#define S_LINE_MAX 2048
#define SGETLINE_ZERO {0,0,0,0,BUFFER_ZERO}

struct sgetline {
  char *s;
  unsigned long len;
  unsigned long a;
  unsigned long line_nr;
  struct buffer b; 
};

#define sgetline_INIT(sbuf, bbuf, op, fd, len)\
{ (sbuf), (0), (sizeof sbuf), (0), { (sizeof sbuf), (0), (fd), (op), (bbuf) } }

void sgetline_init(struct sgetline *,
                   char *, unsigned long,
                   char *, unsigned long, 
                   long (*)(int, char *, unsigned long),
                   int);

void sgetline_initbuf(struct sgetline *, char *, unsigned long, struct buffer *);
void sgetline_chop(struct sgetline *, unsigned long);
void sgetline_trunc(struct sgetline *);
int sgetline_get(struct sgetline *);

unsigned long sgetline_size(const struct sgetline *);
unsigned long sgetline_linenum(const struct sgetline *);
const char *sgetline_data(const struct sgetline *);

#endif
