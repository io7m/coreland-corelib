#include "../hashtable.h"

void printn(const char *s, unsigned int len);

void addb(struct hashtable *h, const char *k, unsigned long klen,
                               const char *x, unsigned long dlen, int exp);
void delete_keyb(struct hashtable *h, const char *k, unsigned long klen, int exp);
void getb(struct hashtable *h, const char *k, unsigned long klen,
                               char **x, unsigned long *len, int exp);
void replaceb(struct hashtable *h, const char *k, unsigned long klen,
                                   const char *x, unsigned long xlen, int exp);
void add(struct hashtable *h, const char *k, const char *x, int exp);
void delete_key(struct hashtable *h, const char *k, int exp);
void get(struct hashtable *h, const char *k, char **x, unsigned long *len, int exp);
void replace(struct hashtable *h, const char *k, const char *x, int exp);

extern const char *ch1str[];
extern const unsigned int ch1str_len;
