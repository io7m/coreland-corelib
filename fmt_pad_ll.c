#include "sd_longlong.h"
#include "fmt.h"

#if defined(HAVE_LONGLONG)
unsigned int fmt_pad_ullong(char *buf, unsigned long long ull, unsigned int pad,
                            unsigned char ch,
                            unsigned int (*fmt)(char *, unsigned long long))
{
  unsigned int num_len;
  unsigned int len;
  char *ptr;

  len = 0;
  ptr = buf;
  num_len = fmt(FMT_LEN, ull);

  if (pad > num_len) {
    pad -= num_len;
    for (;;) {
      if (!pad) break;
      if (ptr) *ptr++ = ch;
      --pad;
      ++len;
    }
  }

  len += fmt(ptr, ull);
  return len;
}
#endif
