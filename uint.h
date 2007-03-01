#ifndef UINT_H
#define UINT_H

#define UINT_PACKBUF (sizeof(unsigned long))

void ulong_packl(unsigned char *, unsigned long, unsigned long);
void ulong_packb(unsigned char *, unsigned long, unsigned long);
void ulong_unpackl(const unsigned char *, unsigned long *, unsigned long);
void ulong_unpackb(const unsigned char *, unsigned long *, unsigned long);

#endif
