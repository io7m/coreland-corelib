#ifndef OPEN_H
#define OPEN_H

#include "sd_fcntl.h"

#ifndef O_NONBLOCK
  #define O_NONBLOCK 0x00
#endif

int open_ro(const char *);
int open_wo(const char *);
int open_excl(const char *);
int open_append(const char *);
int open_trunc(const char *);
int open_rw(const char *);
int open_creat(const char *);

#endif
