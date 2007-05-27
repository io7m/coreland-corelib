#ifndef CORELIB_SCAN_H
#define CORELIB_SCAN_H

unsigned int scan_ulong(const char *, unsigned long *);
unsigned int scan_ulongx(const char *, unsigned long *);
unsigned int scan_ulongo(const char *, unsigned long *);
unsigned int scan_ulongb(const char *, unsigned long *);

unsigned int scan_uint(const char *, unsigned int *);
unsigned int scan_uintx(const char *, unsigned int *);
unsigned int scan_uinto(const char *, unsigned int *);
unsigned int scan_uintb(const char *, unsigned int *);

unsigned int scan_ushort(const char *, unsigned short *);
unsigned int scan_ushortx(const char *, unsigned short *);
unsigned int scan_ushorto(const char *, unsigned short *);
unsigned int scan_ushortb(const char *, unsigned short *);

unsigned int scan_uchar(const char *, unsigned char *);
unsigned int scan_ucharx(const char *, unsigned char *);
unsigned int scan_ucharo(const char *, unsigned char *);
unsigned int scan_ucharb(const char *, unsigned char *);

unsigned int scan_long(const char *, long *);
unsigned int scan_longx(const char *, long *);
unsigned int scan_longo(const char *, long *);
unsigned int scan_longb(const char *, long *);

unsigned int scan_int(const char *, int *);
unsigned int scan_intx(const char *, int *);
unsigned int scan_into(const char *, int *);
unsigned int scan_intb(const char *, int *);

unsigned int scan_short(const char *, short *);
unsigned int scan_shortx(const char *, short *);
unsigned int scan_shorto(const char *, short *);
unsigned int scan_shortb(const char *, short *);

unsigned int scan_char(const char *, char *);
unsigned int scan_charx(const char *, char *);
unsigned int scan_charo(const char *, char *);
unsigned int scan_charb(const char *, char *);

#if defined(CORELIB_USE_LONGLONG)
unsigned int scan_ulonglong(const char *, unsigned long long *);
unsigned int scan_ulonglongx(const char *, unsigned long long *);
unsigned int scan_ulonglongo(const char *, unsigned long long *);
unsigned int scan_ulonglongb(const char *, unsigned long long *);

unsigned int scan_longlong(const char *, long long *);
unsigned int scan_longlongx(const char *, long long *);
unsigned int scan_longlongo(const char *, long long *);
unsigned int scan_longlongb(const char *, long long *);
#endif

unsigned int scan_float(const char *, float *);
unsigned int scan_double(const char *, double *);

unsigned long scan_charset(const char *, const char *);
unsigned long scan_notcharset(const char *, const char *);
unsigned long scan_whitespace(const char *);
unsigned long scan_newline(const char *);

#endif
