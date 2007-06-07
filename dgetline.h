#ifndef DGETLINE_H
#define DGETLINE_H

#include "buffer.h"
#include "dstring.h"

struct dgetline {
  struct buffer b;
  struct dstring d; 
  unsigned long line_nr;
};

int dgetline_init(struct dgetline *, long (*)(int, char *, unsigned long), int fd, char *, unsigned long);
int dgetline_initbuf(struct dgetline *, struct buffer *);
int dgetline_get(struct dgetline *);
void dgetline_setfd(struct dgetline *, int);
void dgetline_free(struct dgetline *);
void dgetline_trunc(struct dgetline *);
void dgetline_chop(struct dgetline *, unsigned long);
const char *dgetline_data(const struct dgetline *);
unsigned long dgetline_size(const struct dgetline *);
unsigned long dgetline_linenum(const struct dgetline *);

#endif
