#include "uint.h"

void uint_unpackl(const unsigned char *buf, unsigned long *ul, unsigned long num)
{
  register unsigned long tmp = 0;
  for (;;) {
    --num; tmp += buf[num]; if (!num) break; tmp <<= 8u; 
  }
  *ul = tmp;
}
void uint_unpackb(const unsigned char *buf, unsigned long *ul, unsigned long num)
{
  register unsigned long tmp = 0;
  register unsigned long len = num;
  for (;;) {
    tmp += buf[len - num]; --num; if (!num) break; tmp <<= 8u;
  }
  *ul = tmp;
}
