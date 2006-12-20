#include "../buffer.h"
#include "../base_name.h"
#include "../str.h"
#include "../syserr.h"

struct exp {
  const char *given;
  const char *expected;
};

static const struct exp explist[] = {
  {"", "."},
  {"/", "/"},
  {"////////", "/"},
  {"/./././././", "."},
  {"..", ".."},
  {".", "."},
  {"/path/path/file", "file"},
  {"/path/path/file/", "file"},
  {"../../path/path/file////", "file"},
  {"./", "."},
  {"path", "path"},
};

int main()
{
  char *newname;
  unsigned int ind;
  
  for (ind = 0; ind < sizeof(explist) / sizeof(struct exp); ++ind) {
    if (!base_name(explist[ind].given, &newname))
      syserr_die2x(1, "fail: base_name returned 0 for ", explist[ind].given);
    if (!str_same(explist[ind].expected, newname))
      syserr_die6x(1, "fail: base_name returned ", newname, " for ", 
                   explist[ind].given, " expected ",
                   explist[ind].expected);
  }

  return 0;
}
