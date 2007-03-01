#include "uint.h"

void uint_packl(unsigned char *buf, unsigned long ul, unsigned long num)
{
  register unsigned long len = num;
  for (;;) {
    if (!num) break;
    buf[len - num] = ul & 0xffu; ul >>= 8u; --num;
  }
}
void uint_packb(unsigned char *buf, unsigned long ul, unsigned long num)
{
  for (;;) {
    buf[--num] = ul & 0xffu; ul >>= 8u;
    if (!num) break;
  }
}
