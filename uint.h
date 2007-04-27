#ifndef CORELIB_UINT_H
#define CORELIB_UINT_H

#define UINT_PACKBUF (sizeof(unsigned long))

void uint_packl(unsigned char *, unsigned long, unsigned long);
void uint_packb(unsigned char *, unsigned long, unsigned long);
void uint_unpackl(const unsigned char *, void *, unsigned long);
void uint_unpackb(const unsigned char *, void *, unsigned long);

#endif
