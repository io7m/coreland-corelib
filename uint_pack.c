#include "uint.h"

void uint_packl(unsigned char *buf, unsigned long ul)
{
  register unsigned int ind = UINT_PACKBUF;
  for (;;) {
    if (!ind) break;
    buf[UINT_PACKBUF - ind] = ul & 0xffu; ul >>= 8u; --ind;
  }
}
void uint_packb(unsigned char *buf, unsigned long ul)
{
  register unsigned int ind = UINT_PACKBUF;
  for (;;) {
    buf[--ind] = ul & 0xffu; ul >>= 8u;
    if (!ind) break;
  }
}
