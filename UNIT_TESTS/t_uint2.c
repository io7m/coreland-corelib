#include <stdio.h>
#include "../uint.h"

unsigned char buf[UINT_PACKBUF];

void show(const char *name, const unsigned char *buf,
          unsigned long len, unsigned long num)
{
  unsigned long ind;
  printf("info: %s %lu %lu [", name, num, len);
  for (ind = 0; ind < len; ++ind) {
    printf("%hhx", buf[ind]);
    if (ind != len - 1) printf(" ");
  } 
  printf("]\n");
}
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

int test_uchar()
{
  unsigned char uc;

  /* uchar */
  uc = 170;
  uint_packb(buf, uc, sizeof(unsigned char));
  if (buf[0] != 170) return fail_pack("b", "uc", 0, 170, buf[0]);

  uc = 0;
  uint_unpackb(buf, &uc, sizeof(unsigned char));
  if (uc != 170) return fail_unpack("b", "uc", uc, 170);

  show("uchar packb", buf, sizeof(unsigned char), uc);

  uc = 170;
  uint_packl(buf, uc, sizeof(unsigned char));
  if (buf[0] != 170) return fail_pack("l", "uc", 0, 170, buf[0]);

  uc = 0;
  uint_unpackl(buf, &uc, sizeof(unsigned char));
  if (uc != 170) return fail_unpack("l", "uc", uc, 170);

  show("uchar packl", buf, sizeof(unsigned char), uc);
  return 1;
}

int test_ushort()
{
  unsigned short us;

  /* ushort */
  us = 52394;
  uint_packb(buf, us, sizeof(us));
  if (buf[sizeof(us) - 1] != 170)
    return fail_pack("b", "us", sizeof(us) - 1, 170, buf[sizeof(us) - 1]);
  if (buf[sizeof(us) - 2] != 204)
    return fail_pack("b", "us", sizeof(us) - 2, 204, buf[sizeof(us) - 2]);

  us = 0;
  uint_unpackb(buf, &us, sizeof(us));
  if (us != 52394) return fail_unpack("b", "us", us, 52394);

  show("ushort packb", buf, sizeof(unsigned short), us);

  us = 52394;
  uint_packl(buf, us, sizeof(us));
  if (buf[0] != 170)
    return fail_pack("l", "us", 0, 170, buf[0]);
  if (buf[1] != 204)
    return fail_pack("l", "us", 1, 204, buf[1]);

  us = 0;
  uint_unpackl(buf, &us, sizeof(us));
  if (us != 52394) return fail_unpack("b", "us", us, 52394);

  show("ushort packl", buf, sizeof(unsigned short), us);
  return 1;
}

int test_uint()
{
  unsigned int ui;

  /* uint */
  ui = 52394;
  uint_packb(buf, ui, sizeof(ui));
  if (buf[sizeof(ui) - 1] != 170)
    return fail_pack("b", "ui", sizeof(ui) - 1, 170, buf[sizeof(ui) - 1]);
  if (buf[sizeof(ui) - 2] != 204)
    return fail_pack("b", "ui", sizeof(ui) - 2, 204, buf[sizeof(ui) - 2]);

  ui = 0;
  uint_unpackb(buf, &ui, sizeof(ui));
  if (ui != 52394) return fail_unpack("b", "ui", ui, 52394);

  show("uint packb", buf, sizeof(unsigned int), ui);

  ui = 52394;
  uint_packl(buf, ui, sizeof(ui));
  if (buf[0] != 170)
    return fail_pack("l", "ui", 0, 170, buf[0]);
  if (buf[1] != 204)
    return fail_pack("l", "ui", 1, 204, buf[1]);

  ui = 0;
  uint_unpackl(buf, &ui, sizeof(ui));
  if (ui != 52394) return fail_unpack("b", "ui", ui, 52394);

  show("uint packl", buf, sizeof(unsigned int), ui);
  return 1;
}

int test_ulong()
{
  unsigned long ul;

  /* ulong */
  ul = 3433745578U;
  uint_packb(buf, ul, sizeof(ul));
  if (buf[sizeof(ul) - 1] != 170)
    return fail_pack("b", "ul", sizeof(ul) - 1, 170, buf[sizeof(ul) - 1]);
  if (buf[sizeof(ul) - 2] != 204)
    return fail_pack("b", "ul", sizeof(ul) - 2, 204, buf[sizeof(ul) - 2]);
  if (buf[sizeof(ul) - 3] != 170)
    return fail_pack("b", "ul", sizeof(ul) - 1, 170, buf[sizeof(ul) - 3]);
  if (buf[sizeof(ul) - 4] != 204)
    return fail_pack("b", "ul", sizeof(ul) - 2, 204, buf[sizeof(ul) - 4]);
 
  ul = 0;
  uint_unpackb(buf, &ul, sizeof(ul));
  if (ul != 3433745578U) return fail_unpack("b", "ul", ul, 3433745578U);

  show("ulong packb", buf, sizeof(unsigned long), ul);

  ul = 3433745578U;
  uint_packl(buf, ul, sizeof(ul));
  if (buf[0] != 170)
    return fail_pack("l", "ul", 0, 170, buf[0]);
  if (buf[1] != 204)
    return fail_pack("l", "ul", 1, 204, buf[1]);
  if (buf[2] != 170)
    return fail_pack("l", "ul", 0, 170, buf[2]);
  if (buf[3] != 204)
    return fail_pack("l", "ul", 1, 204, buf[3]);
 
  ul = 0;
  uint_unpackl(buf, &ul, sizeof(ul));
  if (ul != 3433745578U) return fail_unpack("b", "ul", ul, 3433745578U);

  show("ulong packl", buf, sizeof(unsigned long), ul);
  return 1;
}

int main(void)
{
  if (!test_uchar()) return 1;
  if (!test_ushort()) return 1;
  if (!test_uint()) return 1;
  if (!test_ulong()) return 1;

  return 0;
}
