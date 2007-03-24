#include <stdio.h>
#include "../int16.h"
#include "../int32.h"
#include "../int64.h"

int main(void)
{
  unsigned char p16[sizeof(int16)];
  unsigned char p32[sizeof(int32)];
  unsigned char p64[sizeof(int64)];
  int16 i16;
  int32 i32;
  int64 i64;

  i16 = 0xff;
  int16_packl(p16, i16);
  int16_unpackl(p16, &i16);
  if (i16 != 0xff) { printf("fail: 1 i16 == %u\n", i16); return 1; }
  int16_packb(p16, i16);
  int16_unpackb(p16, &i16);
  if (i16 != 0xff) { printf("fail: 2 i16 == %u\n", i16); return 1; }
 
  i32 = 0xfffff;
  int32_packl(p32, i32);
  int32_unpackl(p32, &i32);
  if (i32 != 0xfffff) { printf("fail: 1 i32 == %u\n", i32); return 1; }
  int32_packb(p32, i32);
  int32_unpackb(p32, &i32);
  if (i32 != 0xfffff) { printf("fail: 2 i32 == %u\n", i32); return 1; }
 
  i64 = 0xfffffaabbccLL;
  int64_packl(p64, i64);
  int64_unpackl(p64, &i64);
  if (i64 != 0xfffffaabbccLL) { printf("fail: 1 i64 == %u\n", i64); return 1; }
  int64_packb(p64, i64);
  int64_unpackb(p64, &i64);
  if (i64 != 0xfffffaabbccLL) { printf("fail: 2 i64 == %u\n", i64); return 1; }

  return 0;
}
