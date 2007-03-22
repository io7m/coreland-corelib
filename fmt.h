#ifndef FMT_H
#define FMT_H

#include "_sd_longlong.h"

#define FMT_ULONG ((sizeof(long) * 8) + 1)
#define FMT_LEN ((char *) 0)
#define FMT_FLOAT (FMT_ULONG + 1 + FMT_ULONG)

#if defined(HAVE_LONGLONG)
  #define FMT_ULONGLONG ((sizeof(long long) * 8) + 1)
  #define FMT_DOUBLE (FMT_ULONGLONG + 1 + FMT_ULONGLONG)
#else
  #define FMT_ULONGLONG FMT_ULONG
  #define FMT_DOUBLE (FMT_ULONG + 1 + FMT_ULONG)
#endif

unsigned int fmt_ulong(char *, unsigned long);
unsigned int fmt_ulongx(char *, unsigned long);
unsigned int fmt_ulongo(char *, unsigned long);
unsigned int fmt_ulongb(char *, unsigned long);

unsigned int fmt_uint(char *, unsigned int);
unsigned int fmt_uintx(char *, unsigned int);
unsigned int fmt_uinto(char *, unsigned int);
unsigned int fmt_uintb(char *, unsigned int);

unsigned int fmt_ushort(char *, unsigned short);
unsigned int fmt_ushortx(char *, unsigned short);
unsigned int fmt_ushorto(char *, unsigned short);
unsigned int fmt_ushortb(char *, unsigned short);

unsigned int fmt_uchar(char *, unsigned char);
unsigned int fmt_ucharx(char *, unsigned char);
unsigned int fmt_ucharo(char *, unsigned char);
unsigned int fmt_ucharb(char *, unsigned char);

#if defined(HAVE_LONGLONG)
unsigned int fmt_ulonglong(char *, unsigned long long);
unsigned int fmt_ulonglongx(char *, unsigned long long);
unsigned int fmt_ulonglongo(char *, unsigned long long);
unsigned int fmt_ulonglongb(char *, unsigned long long);
#endif

unsigned int fmt_float(char *, float, unsigned int);
unsigned int fmt_double(char *, double, unsigned int);

unsigned long fmt_str(char *, const char *);
unsigned long fmt_nstr(char *, const char *, unsigned long);

#endif
