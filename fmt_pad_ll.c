#include "sd_longlong.h"
#include "fmt.h"
#include "fmt_pad.h"

#if defined(HAVE_LONGLONG)
unsigned int fmt_pad_ullong(char *buf, unsigned long long num, unsigned int pad,
                            unsigned char ch,
                            unsigned int (*fmt)(char *, unsigned long long))
{
  FMT_PAD_CORE_UNSIGNED;
}

unsigned int fmt_pad_llong(char *buf, long long num, unsigned int pad,
                           unsigned char ch,
                           unsigned int (*fmt)(char *, long long),
                           unsigned int flags)
{
  FMT_PAD_CORE_SIGNED;
}
#endif
