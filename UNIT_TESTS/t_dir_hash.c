#include "../dir_hash.h"
#include "../syserr.h"

int main()
{
  dir_hash dh;

  if (!dir_hash_init(&dh, "testdata/dir_hash"))
    syserr_die1sys(1, "fatal: dir_hash_init: ");

  if (!dir_hash_check(&dh, "file001"))
    syserr_die1x(1, "file001 not in table");

  if (!dir_hash_check(&dh, "file001"))
    syserr_die1x(1, "file001 not in table");
  if (!dir_hash_check(&dh, "file002"))
    syserr_die1x(1, "file002 not in table");
  if (!dir_hash_check(&dh, "file003"))
    syserr_die1x(1, "file003 not in table");
  if (!dir_hash_check(&dh, "file004"))
    syserr_die1x(1, "file004 not in table");
  if (!dir_hash_check(&dh, "file005"))
    syserr_die1x(1, "file005 not in table");
  if (!dir_hash_check(&dh, "file006"))
    syserr_die1x(1, "file006 not in table");
  if (!dir_hash_check(&dh, "file007"))
    syserr_die1x(1, "file007 not in table");
  if (!dir_hash_check(&dh, "file008"))
    syserr_die1x(1, "file008 not in table");

  if (!dir_hash_check(&dh, "A"))
    syserr_die1x(1, "A not in table");
  if (!dir_hash_check(&dh, "B"))
    syserr_die1x(1, "B not in table");
  if (!dir_hash_check(&dh, "C"))
    syserr_die1x(1, "C not in table");
  if (!dir_hash_check(&dh, "D"))
    syserr_die1x(1, "D not in table");
  if (!dir_hash_check(&dh, "E"))
    syserr_die1x(1, "E not in table");
  if (!dir_hash_check(&dh, "F"))
    syserr_die1x(1, "F not in table");
  if (!dir_hash_check(&dh, "G"))
    syserr_die1x(1, "G not in table");
  if (!dir_hash_check(&dh, "H"))
    syserr_die1x(1, "H not in table");

  dir_hash_free(&dh);
  return 0;
}
