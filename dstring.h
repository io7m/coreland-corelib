#ifndef DSTRING_H
#define DSTRING_H

#define DSTRING_OVERALLOC 32
#define dstring_INIT {0,0,0}

typedef struct dstring {
  char *s;
  unsigned long len;
  unsigned long a;
} dstring;

int dstring_init(dstring *, unsigned long);
void dstring_free(dstring *);

int dstring_cat(dstring *, const dstring *);
int dstring_catb(dstring *, const char *, unsigned long);
int dstring_cats(dstring *, const char *);
int dstring_cat0(dstring *);
unsigned long dstring_0(dstring *);

int dstring_cpyb(dstring *, const char *, unsigned long);
int dstring_cpys(dstring *, const char *);
int dstring_copy(dstring *, const dstring *);

void dstring_trunc(dstring *);
void dstring_chop(dstring *, unsigned long);

#endif
