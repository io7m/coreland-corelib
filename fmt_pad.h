#ifndef FMT_PAD_H
#define FMT_PAD_H

#define FMT_PAD_CORE \
{                                                            \
  unsigned int num_len;                                      \
  unsigned int len;                                          \
  char *ptr;                                                 \
                                                             \
  len = 0;                                                   \
  ptr = buf;                                                 \
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

#endif
