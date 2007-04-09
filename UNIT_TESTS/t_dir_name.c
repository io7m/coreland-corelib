#include "../buffer.h"
#include "../dir_name.h"
#include "../str.h"
#include "../syserr.h"
#include "t_assert.h"

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
    test_assert(dir_name(explist[ind].given, &newname));
    test_assert(str_same(explist[ind].expected, newname));
  }

  return 0;
}
