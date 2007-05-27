#include "fmt.h"

unsigned int fmt_pad_ushort(char *buf, unsigned short us, unsigned int pad,
                            unsigned char ch,
                            unsigned int (*fmt)(char *, unsigned short))
{
  unsigned int num_len;
  unsigned int len;
  char *ptr;

  len = 0;
  ptr = buf;
  num_len = fmt(FMT_LEN, us);

  if (pad > num_len) {
    pad -= num_len;
    for (;;) {
      if (!pad) break;
      if (ptr) *ptr++ = ch;
      --pad;
      ++len;
    }
  }

  len += fmt(ptr, us);
  return len;
}
