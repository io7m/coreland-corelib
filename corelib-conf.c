#include "buffer.h"
#include "ctxt.h"
#include "get_opt.h"
#include "str.h"
#include "syserr.h"

const char progname[] = "corelib-config";

void usage()
{
  syserr_warn2x(progname, ": usage: [-ILhnV]");
}
void help()
{
  syserr_warn1x(
"  -I: print C include location\n"
"  -L: print library location\n"
"  -V: print library version\n"
"  -c: print output as compiler flags, if applicable\n"
"  -h: this message\n"
"  -n: print trailing newline");
}

int main(int argc, char *argv[])
{
  int flag_incdir;
  int flag_libdir;
  int flag_nl;
  int flag_ver;
  int flag_comp;
  char ch;

  flag_comp = 0;
  flag_ver = 0;
  flag_nl = 0;
  flag_incdir = 0;
  flag_libdir = 0;

  if (argc < 2) { usage(); return 111; }

  while ((ch = get_opt(argc, argv, "ILVchn")) != opteof)
    switch (ch) {
      case 'I': flag_incdir = 1; break;
      case 'L': flag_libdir = 1; break;
      case 'c': flag_comp = 1; break;
      case 'h': usage(); help(); return 0; break;
      case 'n': flag_nl = 1; break;
      case 'V': flag_ver = 1; break;
       default: usage(); return 111; break;
    }

  if (flag_ver) {
    buffer_puts(buffer1, ctxt_version);
    buffer_puts(buffer1, " ");
  }
  if (flag_incdir) {
    if (flag_comp) buffer_puts(buffer1, "-I");
    buffer_puts(buffer1, ctxt_incdir);
    if (flag_comp) {
      buffer_puts(buffer1, " ");
      buffer_puts(buffer1, "-I");
      buffer_put(buffer1, ctxt_incdir, str_rchr(ctxt_incdir, '/'));
      buffer_puts(buffer1, " ");
    }
  }
  if (flag_libdir) {
    if (flag_comp) buffer_puts(buffer1, "-L");
    buffer_puts(buffer1, ctxt_libdir);
    if (flag_comp) {
      buffer_puts(buffer1, " ");
      buffer_puts(buffer1, "-L");
      buffer_put(buffer1, ctxt_libdir, str_rchr(ctxt_libdir, '/'));
      buffer_puts(buffer1, " ");
    }
  }
  if (flag_nl) {
    buffer_puts(buffer1, "\n");
  }
  if (buffer_flush(buffer1) == -1)
    syserr_die2sys(112, progname, ": fatal: write: ");

  return 0;
}
