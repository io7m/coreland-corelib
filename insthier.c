#include "install.h"
#include "ctxt.h"

struct install_item insthier[] = {

ls: *.dld: No such file or directory
  {IOP_MKDIR, 0, 0, ctxt_bindir, 0755, ctxt_owner, ctxt_group},
  {IOP_MKDIR, 0, 0, ctxt_incdir, 0755, ctxt_owner, ctxt_group},
  {IOP_MKDIR, 0, 0, ctxt_dlibdir, 0755, ctxt_owner, ctxt_group},
  {IOP_MKDIR, 0, 0, ctxt_slibdir, 0755, ctxt_owner, ctxt_group},
  {IOP_MKDIR, 0, 0, ctxt_repos, 0755, ctxt_owner, ctxt_group},
  {IOP_COPY, "alloc.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "array.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "array_bytes.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "array_cat.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "array_chop.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "array_copy.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "array_data.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "array_index.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "array_size.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "base_name.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "bin_chr.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "bin_copy.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "bin_copyr.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "bin_count.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "bin_diff.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "bin_rchr.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "bin_set.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "bin_tolower.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "bin_toupper.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "bin_zero.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "buffer0.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "buffer1.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "buffer2.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "buffer_copy.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "buffer_get.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "buffer_init.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "buffer_put.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "closeonexec.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dir_array.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dir_hash.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dir_name.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dstring_0.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dstring_cat.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dstring_cat0.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dstring_catb.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dstring_cats.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dstring_chop.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dstring_copy.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dstring_cpyb.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dstring_cpys.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dstring_init.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dstring_trunc.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "env.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "env_get.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "error.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "error_str.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fd_dup.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fd_move.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fd_reset.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "float32_pack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "float32_upack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "float64_pack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "float64_upack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_nstr.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_str.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_u32.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_u32o.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_u32x.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_u64.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_u64o.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_u64x.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_uchar.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_ucharo.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_ucharx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_uint.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_uinto.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_uintx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_ullong.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_ullongo.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_ullongx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_ulong.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_ulongo.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_ulongx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_ushort.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_ushorto.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_ushortx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "get_opt.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "ht_addb.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "ht_adds.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "ht_addu32.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "ht_bytes.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "ht_deleteb.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "ht_deletes.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "ht_destroy.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "ht_getb.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "ht_gets.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "ht_getu32.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "ht_hash.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "ht_init.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "ht_replaceb.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "ht_replaces.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int16_pack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int16_unpack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int32_pack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int32_unpack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int64_pack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int64_unpack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "nonblock.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "open_append.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "open_creat.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "open_excl.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "open_ro.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "open_rw.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "open_trunc.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "open_wo.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_charset.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_double.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_f32.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_f64.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_float.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_ncharset.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_newline.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_space.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_u32.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_u32o.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_u32x.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_u64.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_u64o.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_u64x.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_uchar.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_ucharo.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_ucharx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_uint.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_uinto.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_uintx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_ullong.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_ullongo.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_ullongx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_ulong.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_ulongo.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_ulongx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_ushort.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_ushorto.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_ushortx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "seek_cur.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "seek_end.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "seek_pos.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "seek_start.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sgetline.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sgetline_chop.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sgetline_get.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sig_block.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sig_catch.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sig_pause.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "signal.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sstring_0.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sstring_cat.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sstring_catb.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sstring_cats.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sstring_chop.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sstring_copy.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sstring_cpyb.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sstring_cpys.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sstring_init.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sstring_trunc.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "stalloc.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "str_chr.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "str_diff.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "str_dup.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "str_ends.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "str_len.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "str_ndiff.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "str_rchr.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "str_starts.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "str_tolower.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "str_toupper.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "syserr_die.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "syserr_init.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint16_pack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint16_unpack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint32_pack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint32_unpack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint64_pack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint64_unpack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_direntry.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_direntry.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_endian.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_endian.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_float32.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_float32.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_float64.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_float64.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_int16.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_int16.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_int32.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_int32.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_int64.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_int64.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_sig_action.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_sig_action.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_sig_pmask.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_sig_pmask.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_uint16.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_uint16.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_uint32.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_uint32.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_uint64.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "_uint64.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "alloc.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "alloc.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "array.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "array.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "base_name.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "base_name.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "bin.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "bin.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "buffer.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "buffer.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "close.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "close.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "closeonexec.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "closeonexec.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dir_array.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dir_array.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dir_hash.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dir_hash.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dir_name.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dir_name.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "direntry.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "direntry.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dstring.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dstring.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "endian.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "endian.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "env.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "env.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "error.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "error.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "exit.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "exit.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fd.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fd.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "float32.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "float32.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "float64.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "float64.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_fspec.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_fspec.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_spec.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_spec.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "get_opt.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "get_opt.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "hashtable.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "hashtable.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int16.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int16.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int32.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int32.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int64.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int64.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "nonblock.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "nonblock.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "open.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "open.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "read.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "read.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_fspec.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_fspec.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_spec.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_spec.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "seek.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "seek.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sgetline.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sgetline.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sig_action.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sig_action.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sig_pmask.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sig_pmask.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "signal.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "signal.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sstring.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sstring.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "stalloc.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "stalloc.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "str.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "str.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "syserr.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "syserr.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint16.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint16.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint32.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint32.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint64.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint64.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint8.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint8.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "write.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "write.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "alloc.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "alloc.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "array.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "array.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "base_name.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "base_name.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "bin.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "bin.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "buffer.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "buffer.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "closeonexec.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "closeonexec.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dir_array.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dir_array.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dir_hash.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dir_hash.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dir_name.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dir_name.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dstring.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "dstring.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "env.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "env.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "error.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "error.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fd.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fd.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "float32.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "float32.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "float64.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "float64.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_spec.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "fmt_spec.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "get_opt.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "get_opt.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "hashtable.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "hashtable.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int16.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int16.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int32.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int32.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int64.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "int64.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "nonblock.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "nonblock.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "open.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "open.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_fspec.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_fspec.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_spec.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "scan_spec.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "seek.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "seek.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sgetline.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sgetline.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "signal.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "signal.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sstring.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "sstring.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "stalloc.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "stalloc.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "str.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "str.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "syserr.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "syserr.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint16.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint16.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint32.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint32.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint64.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "uint64.a", 0, ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_COPY, "corelib-conf", 0, ctxt_bindir, 0755, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "alloc.a", "liballoc.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "array.a", "libarray.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "base_name.a", "libbase_name.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "bin.a", "libbin.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "buffer.a", "libbuffer.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "closeonexec.a", "libcloseonexec.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "dir_array.a", "libdir_array.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "dir_hash.a", "libdir_hash.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "dir_name.a", "libdir_name.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "dstring.a", "libdstring.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "env.a", "libenv.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "error.a", "liberror.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "fd.a", "libfd.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "float32.a", "libfloat32.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "float64.a", "libfloat64.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "fmt.a", "libfmt.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "fmt_spec.a", "libfmt_spec.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "get_opt.a", "libget_opt.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "hashtable.a", "libhashtable.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "int16.a", "libint16.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "int32.a", "libint32.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "int64.a", "libint64.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "nonblock.a", "libnonblock.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "open.a", "libopen.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "scan.a", "libscan.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "scan_fspec.a", "libscan_fspec.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "scan_spec.a", "libscan_spec.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "seek.a", "libseek.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "sgetline.a", "libsgetline.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "signal.a", "libsignal.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "sstring.a", "libsstring.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "stalloc.a", "libstalloc.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "str.a", "libstr.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "syserr.a", "libsyserr.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "uint16.a", "libuint16.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "uint32.a", "libuint32.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
  {IOP_LIBLINK, "uint64.a", "libuint64.a", ctxt_slibdir, 0444, ctxt_owner, ctxt_group},
};
unsigned int insthier_size = sizeof(insthier) / sizeof(struct install_item);
