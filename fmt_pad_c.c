#include "fmt.h"
#include "fmt_pad.h"

unsigned int fmt_pad_uchar(char *buf, unsigned char num, unsigned int pad,
                           unsigned char ch,
                           unsigned int (*fmt)(char *, unsigned char))
{
  FMT_PAD_CORE_UNSIGNED
}

unsigned int fmt_pad_char(char *buf, char num, unsigned int pad,
                          unsigned char ch, unsigned int (*fmt)(char *, char),
                          unsigned int flags)
{
  FMT_PAD_CORE_SIGNED
}
