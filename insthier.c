#include "ctxt.h"
#include "install.h"

const struct install_item insthier[] = {
  {0, 0, ctxt_bindir, 0755, ctxt_owner, ctxt_group},
  {0, 0, ctxt_incdir, 0755, ctxt_owner, ctxt_group},
  {0, 0, ctxt_libdir, 0755, ctxt_owner, ctxt_group},
  {0, 0, ctxt_repos, 0755, ctxt_owner, ctxt_group},
  {"alloc.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"array.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"array_bytes.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"array_cat.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"array_chop.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"array_copy.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"array_data.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"array_index.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"array_size.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"base_name.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"bin_chr.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"bin_copy.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"bin_copyr.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"bin_count.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"bin_diff.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"bin_rchr.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"bin_set.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"bin_tolower.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"bin_toupper.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"bin_zero.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"buffer0.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"buffer1.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"buffer2.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"buffer_copy.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"buffer_get.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"buffer_init.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"buffer_put.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"closeonexec.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dir_array.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dir_hash.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dir_name.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dstring_0.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dstring_cat.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dstring_cat0.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dstring_catb.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dstring_cats.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dstring_chop.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dstring_copy.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dstring_cpyb.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dstring_cpys.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dstring_init.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dstring_trunc.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"env.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"env_get.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"error.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"error_str.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fd_dup.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fd_move.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fd_reset.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"float32_pack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"float32_upack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"float64_pack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"float64_upack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_nstr.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_str.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_u32.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_u32o.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_u32x.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_u64.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_u64o.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_u64x.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_uchar.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_ucharo.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_ucharx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_uint.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_uinto.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_uintx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_ullong.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_ullongo.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_ullongx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_ulong.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_ulongo.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_ulongx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_ushort.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_ushorto.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_ushortx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"get_opt.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"ht_addb.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"ht_adds.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"ht_addu32.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"ht_bytes.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"ht_deleteb.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"ht_deletes.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"ht_destroy.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"ht_getb.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"ht_gets.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"ht_getu32.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"ht_hash.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"ht_init.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"ht_replaceb.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"ht_replaces.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"int16_pack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"int16_unpack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"int32_pack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"int32_unpack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"int64_pack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"int64_unpack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"nonblock.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"open_append.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"open_creat.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"open_excl.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"open_ro.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"open_rw.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"open_trunc.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"open_wo.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_charset.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_double.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_f32.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_f64.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_float.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_ncharset.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_newline.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_space.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_u32.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_u32o.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_u32x.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_u64.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_u64o.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_u64x.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_uchar.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_ucharo.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_ucharx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_uint.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_uinto.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_uintx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_ullong.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_ullongo.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_ullongx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_ulong.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_ulongo.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_ulongx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_ushort.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_ushorto.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_ushortx.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"seek_cur.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"seek_end.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"seek_pos.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"seek_start.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sgetline.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sgetline_chop.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sgetline_get.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sig_block.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sig_catch.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sig_pause.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"signal.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sstring_0.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sstring_cat.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sstring_catb.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sstring_cats.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sstring_chop.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sstring_copy.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sstring_cpyb.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sstring_cpys.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sstring_init.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sstring_trunc.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"stalloc.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"str_chr.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"str_copy.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"str_diff.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"str_dup.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"str_ends.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"str_len.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"str_ncopy.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"str_ndiff.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"str_rchr.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"str_starts.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"str_tolower.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"str_toupper.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"syserr_die.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"syserr_init.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"uint16_pack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"uint16_unpack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"uint32_pack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"uint32_unpack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"uint64_pack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"uint64_unpack.c", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"alloc.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"alloc.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"array.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"array.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"base_name.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"base_name.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"bin.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"bin.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"buffer.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"buffer.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"close.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"close.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"closeonexec.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"closeonexec.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"dir_array.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dir_array.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"dir_hash.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dir_hash.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"dir_name.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dir_name.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"dstring.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dstring.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"env.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"env.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"error.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"error.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"exit.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"exit.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"fd.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fd.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"float32.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"float32.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"float64.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"float64.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"fmt.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"fmt_fspec.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_fspec.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"fmt_spec.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_spec.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"get_opt.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"get_opt.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"hashtable.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"hashtable.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"int16.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"int16.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"int32.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"int32.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"int64.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"int64.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"nonblock.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"nonblock.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"open.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"open.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"read.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"read.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"scan.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"scan_fspec.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_fspec.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"scan_spec.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_spec.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"seek.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"seek.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"sgetline.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sgetline.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"signal.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"signal.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"sstring.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sstring.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"stalloc.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"stalloc.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"str.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"str.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"syserr.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"syserr.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"uint16.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"uint16.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"uint32.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"uint32.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"uint64.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"uint64.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"uint8.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"uint8.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"write.h", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"write.h", 0, ctxt_incdir, 0444, ctxt_owner, ctxt_group},
  {"alloc.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"alloc.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"array.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"array.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"base_name.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"base_name.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"bin.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"bin.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"buffer.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"buffer.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"closeonexec.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"closeonexec.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"dir_array.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dir_array.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"dir_hash.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dir_hash.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"dir_name.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dir_name.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"dstring.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"dstring.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"env.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"env.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"error.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"error.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"fd.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fd.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"float32.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"float32.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"float64.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"float64.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"fmt.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"fmt_spec.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"fmt_spec.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"get_opt.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"get_opt.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"hashtable.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"hashtable.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"int16.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"int16.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"int32.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"int32.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"int64.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"int64.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"nonblock.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"nonblock.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"open.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"open.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"scan.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"scan_fspec.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_fspec.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"scan_spec.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"scan_spec.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"seek.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"seek.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"sgetline.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sgetline.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"signal.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"signal.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"sstring.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"sstring.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"stalloc.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"stalloc.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"str.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"str.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"syserr.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"syserr.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"uint16.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"uint16.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"uint32.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"uint32.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"uint64.sld", 0, ctxt_repos, 0444, ctxt_owner, ctxt_group},
  {"uint64.a", 0, ctxt_libdir, 0444, ctxt_owner, ctxt_group},
  {"corelib-conf", 0, ctxt_bindir, 0755, ctxt_owner, ctxt_group},
};

const unsigned int insthier_size = sizeof(insthier) / sizeof(struct install_item);