#include "uint.h"

static void uint_copy(const void *a, void *b, unsigned long len)
{
  const unsigned char *ap = a;
  unsigned char *bp = b;
  while (len--) bp[len] = ap[len];
}

void uint_unpackl(const unsigned char *buf, void *ul, unsigned long num)
{
  unsigned long tmp = 0;
  unsigned long len = num;
  for (;;) {
    --num; tmp += buf[num]; if (!num) break; tmp <<= 8u; 
  }
  uint_copy(&tmp, ul, len);
}
void uint_unpackb(const unsigned char *buf, void *ul, unsigned long num)
{
  unsigned long tmp = 0;
  unsigned long len = num;
  for (;;) {
    tmp += buf[len - num]; --num; if (!num) break; tmp <<= 8u;
  }
  uint_copy(&tmp, ul, len);
}
