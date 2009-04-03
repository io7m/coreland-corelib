#include "fmt.h"
#include "fmt_pad.h"

unsigned int fmt_pad_ushort(char *buf, unsigned short num, unsigned int pad,
                            unsigned char ch,
                            unsigned int (*fmt)(char *, unsigned short))
{
  FMT_PAD_CORE_UNSIGNED
}

unsigned int fmt_pad_short(char *buf, short num, unsigned int pad,
                           unsigned char ch, unsigned int (*fmt)(char *, short),
                           unsigned int flags)
{
  FMT_PAD_CORE_SIGNED
}
