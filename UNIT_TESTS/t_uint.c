#include <stdio.h>
#include "../uint16.h"
#include "../uint32.h"
#include "../uint64.h"
#include "../uint.h"

int main()
{
  unsigned char p16[sizeof(uint16)];
  unsigned char p32[sizeof(uint32)];
  unsigned char p64[sizeof(uint64)];
  unsigned char pui[UINT_PACKBUF];
  uint16 u16;
  uint32 u32;
  uint64 u64;
  unsigned long ui;

  u16 = 0xffU;
  uint16_packl(p16, u16);
  uint16_unpackl(p16, &u16);
  if (u16 != 0xffU) { printf("fail: 1 u16 == %u\n", u16); return 1; }
  uint16_packb(p16, u16);
  uint16_unpackb(p16, &u16);
  if (u16 != 0xffU) { printf("fail: 2 u16 == %u\n", u16); return 1; }
 
  u32 = 0xfffffU;
  uint32_packl(p32, u32);
  uint32_unpackl(p32, &u32);
  if (u32 != 0xfffffU) { printf("fail: 1 u32 == %u\n", u32); return 1; }
  uint32_packb(p32, u32);
  uint32_unpackb(p32, &u32);
  if (u32 != 0xfffffU) { printf("fail: 2 u32 == %u\n", u32); return 1; }
 
  u64 = 0xfffffaabbccULL;
  uint64_packl(p64, u64);
  uint64_unpackl(p64, &u64);
  if (u64 != 0xfffffaabbccULL) { printf("fail: 1 u64 == %u\n", u64); return 1; }
  uint64_packb(p64, u64);
  uint64_unpackb(p64, &u64);
  if (u64 != 0xfffffaabbccULL) { printf("fail: 2 u64 == %u\n", u64); return 1; }

  ui = 0xfffffU;
  uint_packl(pui, ui);
  uint_unpackl(pui, &ui);
  if (ui != 0xfffffU) { printf("fail: 1 ui == %lu\n", ui); return 1; }
  uint_packb(pui, ui);
  uint_unpackb(pui, &ui);
  if (ui != 0xfffffU) { printf("fail: 2 ui == %lu\n", ui); return 1; }
  return 0;
}
