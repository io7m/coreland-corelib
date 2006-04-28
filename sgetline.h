#ifndef SGETLINE_H
#define SGETLINE_H

#include "buffer.h"

#define S_LINE_MAX 2048

typedef struct {
  char *s;
  unsigned int len;
  unsigned int a;
  unsigned int line_nr;
  buffer b; 
} sgetline;

#define sgetline_INIT(sbuf, bbuf, op, fd, len)\
{ (sbuf), (0), (sizeof sbuf), (0), { (sizeof sbuf), (0), (fd), (op), (bbuf) } }

void sgetline_init(sgetline *,
                   char *, unsigned int,
                   char *, unsigned int, 
                   int (*)(), int);

void sgetline_initbuf(sgetline *, char *, unsigned int, buffer *);
void sgetline_chop(sgetline *, unsigned int);
void sgetline_trunc(sgetline *);
int sgetline_get(sgetline *);

#endif
