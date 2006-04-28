#ifndef SCAN_H
#define SCAN_H

#include "uint16.h"
#include "uint32.h"
#include "uint64.h"

unsigned int scan_u32(const char *, uint32 *);
unsigned int scan_u32o(const char *, uint32 *);
unsigned int scan_u32x(const char *, uint32 *);

unsigned int scan_u64(const char *, uint64 *);
unsigned int scan_u64o(const char *, uint64 *);
unsigned int scan_u64x(const char *, uint64 *);

unsigned int scan_float(const char *, float *);
unsigned int scan_double(const char *, double *);

unsigned int scan_space(const char *);
unsigned int scan_chars(const char *, const char *);
unsigned int scan_newline(const char *);

extern const char *lowercase_alpha;
extern const char *uppercase_alpha;
extern const char *numeric;

#endif
