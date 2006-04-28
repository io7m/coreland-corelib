#include "open.h"

int open_excl(const char *f)
{
  return open(f, O_CREAT | O_EXCL | O_WRONLY, 0600);
}
