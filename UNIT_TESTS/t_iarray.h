#ifndef T_IARRAY_H
#define T_IARRAY_H

#include "../iarray.h"

#define IARRAY_DUMP_STRING 0x0001
#define IARRAY_DUMP_INT    0x0002

int iarray_integrity(struct iarray *);
void iarray_dump(struct iarray *, unsigned int);

#endif
