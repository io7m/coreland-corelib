#include "fmt.h"

unsigned int fmt_pad_uint(char *buf, unsigned int ui, unsigned int pad,
                          unsigned char ch,
                          unsigned int (*fmt)(char *, unsigned int))
{
  unsigned int num_len;
  unsigned int len;
  char *ptr;

  len = 0;
  ptr = buf;
  num_len = fmt(FMT_LEN, ui);

  if (pad > num_len) {
    pad -= num_len;
    for (;;) {
      if (!pad) break;
      if (ptr) *ptr++ = ch;
      --pad;
      ++len;
    }
  }

  len += fmt(ptr, ui);
  return len;
}
