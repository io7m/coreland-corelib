#ifndef DGETLINE_H
#define DGETLINE_H

#include "buffer.h"
#include "dstring.h"

struct dgetline {
  struct buffer b;
  struct dstring d; 
  unsigned long line_nr;
};

int dgetline_init(struct dgetline *, int fd, char *, unsigned long);
int dgetline_get(struct dgetline *);
void dgetline_free(struct dgetline *);
const char *dgetline_data(const struct dgetline *);
unsigned long dgetline_size(const struct dgetline *);

#endif
