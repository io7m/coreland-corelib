#include "../uint.h"

unsigned char buf[UINT_PACKBUF];

int fail_pack(const char *endian, const char *type, unsigned int ind,
         unsigned int exp, unsigned int got)
{
  printf("fail: pack%s %s [%u] %u != %u\n", endian, type, ind, exp, got);
  return 0;
}
int fail_unpack(const char *endian, const char *type,
                unsigned int exp, unsigned int got)
{
  printf("fail: unpack%s %s %u != %u\n", endian, type, exp, got);
  return 0;
}

int uchar()
{
  unsigned char uc;

  /* uchar */
  uc = 170;
  uint_packb(buf, uc, sizeof(unsigned char));
  if (buf[0] != 170) return fail_pack("b", "uc", 0, 170, buf[0]);
  uint_unpackb(buf, &uc, sizeof(unsigned char));
  if (uc != 170) return fail_unpack("b", "uc", uc, 170);

  uc = 170;
  uint_packl(buf, uc, sizeof(unsigned char));
  if (buf[0] != 170) return fail_pack("l", "uc", 0, 170, buf[0]);
  uint_unpackl(buf, &uc, sizeof(unsigned char));
  if (uc != 170) return fail_unpack("l", "uc", uc, 170);

  return 1;
}

int ushort()
{
  unsigned short us;

  /* ushort */
  us = 52394;
  uint_packb(buf, us, sizeof(us));
  if (buf[sizeof(us) - 1] != 170)
    return fail_pack("b", "us", sizeof(us) - 1, 170, buf[sizeof(us) - 1]);
  if (buf[sizeof(us) - 2] != 204)
    return fail_pack("b", "us", sizeof(us) - 2, 204, buf[sizeof(us) - 2]);
  uint_unpackb(buf, &us, sizeof(us));
  if (us != 52394) return fail_unpack("b", "us", us, 52394);

  us = 52394;
  uint_packl(buf, us, sizeof(us));
  if (buf[0] != 170)
    return fail_pack("l", "us", 0, 170, buf[0]);
  if (buf[1] != 204)
    return fail_pack("l", "us", 1, 204, buf[1]);
  uint_unpackl(buf, &us, sizeof(us));
  if (us != 52394) return fail_unpack("b", "us", us, 52394);

  return 0;
}

int uint()
{
  return 0;
}

int ulong()
{
  return 0;
}

int main()
{
  unsigned long ul;
  unsigned int ui;

  if (!uchar()) return 1;
/*  if (!ushort()) return 1; */

  return 0;
}
