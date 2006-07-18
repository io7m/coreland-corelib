#ifndef SGETLINE_H
#define SGETLINE_H

#include "buffer.h"

#define S_LINE_MAX 2048

typedef struct {
  char *s;
  unsigned long len;
  unsigned long a;
  unsigned long line_nr;
  buffer b; 
} sgetline;

#define sgetline_INIT(sbuf, bbuf, op, fd, len)\
{ (sbuf), (0), (sizeof sbuf), (0), { (sizeof sbuf), (0), (fd), (op), (bbuf) } }

void sgetline_init(sgetline *,
                   char *, unsigned long,
                   char *, unsigned long, 
                   long (*)(int, char *, unsigned long),
                   int);

void sgetline_initbuf(sgetline *, char *, unsigned long, buffer *);
void sgetline_chop(sgetline *, unsigned long);
void sgetline_trunc(sgetline *);
int sgetline_get(sgetline *);

#endif
