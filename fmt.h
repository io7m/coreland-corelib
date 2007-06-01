#ifndef CORELIB_FMT_H
#define CORELIB_FMT_H

#include <float.h>

#define FMT_ULONG ((sizeof(long) * 8) + 1)
#define FMT_LEN ((char *) 0)
#define FMT_FLOAT (FLT_DIG << 2)
#define FMT_DOUBLE (DBL_DIG << 2)

#if defined(CORELIB_USE_LONGLONG)
  #define FMT_ULONGLONG ((sizeof(long long) * 8) + 1)
#else
  #define FMT_ULONGLONG FMT_ULONG
#endif

#define FMT_LONG FMT_ULONG
#define FMT_LONGLONG FMT_ULONGLONG

#define FMT_PAD_SIGN_POST 0x0000
#define FMT_PAD_SIGN_PRE  0x0001

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

unsigned int fmt_long(char *, long);
unsigned int fmt_longx(char *, long);
unsigned int fmt_longo(char *, long);
unsigned int fmt_longb(char *, long);

unsigned int fmt_int(char *, int);
unsigned int fmt_intx(char *, int);
unsigned int fmt_into(char *, int);
unsigned int fmt_intb(char *, int);

unsigned int fmt_short(char *, short);
unsigned int fmt_shortx(char *, short);
unsigned int fmt_shorto(char *, short);
unsigned int fmt_shortb(char *, short);

unsigned int fmt_char(char *, char);
unsigned int fmt_charx(char *, char);
unsigned int fmt_charo(char *, char);
unsigned int fmt_charb(char *, char);

#if defined(CORELIB_USE_LONGLONG)
unsigned int fmt_ulonglong(char *, unsigned long long);
unsigned int fmt_ulonglongx(char *, unsigned long long);
unsigned int fmt_ulonglongo(char *, unsigned long long);
unsigned int fmt_ulonglongb(char *, unsigned long long);

unsigned int fmt_longlong(char *, long long);
unsigned int fmt_longlongx(char *, long long);
unsigned int fmt_longlongo(char *, long long);
unsigned int fmt_longlongb(char *, long long);
#endif

unsigned int fmt_float(char *, float, unsigned int);
unsigned int fmt_double(char *, double, unsigned int);

unsigned long fmt_str(char *, const char *);
unsigned long fmt_nstr(char *, const char *, unsigned long);

unsigned int fmt_pad_ulong(char *, unsigned long, unsigned int, unsigned char, unsigned int (*)(char *, unsigned long));
unsigned int fmt_pad_uint(char *, unsigned int, unsigned int, unsigned char, unsigned int (*)(char *, unsigned int));
unsigned int fmt_pad_ushort(char *, unsigned short, unsigned int, unsigned char, unsigned int (*)(char *, unsigned short));
unsigned int fmt_pad_uchar(char *, unsigned char, unsigned int, unsigned char, unsigned int (*)(char *, unsigned char));

unsigned int fmt_pad_long(char *, long, unsigned int, unsigned char, unsigned int (*)(char *, long), unsigned int);
unsigned int fmt_pad_int(char *, int, unsigned int, unsigned char, unsigned int (*)(char *, int), unsigned int);
unsigned int fmt_pad_short(char *, short, unsigned int, unsigned char, unsigned int (*)(char *, short), unsigned int);
unsigned int fmt_pad_char(char *, char, unsigned int, unsigned char, unsigned int (*)(char *, char), unsigned int);

#if defined(CORELIB_USE_LONGLONG)
unsigned int fmt_pad_ulonglong(char *, unsigned long long, unsigned int, unsigned char, unsigned int (*)(char *, unsigned long long));
unsigned int fmt_pad_longlong(char *, long long, unsigned int, unsigned char, unsigned int (*)(char *, long long));
#endif

#endif
