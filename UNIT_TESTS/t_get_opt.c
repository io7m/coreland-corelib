#include <stdio.h>
#include "../get_opt.h"

/* needs error condition testing */

static int flags8_1[] = {0, 0, 0, 0, 0, 0, 0, 0};

int main(void)
{
  int ch;
  char *opt8_1;
  char *argv8_1[12];
  int argc8_1 = 12;

  opt8_1 = "abcdef:g:h:";
  argv8_1[0] = "./prog";
  argv8_1[1] = "-a";
  argv8_1[2] = "-b";
  argv8_1[3] = "-c";
  argv8_1[4] = "-d";
  argv8_1[5] = "-e";
  argv8_1[6] = "-f";
  argv8_1[7] = "file";
  argv8_1[8] = "-g";
  argv8_1[9] = "file2";
  argv8_1[10] = "-h";
  argv8_1[11] = "file3";
  argc8_1 = 12;

  while ((ch = get_opt(argc8_1, argv8_1, opt8_1)) != opteof)
    switch (ch) {
      case 'a': flags8_1[0] = 1; break;
      case 'b': flags8_1[1] = 1; break;
      case 'c': flags8_1[2] = 1; break;
      case 'd': flags8_1[3] = 1; break;
      case 'e': flags8_1[4] = 1; break;
      case 'f':
        if (!optarg) { printf("fail: f: optarg == 0\n"); return 1; }
        flags8_1[5] = 1; break;
      case 'g':
        if (!optarg) { printf("fail: g: optarg == 0\n"); return 1; }
        flags8_1[6] = 1; break;
      case 'h':
        if (!optarg) { printf("fail: h: optarg == 0\n"); return 1; }
        flags8_1[7] = 1; break;
      default:
        printf("fail: ended up in switch default statement!\n");
        return 1;
        break; 
    }

  if (!flags8_1[0]) { printf("fail: flags[%u] not set\n", 0); return 1; }
  if (!flags8_1[1]) { printf("fail: flags[%u] not set\n", 1); return 1; }
  if (!flags8_1[2]) { printf("fail: flags[%u] not set\n", 2); return 1; }
  if (!flags8_1[3]) { printf("fail: flags[%u] not set\n", 3); return 1; }
  if (!flags8_1[4]) { printf("fail: flags[%u] not set\n", 4); return 1; }
  if (!flags8_1[5]) { printf("fail: flags[%u] not set\n", 5); return 1; }
  if (!flags8_1[6]) { printf("fail: flags[%u] not set\n", 6); return 1; }
  if (!flags8_1[7]) { printf("fail: flags[%u] not set\n", 7); return 1; }

  return 0;
}
