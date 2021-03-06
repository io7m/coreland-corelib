#ifndef CORELIB_STR_H
#define CORELIB_STR_H

unsigned long str_len(const char *);

long str_chr(const char *, int);
long str_rchr(const char *, int);

int str_char(const char *, int, unsigned long *);
int str_rchar(const char *, int, unsigned long *);

int str_diff(const char *, const char *);
int str_ndiff(const char *, const char *, unsigned long);
int str_casei_diff(const char *, const char *);
int str_casei_ndiff(const char *, const char *, unsigned long);

void str_toupper(char *);
void str_tolower(char *);

int str_dup(const char *, char **);
int str_ends(const char *, const char *);
int str_starts(const char *, const char *);

#define str_same(s,t) (str_diff((s),(t)) == 0)
#define str_nsame(s,t,n) (str_ndiff((s),(t),(n)) == 0)
#define str_casei_same(s,t) (str_casei_diff((s),(t)) == 0)
#define str_casei_nsame(s,t,n) (str_casei_ndiff((s),(t),(n)) == 0)

#endif
