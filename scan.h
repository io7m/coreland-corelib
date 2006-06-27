#ifndef SCAN_H
#define SCAN_H

unsigned int scan_ulong(const char *, unsigned long *);
unsigned int scan_ulongx(const char *, unsigned long *);
unsigned int scan_ulongo(const char *, unsigned long *);

unsigned int scan_uint(const char *, unsigned int *);
unsigned int scan_uintx(const char *, unsigned int *);
unsigned int scan_uinto(const char *, unsigned int *);

unsigned int scan_ushort(const char *, unsigned short *);
unsigned int scan_ushortx(const char *, unsigned short *);
unsigned int scan_ushorto(const char *, unsigned short *);

unsigned int scan_uchar(const char *, unsigned char *);
unsigned int scan_ucharx(const char *, unsigned char *);
unsigned int scan_ucharo(const char *, unsigned char *);

unsigned int scan_ulonglong(const char *, unsigned long long *);
unsigned int scan_ulonglongx(const char *, unsigned long long *);
unsigned int scan_ulonglongo(const char *, unsigned long long *);

unsigned int scan_float(const char *, float *);
unsigned int scan_double(const char *, double *);

unsigned long scan_charset(const char *, const char *);
unsigned long scan_notcharset(const char *, const char *);
unsigned long scan_whitespace(const char *);
unsigned long scan_newline(const char *);

#endif
