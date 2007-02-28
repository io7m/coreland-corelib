#include "uint.h"

void uint_unpackl(const unsigned char *buf, unsigned long *ul)
{
  register unsigned int ind = UINT_PACKBUF;
  register unsigned long tmp = 0;
  for (;;) {
    --ind; tmp += buf[ind]; if (!ind) break; tmp <<= 8u; 
  }
  *ul = tmp;
}
void uint_unpackb(const unsigned char *buf, unsigned long *ul)
{
  register unsigned int ind = UINT_PACKBUF;
  register unsigned long tmp = 0;
  for (;;) {
    tmp += buf[UINT_PACKBUF - ind]; --ind; if (!ind) break; tmp <<= 8u;
  }
  *ul = tmp;
}
