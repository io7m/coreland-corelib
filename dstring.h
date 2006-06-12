#ifndef DSTRING_H
#define DSTRING_H

#define DSTRING_OVERALLOC 32
#define dstring_INIT {0,0,0}

typedef struct dstring {
  char *s;
  unsigned int len;
  unsigned int a;
} dstring;

int dstring_init(dstring *, unsigned int);
void dstring_free(dstring *);

int dstring_cat(dstring *, const dstring *);
int dstring_catb(dstring *, const char *, unsigned int);
int dstring_cats(dstring *, const char *);
int dstring_cat0(dstring *);
unsigned int dstring_0(dstring *);

int dstring_cpyb(dstring *, const char *, unsigned int);
int dstring_cpys(dstring *, const char *);
int dstring_copy(dstring *, const dstring *);

void dstring_trunc(dstring *);
void dstring_chop(dstring *, unsigned int);

#endif
