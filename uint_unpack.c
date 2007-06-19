#include "uint.h"

/* test if current system is big endian */
static int uint_big_endian()
{
  unsigned int i = 0x7f;
  unsigned char c = * (unsigned char *) &i;
  return (c != i);
}

/* simulate integer truncation. dst is dst_len bytes long and src
 * is src_len bytes long. depending on endianness, a straight memory
 * copy would result in different values on different platforms. this
 * copy is careful to simulate integer truncation (a large value copied
 * into a single byte would become 0xff).
 */

static void uint_convert(const void *src, unsigned long src_len,
                               void *dst, unsigned long dst_len)
{
  unsigned long ind;
  const unsigned char *src_p = src;
  unsigned char *dst_p = dst;

  if (uint_big_endian())
    for (ind = 0; ind < dst_len; ++ind)
      dst_p[dst_len - (ind + 1)] = src_p[src_len - (ind + 1)];
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
