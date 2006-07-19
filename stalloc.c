#include "error.h"
#include "stalloc.h"

typedef union { char x[STALLOC_ALIGN]; double d; } aligned;
static aligned a_space[STALLOC_SPACE / STALLOC_ALIGN];
#define space ((char *) a_space)
static unsigned long avail = STALLOC_SPACE;

static void copy_bytes(const char *sc, char *dc, unsigned long n)
{
  for (;;) {
    if (!n) return; *dc++ = *sc++; --n;
    if (!n) return; *dc++ = *sc++; --n;
    if (!n) return; *dc++ = *sc++; --n;
    if (!n) return; *dc++ = *sc++; --n;
  }
}
void *stalloc(unsigned long n)
{
  if (n < 0xfffffff0) {
    n = STALLOC_ALIGN + n - (n & (STALLOC_ALIGN - 1));
    if (n <= avail) {
      avail -= n;
      return space + avail;
    }
  }
  errno = error_nomem;
  return 0;
}
int strealloc(void **p, unsigned long n, unsigned long m)
{
  char *q;
  q = stalloc(n); /* avoid indirect call */
  if (q == 0) return 0;
  copy_bytes(*(char **)p, q, m);
  stdealloc(*(char **)p);
  *(char **)p = q;
  return 1;
}
void stdealloc(void *p)
{
  return;
}
