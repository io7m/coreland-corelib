#include "uint.h"

/* test if current system is big endian */
static int uint_big_endian()
{
  unsigned int i = 0x7f;
  unsigned char c = * (unsigned char *) &i;
  return (c != i);
}

/* copy src_len bytes of data from src into dst_len bytes of data
 * at dst. this is necessary to take care of endianness and the fact
 * that 'unsigned long' is used internally to hold a temporary value
 * but client code may be requesting the unpacking of an 'unsigned
 * short', for example.
 */

static void uint_convert(const void *src, unsigned long src_len,
                               void *dst, unsigned long dst_len)
{
  unsigned long ind;
  const unsigned char *src_p = src;
  unsigned char *dst_p = dst;

  if (uint_big_endian())
    for (ind = 0; ind < dst_len; ++ind)
      dst_p[dst_len - ind] = src_p[src_len - ind];
  else
    for (ind = 0; ind < dst_len; ++ind)
      dst_p[ind] = src_p[ind];
}

void uint_unpackl(const unsigned char *buf, void *ul, unsigned long num)
{
  unsigned long tmp = 0;
  unsigned long len = num;
  for (;;) {
    --num; tmp += buf[num]; if (!num) break; tmp <<= 8u; 
  }
  uint_convert(&tmp, sizeof(unsigned long), ul, len);
}
void uint_unpackb(const unsigned char *buf, void *ul, unsigned long num)
{
  unsigned long tmp = 0;
  unsigned long len = num;
  for (;;) {
    tmp += buf[len - num]; --num; if (!num) break; tmp <<= 8u;
  }
  uint_convert(&tmp, sizeof(unsigned long), ul, len);
}
