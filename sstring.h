#ifndef CORELIB_SSTRING_H
#define CORELIB_SSTRING_H

#define SSTRING_ZERO {0,0,0}

struct sstring {
  char *s;
  unsigned long len; /* length of contents */
  unsigned long a;   /* allocated */
};

#define sstring_INIT(s) { (s), (0), (sizeof s) }

void sstring_init(struct sstring *, char *, unsigned long);

unsigned long sstring_catb(struct sstring *, const char *, unsigned long);
unsigned long sstring_cats(struct sstring *, const char *);
unsigned long sstring_cat(struct sstring *, const struct sstring *);

unsigned long sstring_cpyb(struct sstring *, const char *, unsigned long);
unsigned long sstring_cpys(struct sstring *, const char *);
unsigned long sstring_copy(struct sstring *, const struct sstring *);

unsigned long sstring_0(struct sstring *);
unsigned long sstring_chop(struct sstring *, unsigned long);

#define sstring_trunc(ss) (sstring_chop((ss),0))

#endif
