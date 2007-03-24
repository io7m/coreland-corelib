#include "../dir_hash.h"
#include "../syserr.h"

int main(void)
{
  struct dir_hash dh;

  if (!dir_hash_init(&dh, "testdata/dir_hash"))
    syserr_die1sys(1, "fatal: dir_hash_init: ");

  if (!dir_hash_check(&dh, "file001"))
    syserr_die1x(1, "fail: file001 not in table");

  if (!dir_hash_check(&dh, "file001"))
    syserr_die1x(1, "fail: file001 not in table");
  if (!dir_hash_check(&dh, "file002"))
    syserr_die1x(1, "fail: file002 not in table");
  if (!dir_hash_check(&dh, "file003"))
    syserr_die1x(1, "fail: file003 not in table");
  if (!dir_hash_check(&dh, "file004"))
    syserr_die1x(1, "fail: file004 not in table");
  if (!dir_hash_check(&dh, "file005"))
    syserr_die1x(1, "fail: file005 not in table");
  if (!dir_hash_check(&dh, "file006"))
    syserr_die1x(1, "fail: file006 not in table");
  if (!dir_hash_check(&dh, "file007"))
    syserr_die1x(1, "fail: file007 not in table");
  if (!dir_hash_check(&dh, "file008"))
    syserr_die1x(1, "fail: file008 not in table");

  if (!dir_hash_check(&dh, "A"))
    syserr_die1x(1, "fail: A not in table");
  if (!dir_hash_check(&dh, "B"))
    syserr_die1x(1, "fail: B not in table");
  if (!dir_hash_check(&dh, "C"))
    syserr_die1x(1, "fail: C not in table");
  if (!dir_hash_check(&dh, "D"))
    syserr_die1x(1, "fail: D not in table");
  if (!dir_hash_check(&dh, "E"))
    syserr_die1x(1, "fail: E not in table");
  if (!dir_hash_check(&dh, "F"))
    syserr_die1x(1, "fail: F not in table");
  if (!dir_hash_check(&dh, "G"))
    syserr_die1x(1, "fail: G not in table");
  if (!dir_hash_check(&dh, "H"))
    syserr_die1x(1, "fail: H not in table");

  dir_hash_free(&dh);
  return 0;
}
