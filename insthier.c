#include "install.h"
#include "ctxt.h"

/* generate AFTER build, or generated headers will be missing! */

struct install_item insthier[] = {
  {INST_MKDIR, 0, 0, ctxt_bindir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_incdir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_dlibdir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_slibdir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_repos, 0, 0, 0755},
  {INST_COPY, "alloc.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "array.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "array_bytes.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "array_cat.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "array_chop.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "array_copy.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "array_data.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "array_index.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "array_size.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "array_trunc.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "array_zero.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "base_name.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "bin_char.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "bin_chr.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "bin_copy.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "bin_copyr.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "bin_count.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "bin_diff.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "bin_rchar.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "bin_rchr.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "bin_set.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "bin_tolower.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "bin_toupper.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "bin_zero.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "buffer0.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "buffer1.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "buffer2.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "buffer_copy.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "buffer_get.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "buffer_init.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "buffer_put.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "closeonexec.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "corelib-conf.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dgetline_chop.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dgetline_data.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dgetline_free.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dgetline_get.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dgetline_init.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dgetline_lnum.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dgetline_size.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dir_array.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dir_hash.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dir_name.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dstring_0.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dstring_cat.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dstring_catb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dstring_cats.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dstring_chop.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dstring_copy.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dstring_cpyb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dstring_cpys.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dstring_data.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dstring_init.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dstring_size.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dstring_trunc.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "env.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "env_get.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "error.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "error_str.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fd_dup.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fd_move.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fd_reset.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fd_seek_cur.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fd_seek_end.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fd_seek_pos.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fd_seek_start.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_char.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_charb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_charo.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_charx.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_double.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_float.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_int.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_intb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_into.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_intx.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_llong.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_llongb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_llongo.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_llongx.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_long.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_longb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_longo.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_longx.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_nstr.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_pad_c.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_pad_i.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_pad_l.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_pad_ll.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_pad_s.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_short.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_shortb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_shorto.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_shortx.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_str.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "get_opt.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ht_addb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ht_adds.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ht_bytes.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ht_checkb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ht_checks.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ht_deleteb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ht_deletes.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ht_free.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ht_getb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ht_gets.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ht_hash.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ht_init.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ht_iter.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ht_replaceb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ht_replaces.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "iarray_bytes.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "iarray_cat.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "iarray_chop.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "iarray_copy.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "iarray_free.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "iarray_index.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "iarray_init.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "iarray_insert.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "iarray_node.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "iarray_remove.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "iarray_size.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "iarray_sort.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "iarray_trunc.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "iarray_zero.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "nonblock.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "open_append.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "open_creat.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "open_excl.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "open_ro.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "open_rw.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "open_trunc.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "open_wo.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sarray_bytes.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sarray_cat.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sarray_chop.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sarray_data.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sarray_index.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sarray_init.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sarray_size.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sarray_trunc.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_char.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_charb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_charo.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_charset.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_charx.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_double.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_float.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_int.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_intb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_into.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_intx.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_llong.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_llongb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_llongo.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_llongx.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_long.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_longb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_longo.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_longx.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_ncharset.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_newline.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_short.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_shortb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_shorto.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_shortx.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan_space.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sgetline.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sgetline_chop.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sgetline_data.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sgetline_get.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sgetline_lnum.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sgetline_size.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sig.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sig_block.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sig_catch.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sig_pause.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "squeue_bytes.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "squeue_data.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "squeue_deq.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "squeue_enq.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "squeue_init.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "squeue_peek.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "squeue_size.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstack_bytes.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstack_data.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstack_init.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstack_peek.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstack_pop.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstack_push.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstack_size.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstring_0.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstring_cat.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstring_catb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstring_cats.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstring_chop.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstring_copy.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstring_cpyb.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstring_cpys.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstring_init.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "stalloc.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "str_char.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "str_chr.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "str_ci_diff.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "str_ci_ndiff.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "str_diff.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "str_dup.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "str_ends.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "str_len.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "str_ndiff.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "str_rchar.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "str_rchr.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "str_starts.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "str_tolower.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "str_toupper.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "syserr_die.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "syserr_init.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "uint_pack.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "uint_unpack.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "_direntry.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "_direntry.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "_sig_action.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "_sig_action.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "_sig_pmask.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "_sig_pmask.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "alloc.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "alloc.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "array.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "array.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "base_name.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "base_name.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "bin.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "bin.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "buffer.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "buffer.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "byteorder.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "byteorder.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "close.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "close.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "closeonexec.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "closeonexec.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "dgetline.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dgetline.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "dir_array.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dir_array.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "dir_hash.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dir_hash.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "dir_name.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dir_name.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "direntry.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "direntry.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "dstring.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dstring.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "env.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "env.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "error.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "error.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "exit.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "exit.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "fd.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fd.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "fd_seek.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fd_seek.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "fmt.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "fmt_pad.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt_pad.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "get_opt.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "get_opt.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "hashtable.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "hashtable.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "iarray.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "iarray.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "nonblock.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "nonblock.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "open.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "open.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "read.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "read.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "sarray.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sarray.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "scan.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "sgetline.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sgetline.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "sig.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sig.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "sig_action.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sig_action.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "sig_pmask.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sig_pmask.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "squeue.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "squeue.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "sstack.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstack.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "sstring.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstring.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "stalloc.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "stalloc.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "str.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "str.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "syserr.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "syserr.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "uint.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "uint.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "write.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "write.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "alloc.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "alloc.a", "liballoc.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "array.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "array.a", "libarray.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "base_name.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "base_name.a", "libbase_name.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "bin.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "bin.a", "libbin.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "buffer.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "buffer.a", "libbuffer.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "closeonexec.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "closeonexec.a", "libcloseonexec.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "dgetline.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dgetline.a", "libdgetline.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "dir_array.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dir_array.a", "libdir_array.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "dir_hash.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dir_hash.a", "libdir_hash.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "dir_name.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dir_name.a", "libdir_name.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "dstring.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "dstring.a", "libdstring.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "env.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "env.a", "libenv.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "error.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "error.a", "liberror.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "fd.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fd.a", "libfd.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "fd_seek.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fd_seek.a", "libfd_seek.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "fmt.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "fmt.a", "libfmt.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "get_opt.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "get_opt.a", "libget_opt.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "hashtable.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "hashtable.a", "libhashtable.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "iarray.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "iarray.a", "libiarray.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "nonblock.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "nonblock.a", "libnonblock.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "open.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "open.a", "libopen.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "sarray.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sarray.a", "libsarray.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "scan.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "scan.a", "libscan.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "sgetline.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sgetline.a", "libsgetline.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "sig.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sig.a", "libsig.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "squeue.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "squeue.a", "libsqueue.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "sstack.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstack.a", "libsstack.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "sstring.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "sstring.a", "libsstring.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "stalloc.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "stalloc.a", "libstalloc.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "str.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "str.a", "libstr.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "syserr.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "syserr.a", "libsyserr.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "uint.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "uint.a", "libuint.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "corelib-conf.ld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "corelib-conf", 0, ctxt_bindir, 0, 0, 0755},
};
unsigned long insthier_len = sizeof(insthier) / sizeof(struct install_item);
