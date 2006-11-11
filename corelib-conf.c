#include "buffer.h"
#include "ctxt.h"
#include "get_opt.h"
#include "str.h"
#include "syserr.h"

const char progname[] = "corelib-config";

void usage()
{
  syserr_warn2x(progname, ": usage: [-ILchnsV]");
}
void help()
{
  syserr_warn1x(
"  -I: print C include location\n"
"  -L: print library location\n"
"  -V: print library version\n"
"  -c: print output as compiler flags, if applicable\n"
"  -s: print output for compiling against static libraries\n"
"  -h: this message\n"
"  -n: print trailing newline");
}

#define FLAG_INCDIR  0x0001
#define FLAG_LIBDIR  0x0002
#define FLAG_NEWLINE 0x0004
#define FLAG_VER     0x0008
#define FLAG_COMP    0x0010
#define FLAG_STATIC  0x0020

int main(int argc, char *argv[])
{
  unsigned int flag;
  int ch;

  if (argc < 2) { usage(); return 111; }

  flag = 0;
  while ((ch = get_opt(argc, argv, "ILVchns")) != opteof)
    switch (ch) {
      case 'I': flag |= FLAG_INCDIR; break;
      case 'L': flag |= FLAG_LIBDIR; break;
      case 'c': flag |= FLAG_COMP; break;
      case 'h': usage(); help(); return 0; break;
      case 'n': flag |= FLAG_NEWLINE; break;
      case 's': flag |= FLAG_STATIC; break;
      case 'V': flag |= FLAG_VER; break;
       default: usage(); return 111; break;
    }

  if (flag & FLAG_VER) {
    buffer_puts(buffer1, ctxt_version);
    buffer_puts(buffer1, " ");
  }
  if (flag & FLAG_INCDIR) {
    if (flag & FLAG_COMP) {
      buffer_puts(buffer1, "-I");
      buffer_put(buffer1, ctxt_incdir, str_rchr(ctxt_incdir, '/'));
      buffer_puts(buffer1, " ");
    } else {
      buffer_puts(buffer1, ctxt_incdir);
    }
  }
  if (flag & FLAG_LIBDIR) {
    if (flag & FLAG_COMP) buffer_puts(buffer1, "-L");
    if (flag & FLAG_STATIC)
      buffer_puts(buffer1, ctxt_slibdir);
    else
      buffer_puts(buffer1, ctxt_dlibdir);
    buffer_puts(buffer1, " ");
  }
  if (flag & FLAG_NEWLINE) {
    buffer_puts(buffer1, "\n");
  }
  if (buffer_flush(buffer1) == -1)
    syserr_die2sys(112, progname, ": fatal: write: ");

  return 0;
}
