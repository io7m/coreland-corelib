#ifndef SSTRING_H
#define SSTRING_H

typedef struct sstring {
  char* s;
  unsigned long len; /* length of contents */
  unsigned long a;   /* allocated */
} sstring;

#define sstring_INIT(s) { (s), (0), (sizeof s) }

void sstring_init(sstring *, char *, unsigned long);

unsigned long sstring_catb(sstring *, const char *, unsigned long);
unsigned long sstring_cats(sstring *, const char *);
unsigned long sstring_cat(sstring *, const sstring *);

unsigned long sstring_cpyb(sstring *, const char *, unsigned long);
unsigned long sstring_cpys(sstring *, const char *);
unsigned long sstring_copy(sstring *, const sstring *);

unsigned long sstring_0(sstring *);

unsigned long sstring_chop(sstring *, unsigned long);
void sstring_trunc(sstring *);

#endif
