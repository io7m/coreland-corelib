#include "fmt.h"
#include "fmt_pad.h"

unsigned int fmt_pad_ulong(char *buf, unsigned long num, unsigned int pad,
                           unsigned char ch,
                           unsigned int (*fmt)(char *, unsigned long))
{
  FMT_PAD_CORE_UNSIGNED
}

unsigned int fmt_pad_long(char *buf, long num, unsigned int pad,
                          unsigned char ch, unsigned int (*fmt)(char *, long),
                          unsigned int flags)
{
  FMT_PAD_CORE_SIGNED
}
