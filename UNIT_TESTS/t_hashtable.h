#include "../hashtable.h"

void printn(const char *s, unsigned int len);

void addb(hashtable *h, const char *k, unsigned long klen,
                        const char *x, unsigned long dlen, int exp);
void delete_keyb(hashtable *h, const char *k, unsigned long klen, int exp);
void getb(hashtable *h, const char *k, unsigned long klen,
                        char **x, unsigned long *len, int exp);
void replaceb(hashtable *h, const char *k, unsigned long klen,
                            const char *x, unsigned long xlen, int exp);

void add(hashtable *h, const char *k, const char *x, int exp);
void delete_key(hashtable *h, const char *k, int exp);
void get(hashtable *h, const char *k, char **x, unsigned long *len, int exp);
void replace(hashtable *h, const char *k, const char *x, int exp);

extern const char *ch1str[];
extern const unsigned int ch1str_len;
