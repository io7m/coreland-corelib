#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../scan.h"

struct int_str {
  unsigned int sz;
  unsigned int base;
  const char *str;
  unsigned long long n;
};

#define UINT 1
#define ULONGLONG 2

static struct int_str int_list[] = {
  { UINT,      10, "2147483648",         2147483648U            },
  { UINT,      16, "80000000",           0x80000000U            },
  { UINT,      8,  "20000000000",        020000000000U          },
  { ULONGLONG, 10, "4503599627370480",   4503599627370480ULL    },
  { ULONGLONG, 16, "ffffffffffff0",      0xffffffffffff0ULL     },
  { ULONGLONG, 16, "16FC461",            0x16FC461ULL           },
  { ULONGLONG, 8,  "177777777777777760", 0177777777777777760ULL },
  { 0, 0, 0, 0 },
};

int main()
{
  unsigned int ui;
  unsigned long long ull;
  unsigned int i;

  i = 0;
  for (;;) {
    switch (int_list[i].sz) {
      case 0: return 0; break;
      case UINT:
        ui = 0;
        switch (int_list[i].base) {
          case 10:
            scan_uint(int_list[i].str, &ui);
            if (ui != (unsigned int) int_list[i].n) {
              printf("fail: scan_uint: [%u] ui == %u\n", i, ui); return 1;
            }
            break;
          case 16:
            scan_uintx(int_list[i].str, &ui);
            if (ui != (unsigned int) int_list[i].n) {
              printf("fail: scan_uintx: [%u] ui == %x\n", i, ui); return 1;
            }
            break;
          case 8:
            scan_uinto(int_list[i].str, &ui);
            if (ui != (unsigned int) int_list[i].n) {
              printf("fail: scan_uinto: [%u] ui == %o\n", i, ui); return 1;
            }
            break;
          default: break;
        }
        break;
      case ULONGLONG:
        ull = 0;
        switch (int_list[i].base) {
          case 10:
            scan_ulonglong(int_list[i].str, &ull);
            if (ull != (unsigned long long) int_list[i].n) {
              printf("fail: scan_ulonglong: [%u] ull == %llu\n", i, ull); return 1;
            }
            break;
          case 16:
            scan_ulonglongx(int_list[i].str, &ull);
            if (ull != (unsigned long long) int_list[i].n) {
              printf("fail: scan_ulonglongx: [%u] ull == %llx\n", i, ull); return 1;
            }
            break;
          case 8:
            scan_ulonglongo(int_list[i].str, &ull);
            if (ull != (unsigned long long) int_list[i].n) {
              printf("fail: scan_ulonglongo: [%u] ull == %llo\n", i, ull); return 1;
            }
            break;
          default: break;
        }
        break;
      default: break;
    }
    ++i;
  }

  return 0;
}
