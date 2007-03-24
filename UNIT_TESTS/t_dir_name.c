#include "../buffer.h"
#include "../dir_name.h"
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
  {"/./././././", "/./././."},
  {"..", "."},
  {".", "."},
  {"/path/path/file", "/path/path"},
  {"/path/path/file/", "/path/path"},
  {"../../path/path/file////", "../../path/path"},
  {"./", "."},
  {"path", "."},
};

int main(void)
{
  char *newname;
  unsigned int ind;
  
  for (ind = 0; ind < sizeof(explist) / sizeof(struct exp); ++ind) {
    if (!dir_name(explist[ind].given, &newname))
      syserr_die3x(1, "fail: dir_name returned 0 for \"", explist[ind].given, "\"");
    if (!str_same(explist[ind].expected, newname))
      syserr_die6x(1, "fail: dir_name returned ", newname, " for \"",
                   explist[ind].given, "\" expected ",
                   explist[ind].expected);
  }

  return 0;
}
