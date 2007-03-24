#include "../fmt_spec.h"
#include <stdio.h>

int main(void)
{
  uint32 u32;
  uint64 u64;
  char c32[FMT_UINT32];
  char c64[FMT_UINT64];

  /* u32 */

  u32 = 10000U;
  c32[fmt_u32(c32, u32)] = 0;
  if (c32[0] != '1') { printf("fail: c32[0] == %c\n", c32[0]); return 1; }
  if (c32[1] != '0') { printf("fail: c32[1] == %c\n", c32[1]); return 1; }
  if (c32[2] != '0') { printf("fail: c32[2] == %c\n", c32[2]); return 1; }
  if (c32[3] != '0') { printf("fail: c32[3] == %c\n", c32[3]); return 1; }
  if (c32[4] != '0') { printf("fail: c32[4] == %c\n", c32[4]); return 1; }

  u32 = 0xdeadfaceU;
  c32[fmt_u32x(c32, u32)] = 0;
  if (c32[0] != 'd') { printf("fail: c32[0] == %c\n", c32[0]); return 1; }
  if (c32[1] != 'e') { printf("fail: c32[1] == %c\n", c32[1]); return 1; }
  if (c32[2] != 'a') { printf("fail: c32[2] == %c\n", c32[2]); return 1; }
  if (c32[3] != 'd') { printf("fail: c32[3] == %c\n", c32[3]); return 1; }
  if (c32[4] != 'f') { printf("fail: c32[4] == %c\n", c32[4]); return 1; }
  if (c32[5] != 'a') { printf("fail: c32[5] == %c\n", c32[5]); return 1; }
  if (c32[6] != 'c') { printf("fail: c32[6] == %c\n", c32[6]); return 1; }
  if (c32[7] != 'e') { printf("fail: c32[7] == %c\n", c32[7]); return 1; }

  u32 = 0123456U;
  c32[fmt_u32o(c32, u32)] = 0;
  if (c32[0] != '1') { printf("fail: c32[0] == %c\n", c32[0]); return 1; }
  if (c32[1] != '2') { printf("fail: c32[1] == %c\n", c32[1]); return 1; }
  if (c32[2] != '3') { printf("fail: c32[2] == %c\n", c32[2]); return 1; }
  if (c32[3] != '4') { printf("fail: c32[3] == %c\n", c32[3]); return 1; }
  if (c32[4] != '5') { printf("fail: c32[4] == %c\n", c32[4]); return 1; }
  if (c32[5] != '6') { printf("fail: c32[5] == %c\n", c32[5]); return 1; }

  /* u64 */

  u64 = 12302652060662212828ULL;
  c64[fmt_u64(c64, u64)] = 0;  
  if (c64[0] != '1') { printf("fail: c64[0] == %c\n", c64[0]); return 1; }
  if (c64[1] != '2') { printf("fail: c64[1] == %c\n", c64[1]); return 1; }
  if (c64[2] != '3') { printf("fail: c64[2] == %c\n", c64[2]); return 1; }
  if (c64[3] != '0') { printf("fail: c64[3] == %c\n", c64[3]); return 1; }
  if (c64[4] != '2') { printf("fail: c64[4] == %c\n", c64[4]); return 1; }
  if (c64[5] != '6') { printf("fail: c64[5] == %c\n", c64[5]); return 1; }
  if (c64[6] != '5') { printf("fail: c64[6] == %c\n", c64[6]); return 1; }
  if (c64[7] != '2') { printf("fail: c64[7] == %c\n", c64[7]); return 1; }
  if (c64[8] != '0') { printf("fail: c64[8] == %c\n", c64[8]); return 1; }
  if (c64[9] != '6') { printf("fail: c64[9] == %c\n", c64[9]); return 1; }
  if (c64[10] != '0') { printf("fail: c64[10] == %c\n", c64[10]); return 1; }
  if (c64[11] != '6') { printf("fail: c64[11] == %c\n", c64[11]); return 1; }
  if (c64[12] != '6') { printf("fail: c64[12] == %c\n", c64[12]); return 1; }
  if (c64[13] != '2') { printf("fail: c64[13] == %c\n", c64[13]); return 1; }
  if (c64[14] != '2') { printf("fail: c64[14] == %c\n", c64[14]); return 1; }
  if (c64[15] != '1') { printf("fail: c64[15] == %c\n", c64[15]); return 1; }
  if (c64[16] != '2') { printf("fail: c64[16] == %c\n", c64[16]); return 1; }
  if (c64[17] != '8') { printf("fail: c64[17] == %c\n", c64[17]); return 1; }
  if (c64[18] != '2') { printf("fail: c64[18] == %c\n", c64[18]); return 1; }
  if (c64[19] != '8') { printf("fail: c64[19] == %c\n", c64[19]); return 1; }

  u64 = 0xaabbccddeeffaabbULL;
  c64[fmt_u64x(c64, u64)] = 0;
  if (c64[0] != 'a') { printf("fail: c64[0] == %c\n", c64[0]); return 1; }
  if (c64[1] != 'a') { printf("fail: c64[1] == %c\n", c64[1]); return 1; }
  if (c64[2] != 'b') { printf("fail: c64[2] == %c\n", c64[2]); return 1; }
  if (c64[3] != 'b') { printf("fail: c64[3] == %c\n", c64[3]); return 1; }
  if (c64[4] != 'c') { printf("fail: c64[4] == %c\n", c64[4]); return 1; }
  if (c64[5] != 'c') { printf("fail: c64[5] == %c\n", c64[5]); return 1; }
  if (c64[6] != 'd') { printf("fail: c64[6] == %c\n", c64[6]); return 1; }
  if (c64[7] != 'd') { printf("fail: c64[7] == %c\n", c64[7]); return 1; }
  if (c64[8] != 'e') { printf("fail: c64[8] == %c\n", c64[8]); return 1; }
  if (c64[9] != 'e') { printf("fail: c64[9] == %c\n", c64[9]); return 1; }
  if (c64[10] != 'f') { printf("fail: c64[10] == %c\n", c64[10]); return 1; }
  if (c64[11] != 'f') { printf("fail: c64[11] == %c\n", c64[11]); return 1; }
  if (c64[12] != 'a') { printf("fail: c64[12] == %c\n", c64[12]); return 1; }
  if (c64[13] != 'a') { printf("fail: c64[13] == %c\n", c64[13]); return 1; }
  if (c64[14] != 'b') { printf("fail: c64[14] == %c\n", c64[14]); return 1; }
  if (c64[15] != 'b') { printf("fail: c64[15] == %c\n", c64[15]); return 1; }

  u64 = 01252736315675677724000ULL;
  c64[fmt_u64o(c64, u64)] = 0;
  if (c64[0] != '1') { printf("fail: c64[0] == %c\n", c64[0]); return 1; }
  if (c64[1] != '2') { printf("fail: c64[1] == %c\n", c64[1]); return 1; }
  if (c64[2] != '5') { printf("fail: c64[2] == %c\n", c64[2]); return 1; }
  if (c64[3] != '2') { printf("fail: c64[3] == %c\n", c64[3]); return 1; }
  if (c64[4] != '7') { printf("fail: c64[4] == %c\n", c64[4]); return 1; }
  if (c64[5] != '3') { printf("fail: c64[5] == %c\n", c64[5]); return 1; }
  if (c64[6] != '6') { printf("fail: c64[6] == %c\n", c64[6]); return 1; }
  if (c64[7] != '3') { printf("fail: c64[7] == %c\n", c64[7]); return 1; }
  if (c64[8] != '1') { printf("fail: c64[8] == %c\n", c64[8]); return 1; }
  if (c64[9] != '5') { printf("fail: c64[9] == %c\n", c64[9]); return 1; }
  if (c64[10] != '6') { printf("fail: c64[10] == %c\n", c64[10]); return 1; }
  if (c64[11] != '7') { printf("fail: c64[11] == %c\n", c64[11]); return 1; }
  if (c64[12] != '5') { printf("fail: c64[12] == %c\n", c64[12]); return 1; }
  if (c64[13] != '6') { printf("fail: c64[13] == %c\n", c64[13]); return 1; }
  if (c64[14] != '7') { printf("fail: c64[14] == %c\n", c64[14]); return 1; }
  if (c64[15] != '7') { printf("fail: c64[15] == %c\n", c64[15]); return 1; }
  if (c64[16] != '7') { printf("fail: c64[16] == %c\n", c64[16]); return 1; }
  if (c64[17] != '2') { printf("fail: c64[17] == %c\n", c64[17]); return 1; }
  if (c64[18] != '4') { printf("fail: c64[18] == %c\n", c64[18]); return 1; }
  if (c64[19] != '0') { printf("fail: c64[19] == %c\n", c64[19]); return 1; }
  if (c64[20] != '0') { printf("fail: c64[20] == %c\n", c64[20]); return 1; }
  if (c64[21] != '0') { printf("fail: c64[21] == %c\n", c64[21]); return 1; }

  return 0;
}
