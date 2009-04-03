#ifndef FMT_PAD_H
#define FMT_PAD_H

#define FMT_PAD_CORE \
{                                                            \
  num_len = fmt(FMT_LEN, num);                               \
                                                             \
  if (pad > num_len) {                                       \
    pad -= num_len;                                          \
    for (;;) {                                               \
      if (!pad) break;                                       \
      if (ptr) *ptr++ = ch;                                  \
      --pad;                                                 \
      ++len;                                                 \
    }                                                        \
  }                                                          \
                                                             \
  len += fmt(ptr, num);                                      \
  return len;                                                \
}

#define FMT_PAD_CORE_UNSIGNED \
{                                                            \
  unsigned int num_len;                                      \
  unsigned int len = 0;                                      \
  char *ptr = buf;                                           \
                                                             \
  FMT_PAD_CORE                                               \
}

#define FMT_PAD_CORE_SIGNED \
{                                                            \
  unsigned int num_len;                                      \
  unsigned int len = 0;                                      \
  char *ptr = buf;                                           \
                                                             \
  if (flags & FMT_PAD_SIGN_PRE) {                            \
    if (num < 0) {                                           \
      if (ptr) *ptr++ = '-';                                 \
      --pad;                                                 \
      ++len;                                                 \
      num = -num;                                            \
    }                                                        \
  }                                                          \
                                                             \
  FMT_PAD_CORE                                               \
}

#endif
