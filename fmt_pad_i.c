#include "fmt.h"
#include "fmt_pad.h"

unsigned int fmt_pad_uint(char *buf, unsigned int num, unsigned int pad,
                          unsigned char ch,
                          unsigned int (*fmt)(char *, unsigned int))
{
  FMT_PAD_CORE;
}

unsigned int fmt_pad_int(char *buf, int num, unsigned int pad,
                         unsigned char ch,
                         unsigned int (*fmt)(char *, int))
{
  FMT_PAD_CORE;
}
