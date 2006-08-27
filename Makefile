# auto generated - do not edit
SHELL=/bin/sh
default: all
all: phase_sysdeps_local phase_sysdeps phase_tools_local phase_tools \
	phase_pregen_local phase_pregen phase_compile_local phase_compile \
	phase_library_local phase_library phase_link_local phase_link 
tests: phase_test
install: phase_install
install-check: phase_install_check
clean: phase_local_clean phase_sysdeps_clean phase_tools_clean \
	phase_pregen_clean phase_compile_clean phase_library_clean \
	phase_link_clean phase_test_clean 

#--LINK-----------------------------------------------------------------------

auto-text:\
	ld auto-text.ld auto-text.o 
	./ld auto-text auto-text.o 
corelib-conf:\
	ld corelib-conf.ld corelib-conf.o ctxt/ctxt.a \
	get_opt.a syserr.a buffer.a error.a bin.a str.a 
	./ld corelib-conf corelib-conf.o ctxt/ctxt.a get_opt.a syserr.a \
	buffer.a error.a bin.a str.a 
deinstaller:\
	ld deinstaller.ld deinstaller.o insthier.o \
	install_core.o install_error.o ctxt/ctxt.a 
	./ld deinstaller deinstaller.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
inst-check:\
	ld inst-check.ld inst-check.o install_error.o 
	./ld inst-check inst-check.o install_error.o 
inst-copy:\
	ld inst-copy.ld inst-copy.o install_error.o 
	./ld inst-copy inst-copy.o install_error.o 
inst-dir:\
	ld inst-dir.ld inst-dir.o install_error.o 
	./ld inst-dir inst-dir.o install_error.o 
inst-link:\
	ld inst-link.ld inst-link.o install_error.o 
	./ld inst-link inst-link.o install_error.o 
installer:\
	ld installer.ld installer.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
	./ld installer installer.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
instchk:\
	ld instchk.ld instchk.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
	./ld instchk instchk.o insthier.o install_core.o install_error.o \
	ctxt/ctxt.a 
mk-ctxt:\
	ld mk-ctxt.ld mk-ctxt.o 
	./ld mk-ctxt mk-ctxt.o 

phase_link: auto-text corelib-conf deinstaller inst-check inst-copy \
	inst-dir inst-link installer instchk mk-ctxt 
phase_link_clean:
	rm -f auto-text corelib-conf deinstaller \
	inst-check inst-copy inst-dir inst-link installer instchk mk-ctxt 

#--LIBRARY--------------------------------------------------------------------

alloc.a:\
	mk-slib alloc.sld alloc.o 
	./mk-slib alloc alloc.o 
array.a:\
	mk-slib array.sld array.o array_bytes.o array_cat.o \
	array_copy.o array_index.o array_size.o array_chop.o 
	./mk-slib array array.o array_bytes.o array_cat.o array_copy.o \
	array_index.o array_size.o array_chop.o 
base_name.a:\
	mk-slib base_name.sld base_name.o 
	./mk-slib base_name base_name.o 
bin.a:\
	mk-slib bin.sld bin_char.o bin_rchar.o bin_chr.o bin_copy.o \
	bin_copyr.o bin_count.o bin_diff.o bin_rchr.o bin_set.o \
	bin_tolower.o bin_toupper.o bin_zero.o 
	./mk-slib bin bin_char.o bin_rchar.o bin_chr.o bin_copy.o \
	bin_copyr.o bin_count.o bin_diff.o bin_rchr.o bin_set.o \
	bin_tolower.o bin_toupper.o bin_zero.o 
buffer.a:\
	mk-slib buffer.sld buffer0.o buffer1.o buffer2.o \
	buffer_get.o buffer_init.o buffer_put.o buffer_copy.o 
	./mk-slib buffer buffer0.o buffer1.o buffer2.o buffer_get.o \
	buffer_init.o buffer_put.o buffer_copy.o 
closeonexec.a:\
	mk-slib closeonexec.sld closeonexec.o 
	./mk-slib closeonexec closeonexec.o 
dir_array.a:\
	mk-slib dir_array.sld dir_array.o 
	./mk-slib dir_array dir_array.o 
dir_hash.a:\
	mk-slib dir_hash.sld dir_hash.o 
	./mk-slib dir_hash dir_hash.o 
dir_name.a:\
	mk-slib dir_name.sld dir_name.o 
	./mk-slib dir_name dir_name.o 
dstring.a:\
	mk-slib dstring.sld dstring_cpyb.o dstring_cpys.o \
	dstring_copy.o dstring_cat.o dstring_catb.o dstring_cats.o \
	dstring_cat0.o dstring_0.o dstring_chop.o dstring_init.o \
	dstring_trunc.o 
	./mk-slib dstring dstring_cpyb.o dstring_cpys.o dstring_copy.o \
	dstring_cat.o dstring_catb.o dstring_cats.o dstring_cat0.o \
	dstring_0.o dstring_chop.o dstring_init.o dstring_trunc.o 
env.a:\
	mk-slib env.sld env.o env_get.o 
	./mk-slib env env.o env_get.o 
error.a:\
	mk-slib error.sld error.o error_str.o 
	./mk-slib error error.o error_str.o 
fd.a:\
	mk-slib fd.sld fd_dup.o fd_move.o fd_reset.o 
	./mk-slib fd fd_dup.o fd_move.o fd_reset.o 
float32.a:\
	mk-slib float32.sld float32_pack.o float32_upack.o 
	./mk-slib float32 float32_pack.o float32_upack.o 
float64.a:\
	mk-slib float64.sld float64_pack.o float64_upack.o 
	./mk-slib float64 float64_pack.o float64_upack.o 
fmt.a:\
	mk-slib fmt.sld fmt_nstr.o fmt_str.o fmt_uchar.o \
	fmt_ucharo.o fmt_ucharx.o fmt_uint.o fmt_uinto.o fmt_uintx.o \
	fmt_ullong.o fmt_ullongo.o fmt_ullongx.o fmt_ulong.o fmt_ulongo.o \
	fmt_ulongx.o fmt_ushort.o fmt_ushorto.o fmt_ushortx.o 
	./mk-slib fmt fmt_nstr.o fmt_str.o fmt_uchar.o fmt_ucharo.o \
	fmt_ucharx.o fmt_uint.o fmt_uinto.o fmt_uintx.o fmt_ullong.o \
	fmt_ullongo.o fmt_ullongx.o fmt_ulong.o fmt_ulongo.o fmt_ulongx.o \
	fmt_ushort.o fmt_ushorto.o fmt_ushortx.o 
fmt_spec.a:\
	mk-slib fmt_spec.sld fmt_u32.o fmt_u32o.o fmt_u32x.o \
	fmt_u64.o fmt_u64o.o fmt_u64x.o 
	./mk-slib fmt_spec fmt_u32.o fmt_u32o.o fmt_u32x.o fmt_u64.o \
	fmt_u64o.o fmt_u64x.o 
get_opt.a:\
	mk-slib get_opt.sld get_opt.o 
	./mk-slib get_opt get_opt.o 
hashtable.a:\
	mk-slib hashtable.sld ht_init.o ht_hash.o ht_free.o \
	ht_addb.o ht_adds.o ht_deleteb.o ht_deletes.o ht_getb.o ht_gets.o \
	ht_replaceb.o ht_replaces.o ht_bytes.o 
	./mk-slib hashtable ht_init.o ht_hash.o ht_free.o ht_addb.o \
	ht_adds.o ht_deleteb.o ht_deletes.o ht_getb.o ht_gets.o \
	ht_replaceb.o ht_replaces.o ht_bytes.o 
int16.a:\
	mk-slib int16.sld int16_pack.o int16_unpack.o 
	./mk-slib int16 int16_pack.o int16_unpack.o 
int32.a:\
	mk-slib int32.sld int32_pack.o int32_unpack.o 
	./mk-slib int32 int32_pack.o int32_unpack.o 
int64.a:\
	mk-slib int64.sld int64_pack.o int64_unpack.o 
	./mk-slib int64 int64_pack.o int64_unpack.o 
nonblock.a:\
	mk-slib nonblock.sld nonblock.o 
	./mk-slib nonblock nonblock.o 
open.a:\
	mk-slib open.sld open_append.o open_creat.o open_excl.o \
	open_ro.o open_rw.o open_trunc.o open_wo.o 
	./mk-slib open open_append.o open_creat.o open_excl.o open_ro.o \
	open_rw.o open_trunc.o open_wo.o 
scan.a:\
	mk-slib scan.sld scan_charset.o scan_double.o scan_float.o \
	scan_ncharset.o scan_newline.o scan_space.o scan_uchar.o \
	scan_ucharo.o scan_ucharx.o scan_uint.o scan_uinto.o scan_uintx.o \
	scan_ullong.o scan_ullongo.o scan_ullongx.o scan_ulong.o \
	scan_ulongo.o scan_ulongx.o scan_ushort.o scan_ushorto.o \
	scan_ushortx.o 
	./mk-slib scan scan_charset.o scan_double.o scan_float.o \
	scan_ncharset.o scan_newline.o scan_space.o scan_uchar.o \
	scan_ucharo.o scan_ucharx.o scan_uint.o scan_uinto.o scan_uintx.o \
	scan_ullong.o scan_ullongo.o scan_ullongx.o scan_ulong.o \
	scan_ulongo.o scan_ulongx.o scan_ushort.o scan_ushorto.o \
	scan_ushortx.o 
scan_fspec.a:\
	mk-slib scan_fspec.sld scan_f32.o scan_f64.o 
	./mk-slib scan_fspec scan_f32.o scan_f64.o 
scan_spec.a:\
	mk-slib scan_spec.sld scan_u32.o scan_u32o.o \
	scan_u32x.o scan_u64.o scan_u64o.o scan_u64x.o 
	./mk-slib scan_spec scan_u32.o scan_u32o.o scan_u32x.o scan_u64.o \
	scan_u64o.o scan_u64x.o 
seek.a:\
	mk-slib seek.sld seek_cur.o seek_end.o seek_pos.o \
	seek_start.o 
	./mk-slib seek seek_cur.o seek_end.o seek_pos.o seek_start.o 
sgetline.a:\
	mk-slib sgetline.sld sgetline.o sgetline_chop.o \
	sgetline_get.o 
	./mk-slib sgetline sgetline.o sgetline_chop.o sgetline_get.o 
signal.a:\
	mk-slib signal.sld signal.o sig_block.o sig_catch.o \
	sig_pause.o 
	./mk-slib signal signal.o sig_block.o sig_catch.o sig_pause.o 
sstring.a:\
	mk-slib sstring.sld sstring_0.o sstring_cat.o \
	sstring_catb.o sstring_cats.o sstring_copy.o sstring_cpyb.o \
	sstring_cpys.o sstring_init.o sstring_trunc.o sstring_chop.o 
	./mk-slib sstring sstring_0.o sstring_cat.o sstring_catb.o \
	sstring_cats.o sstring_copy.o sstring_cpyb.o sstring_cpys.o \
	sstring_init.o sstring_trunc.o sstring_chop.o 
stalloc.a:\
	mk-slib stalloc.sld stalloc.o 
	./mk-slib stalloc stalloc.o 
str.a:\
	mk-slib str.sld str_char.o str_chr.o str_diff.o str_dup.o \
	str_ends.o str_len.o str_ndiff.o str_rchar.o str_rchr.o str_starts.o \
	str_tolower.o str_toupper.o 
	./mk-slib str str_char.o str_chr.o str_diff.o str_dup.o str_ends.o \
	str_len.o str_ndiff.o str_rchar.o str_rchr.o str_starts.o \
	str_tolower.o str_toupper.o 
syserr.a:\
	mk-slib syserr.sld syserr_die.o syserr_init.o 
	./mk-slib syserr syserr_die.o syserr_init.o 
uint16.a:\
	mk-slib uint16.sld uint16_pack.o uint16_unpack.o 
	./mk-slib uint16 uint16_pack.o uint16_unpack.o 
uint32.a:\
	mk-slib uint32.sld uint32_pack.o uint32_unpack.o 
	./mk-slib uint32 uint32_pack.o uint32_unpack.o 
uint64.a:\
	mk-slib uint64.sld uint64_pack.o uint64_unpack.o 
	./mk-slib uint64 uint64_pack.o uint64_unpack.o 
ctxt/ctxt.a:\
	mk-slib ctxt/ctxt.sld ctxt/ctxt_version.o \
	ctxt/ctxt_group.o ctxt/ctxt_bindir.o ctxt/ctxt_incdir.o \
	ctxt/ctxt_slibdir.o ctxt/ctxt_dlibdir.o ctxt/ctxt_owner.o \
	ctxt/ctxt_repos.o 
	./mk-slib ctxt/ctxt ctxt/ctxt_version.o ctxt/ctxt_group.o \
	ctxt/ctxt_bindir.o ctxt/ctxt_incdir.o ctxt/ctxt_slibdir.o \
	ctxt/ctxt_dlibdir.o ctxt/ctxt_owner.o ctxt/ctxt_repos.o 

phase_library: alloc.a array.a base_name.a bin.a buffer.a \
	closeonexec.a dir_array.a dir_hash.a dir_name.a dstring.a env.a \
	error.a fd.a float32.a float64.a fmt.a fmt_spec.a get_opt.a \
	hashtable.a int16.a int32.a int64.a nonblock.a open.a scan.a \
	scan_fspec.a scan_spec.a seek.a sgetline.a signal.a sstring.a \
	stalloc.a str.a syserr.a uint16.a uint32.a uint64.a ctxt/ctxt.a 
phase_library_clean:
	rm -f alloc.a array.a base_name.a bin.a \
	buffer.a closeonexec.a dir_array.a dir_hash.a dir_name.a dstring.a \
	env.a error.a fd.a float32.a float64.a fmt.a fmt_spec.a get_opt.a \
	hashtable.a int16.a int32.a int64.a nonblock.a open.a scan.a \
	scan_fspec.a scan_spec.a seek.a sgetline.a signal.a sstring.a \
	stalloc.a str.a syserr.a uint16.a uint32.a uint64.a ctxt/ctxt.a 

#--COMPILE--------------------------------------------------------------------

alloc.o:\
	cc alloc.c alloc.h 
	./cc alloc alloc.c 
array.o:\
	cc array.c alloc.h array.h bin.h uint32.h uint64.h 
	./cc array array.c 
array_bytes.o:\
	cc array_bytes.c alloc.h array.h bin.h uint32.h \
	uint64.h 
	./cc array_bytes array_bytes.c 
array_cat.o:\
	cc array_cat.c alloc.h array.h bin.h uint32.h \
	uint64.h 
	./cc array_cat array_cat.c 
array_chop.o:\
	cc array_chop.c alloc.h array.h bin.h uint32.h \
	uint64.h 
	./cc array_chop array_chop.c 
array_copy.o:\
	cc array_copy.c alloc.h array.h bin.h uint32.h \
	uint64.h 
	./cc array_copy array_copy.c 
array_data.o:\
	cc array_data.c array.h 
	./cc array_data array_data.c 
array_index.o:\
	cc array_index.c alloc.h array.h bin.h uint32.h \
	uint64.h 
	./cc array_index array_index.c 
array_size.o:\
	cc array_size.c alloc.h array.h bin.h uint32.h \
	uint64.h 
	./cc array_size array_size.c 
auto-text.o:\
	cc auto-text.c 
	./cc auto-text auto-text.c 
base_name.o:\
	cc base_name.c bin.h base_name.h str.h 
	./cc base_name base_name.c 
bin_char.o:\
	cc bin_char.c bin.h 
	./cc bin_char bin_char.c 
bin_chr.o:\
	cc bin_chr.c bin.h 
	./cc bin_chr bin_chr.c 
bin_copy.o:\
	cc bin_copy.c bin.h 
	./cc bin_copy bin_copy.c 
bin_copyr.o:\
	cc bin_copyr.c bin.h 
	./cc bin_copyr bin_copyr.c 
bin_count.o:\
	cc bin_count.c bin.h 
	./cc bin_count bin_count.c 
bin_diff.o:\
	cc bin_diff.c bin.h 
	./cc bin_diff bin_diff.c 
bin_rchar.o:\
	cc bin_rchar.c bin.h 
	./cc bin_rchar bin_rchar.c 
bin_rchr.o:\
	cc bin_rchr.c bin.h 
	./cc bin_rchr bin_rchr.c 
bin_set.o:\
	cc bin_set.c bin.h 
	./cc bin_set bin_set.c 
bin_tolower.o:\
	cc bin_tolower.c bin.h 
	./cc bin_tolower bin_tolower.c 
bin_toupper.o:\
	cc bin_toupper.c bin.h 
	./cc bin_toupper bin_toupper.c 
bin_zero.o:\
	cc bin_zero.c bin.h 
	./cc bin_zero bin_zero.c 
buffer0.o:\
	cc buffer0.c buffer.h read.h 
	./cc buffer0 buffer0.c 
buffer1.o:\
	cc buffer1.c buffer.h write.h 
	./cc buffer1 buffer1.c 
buffer2.o:\
	cc buffer2.c buffer.h write.h 
	./cc buffer2 buffer2.c 
buffer_copy.o:\
	cc buffer_copy.c buffer.h 
	./cc buffer_copy buffer_copy.c 
buffer_get.o:\
	cc buffer_get.c bin.h buffer.h error.h 
	./cc buffer_get buffer_get.c 
buffer_init.o:\
	cc buffer_init.c buffer.h 
	./cc buffer_init buffer_init.c 
buffer_put.o:\
	cc buffer_put.c bin.h buffer.h error.h str.h 
	./cc buffer_put buffer_put.c 
closeonexec.o:\
	cc closeonexec.c closeonexec.h 
	./cc closeonexec closeonexec.c 
corelib-conf.o:\
	cc corelib-conf.c buffer.h ctxt.h get_opt.h str.h \
	syserr.h 
	./cc corelib-conf corelib-conf.c 
deinstaller.o:\
	cc deinstaller.c install.h 
	./cc deinstaller deinstaller.c 
dir_array.o:\
	cc dir_array.c alloc.h bin.h dir_array.h direntry.h \
	str.h 
	./cc dir_array dir_array.c 
dir_hash.o:\
	cc dir_hash.c alloc.h bin.h dir_array.h dir_hash.h \
	str.h 
	./cc dir_hash dir_hash.c 
dir_name.o:\
	cc dir_name.c bin.h dir_name.h str.h 
	./cc dir_name dir_name.c 
dstring_0.o:\
	cc dstring_0.c dstring.h 
	./cc dstring_0 dstring_0.c 
dstring_cat.o:\
	cc dstring_cat.c dstring.h 
	./cc dstring_cat dstring_cat.c 
dstring_cat0.o:\
	cc dstring_cat0.c dstring.h 
	./cc dstring_cat0 dstring_cat0.c 
dstring_catb.o:\
	cc dstring_catb.c alloc.h bin.h dstring.h 
	./cc dstring_catb dstring_catb.c 
dstring_cats.o:\
	cc dstring_cats.c alloc.h bin.h dstring.h str.h 
	./cc dstring_cats dstring_cats.c 
dstring_chop.o:\
	cc dstring_chop.c dstring.h 
	./cc dstring_chop dstring_chop.c 
dstring_copy.o:\
	cc dstring_copy.c dstring.h 
	./cc dstring_copy dstring_copy.c 
dstring_cpyb.o:\
	cc dstring_cpyb.c alloc.h bin.h dstring.h 
	./cc dstring_cpyb dstring_cpyb.c 
dstring_cpys.o:\
	cc dstring_cpys.c dstring.h str.h 
	./cc dstring_cpys dstring_cpys.c 
dstring_init.o:\
	cc dstring_init.c alloc.h dstring.h 
	./cc dstring_init dstring_init.c 
dstring_trunc.o:\
	cc dstring_trunc.c dstring.h 
	./cc dstring_trunc dstring_trunc.c 
env.o:\
	cc env.c alloc.h bin.h env.h str.h 
	./cc env env.c 
env_get.o:\
	cc env_get.c env.h str.h 
	./cc env_get env_get.c 
error.o:\
	cc error.c error.h 
	./cc error error.c 
error_str.o:\
	cc error_str.c error.h 
	./cc error_str error_str.c 
fd_dup.o:\
	cc fd_dup.c close.h fd.h 
	./cc fd_dup fd_dup.c 
fd_move.o:\
	cc fd_move.c close.h fd.h 
	./cc fd_move fd_move.c 
fd_reset.o:\
	cc fd_reset.c fd.h 
	./cc fd_reset fd_reset.c 
float32_pack.o:\
	cc float32_pack.c endian.h float32.h 
	./cc float32_pack float32_pack.c 
float32_upack.o:\
	cc float32_upack.c endian.h float32.h 
	./cc float32_upack float32_upack.c 
float64_pack.o:\
	cc float64_pack.c endian.h float64.h 
	./cc float64_pack float64_pack.c 
float64_upack.o:\
	cc float64_upack.c endian.h float64.h 
	./cc float64_upack float64_upack.c 
fmt_nstr.o:\
	cc fmt_nstr.c fmt.h 
	./cc fmt_nstr fmt_nstr.c 
fmt_str.o:\
	cc fmt_str.c fmt.h 
	./cc fmt_str fmt_str.c 
fmt_u32.o:\
	cc fmt_u32.c fmt_spec.h uint32.h uint64.h 
	./cc fmt_u32 fmt_u32.c 
fmt_u32o.o:\
	cc fmt_u32o.c fmt_spec.h uint32.h uint64.h 
	./cc fmt_u32o fmt_u32o.c 
fmt_u32x.o:\
	cc fmt_u32x.c fmt_spec.h uint32.h uint64.h 
	./cc fmt_u32x fmt_u32x.c 
fmt_u64.o:\
	cc fmt_u64.c fmt_spec.h uint64.h 
	./cc fmt_u64 fmt_u64.c 
fmt_u64o.o:\
	cc fmt_u64o.c fmt_spec.h uint64.h 
	./cc fmt_u64o fmt_u64o.c 
fmt_u64x.o:\
	cc fmt_u64x.c fmt_spec.h uint64.h 
	./cc fmt_u64x fmt_u64x.c 
fmt_uchar.o:\
	cc fmt_uchar.c fmt.h 
	./cc fmt_uchar fmt_uchar.c 
fmt_ucharo.o:\
	cc fmt_ucharo.c fmt.h 
	./cc fmt_ucharo fmt_ucharo.c 
fmt_ucharx.o:\
	cc fmt_ucharx.c fmt.h 
	./cc fmt_ucharx fmt_ucharx.c 
fmt_uint.o:\
	cc fmt_uint.c fmt.h 
	./cc fmt_uint fmt_uint.c 
fmt_uinto.o:\
	cc fmt_uinto.c fmt.h 
	./cc fmt_uinto fmt_uinto.c 
fmt_uintx.o:\
	cc fmt_uintx.c fmt.h 
	./cc fmt_uintx fmt_uintx.c 
fmt_ullong.o:\
	cc fmt_ullong.c fmt.h 
	./cc fmt_ullong fmt_ullong.c 
fmt_ullongo.o:\
	cc fmt_ullongo.c fmt.h 
	./cc fmt_ullongo fmt_ullongo.c 
fmt_ullongx.o:\
	cc fmt_ullongx.c fmt.h 
	./cc fmt_ullongx fmt_ullongx.c 
fmt_ulong.o:\
	cc fmt_ulong.c fmt.h 
	./cc fmt_ulong fmt_ulong.c 
fmt_ulongo.o:\
	cc fmt_ulongo.c fmt.h 
	./cc fmt_ulongo fmt_ulongo.c 
fmt_ulongx.o:\
	cc fmt_ulongx.c fmt.h 
	./cc fmt_ulongx fmt_ulongx.c 
fmt_ushort.o:\
	cc fmt_ushort.c fmt.h 
	./cc fmt_ushort fmt_ushort.c 
fmt_ushorto.o:\
	cc fmt_ushorto.c fmt.h 
	./cc fmt_ushorto fmt_ushorto.c 
fmt_ushortx.o:\
	cc fmt_ushortx.c fmt.h 
	./cc fmt_ushortx fmt_ushortx.c 
get_opt.o:\
	cc get_opt.c buffer.h get_opt.h 
	./cc get_opt get_opt.c 
ht_addb.o:\
	cc ht_addb.c alloc.h bin.h error.h hashtable.h 
	./cc ht_addb ht_addb.c 
ht_adds.o:\
	cc ht_adds.c hashtable.h str.h 
	./cc ht_adds ht_adds.c 
ht_bytes.o:\
	cc ht_bytes.c hashtable.h 
	./cc ht_bytes ht_bytes.c 
ht_deleteb.o:\
	cc ht_deleteb.c alloc.h bin.h hashtable.h 
	./cc ht_deleteb ht_deleteb.c 
ht_deletes.o:\
	cc ht_deletes.c hashtable.h str.h 
	./cc ht_deletes ht_deletes.c 
ht_free.o:\
	cc ht_free.c alloc.h hashtable.h 
	./cc ht_free ht_free.c 
ht_getb.o:\
	cc ht_getb.c bin.h hashtable.h 
	./cc ht_getb ht_getb.c 
ht_gets.o:\
	cc ht_gets.c hashtable.h str.h 
	./cc ht_gets ht_gets.c 
ht_hash.o:\
	cc ht_hash.c hashtable.h 
	./cc ht_hash ht_hash.c 
ht_init.o:\
	cc ht_init.c bin.h hashtable.h 
	./cc ht_init ht_init.c 
ht_replaceb.o:\
	cc ht_replaceb.c alloc.h bin.h hashtable.h 
	./cc ht_replaceb ht_replaceb.c 
ht_replaces.o:\
	cc ht_replaces.c hashtable.h str.h 
	./cc ht_replaces ht_replaces.c 
inst-check.o:\
	cc inst-check.c install.h 
	./cc inst-check inst-check.c 
inst-copy.o:\
	cc inst-copy.c install.h 
	./cc inst-copy inst-copy.c 
inst-dir.o:\
	cc inst-dir.c install.h 
	./cc inst-dir inst-dir.c 
inst-link.o:\
	cc inst-link.c install.h 
	./cc inst-link inst-link.c 
install_core.o:\
	cc install_core.c install.h 
	./cc install_core install_core.c 
install_error.o:\
	cc install_error.c install.h 
	./cc install_error install_error.c 
installer.o:\
	cc installer.c install.h 
	./cc installer installer.c 
instchk.o:\
	cc instchk.c install.h 
	./cc instchk instchk.c 
insthier.o:\
	cc insthier.c install.h ctxt.h 
	./cc insthier insthier.c 
int16_pack.o:\
	cc int16_pack.c int16.h 
	./cc int16_pack int16_pack.c 
int16_unpack.o:\
	cc int16_unpack.c int16.h 
	./cc int16_unpack int16_unpack.c 
int32_pack.o:\
	cc int32_pack.c int32.h 
	./cc int32_pack int32_pack.c 
int32_unpack.o:\
	cc int32_unpack.c int32.h 
	./cc int32_unpack int32_unpack.c 
int64_pack.o:\
	cc int64_pack.c int64.h 
	./cc int64_pack int64_pack.c 
int64_unpack.o:\
	cc int64_unpack.c int64.h 
	./cc int64_unpack int64_unpack.c 
mk-ctxt.o:\
	cc mk-ctxt.c 
	./cc mk-ctxt mk-ctxt.c 
nonblock.o:\
	cc nonblock.c nonblock.h 
	./cc nonblock nonblock.c 
open_append.o:\
	cc open_append.c open.h 
	./cc open_append open_append.c 
open_creat.o:\
	cc open_creat.c open.h 
	./cc open_creat open_creat.c 
open_excl.o:\
	cc open_excl.c open.h 
	./cc open_excl open_excl.c 
open_ro.o:\
	cc open_ro.c open.h 
	./cc open_ro open_ro.c 
open_rw.o:\
	cc open_rw.c open.h 
	./cc open_rw open_rw.c 
open_trunc.o:\
	cc open_trunc.c open.h 
	./cc open_trunc open_trunc.c 
open_wo.o:\
	cc open_wo.c open.h 
	./cc open_wo open_wo.c 
scan_charset.o:\
	cc scan_charset.c scan.h 
	./cc scan_charset scan_charset.c 
scan_double.o:\
	cc scan_double.c scan.h 
	./cc scan_double scan_double.c 
scan_f32.o:\
	cc scan_f32.c scan_fspec.h 
	./cc scan_f32 scan_f32.c 
scan_f64.o:\
	cc scan_f64.c scan_fspec.h 
	./cc scan_f64 scan_f64.c 
scan_float.o:\
	cc scan_float.c scan.h 
	./cc scan_float scan_float.c 
scan_ncharset.o:\
	cc scan_ncharset.c scan.h 
	./cc scan_ncharset scan_ncharset.c 
scan_newline.o:\
	cc scan_newline.c scan.h 
	./cc scan_newline scan_newline.c 
scan_space.o:\
	cc scan_space.c scan.h 
	./cc scan_space scan_space.c 
scan_u32.o:\
	cc scan_u32.c scan_spec.h uint32.h uint64.h 
	./cc scan_u32 scan_u32.c 
scan_u32o.o:\
	cc scan_u32o.c scan_spec.h uint32.h uint64.h 
	./cc scan_u32o scan_u32o.c 
scan_u32x.o:\
	cc scan_u32x.c scan_spec.h uint32.h uint64.h 
	./cc scan_u32x scan_u32x.c 
scan_u64.o:\
	cc scan_u64.c scan_spec.h uint64.h 
	./cc scan_u64 scan_u64.c 
scan_u64o.o:\
	cc scan_u64o.c scan_spec.h uint64.h 
	./cc scan_u64o scan_u64o.c 
scan_u64x.o:\
	cc scan_u64x.c scan_spec.h uint64.h 
	./cc scan_u64x scan_u64x.c 
scan_uchar.o:\
	cc scan_uchar.c scan.h 
	./cc scan_uchar scan_uchar.c 
scan_ucharo.o:\
	cc scan_ucharo.c scan.h 
	./cc scan_ucharo scan_ucharo.c 
scan_ucharx.o:\
	cc scan_ucharx.c scan.h 
	./cc scan_ucharx scan_ucharx.c 
scan_uint.o:\
	cc scan_uint.c scan.h 
	./cc scan_uint scan_uint.c 
scan_uinto.o:\
	cc scan_uinto.c scan.h 
	./cc scan_uinto scan_uinto.c 
scan_uintx.o:\
	cc scan_uintx.c scan.h 
	./cc scan_uintx scan_uintx.c 
scan_ullong.o:\
	cc scan_ullong.c scan.h 
	./cc scan_ullong scan_ullong.c 
scan_ullongo.o:\
	cc scan_ullongo.c scan.h 
	./cc scan_ullongo scan_ullongo.c 
scan_ullongx.o:\
	cc scan_ullongx.c scan.h 
	./cc scan_ullongx scan_ullongx.c 
scan_ulong.o:\
	cc scan_ulong.c scan.h 
	./cc scan_ulong scan_ulong.c 
scan_ulongo.o:\
	cc scan_ulongo.c scan.h 
	./cc scan_ulongo scan_ulongo.c 
scan_ulongx.o:\
	cc scan_ulongx.c scan.h 
	./cc scan_ulongx scan_ulongx.c 
scan_ushort.o:\
	cc scan_ushort.c scan.h 
	./cc scan_ushort scan_ushort.c 
scan_ushorto.o:\
	cc scan_ushorto.c scan.h 
	./cc scan_ushorto scan_ushorto.c 
scan_ushortx.o:\
	cc scan_ushortx.c scan.h 
	./cc scan_ushortx scan_ushortx.c 
seek_cur.o:\
	cc seek_cur.c int64.h seek.h 
	./cc seek_cur seek_cur.c 
seek_end.o:\
	cc seek_end.c int64.h seek.h 
	./cc seek_end seek_end.c 
seek_pos.o:\
	cc seek_pos.c int64.h seek.h 
	./cc seek_pos seek_pos.c 
seek_start.o:\
	cc seek_start.c int64.h seek.h 
	./cc seek_start seek_start.c 
sgetline.o:\
	cc sgetline.c sgetline.h 
	./cc sgetline sgetline.c 
sgetline_chop.o:\
	cc sgetline_chop.c sgetline.h 
	./cc sgetline_chop sgetline_chop.c 
sgetline_get.o:\
	cc sgetline_get.c bin.h buffer.h sgetline.h \
	sstring.h 
	./cc sgetline_get sgetline_get.c 
sig_block.o:\
	cc sig_block.c signal.h sig_pmask.h 
	./cc sig_block sig_block.c 
sig_catch.o:\
	cc sig_catch.c signal.h sig_action.h 
	./cc sig_catch sig_catch.c 
sig_pause.o:\
	cc sig_pause.c signal.h sig_pmask.h 
	./cc sig_pause sig_pause.c 
signal.o:\
	cc signal.c signal.h 
	./cc signal signal.c 
sstring_0.o:\
	cc sstring_0.c sstring.h 
	./cc sstring_0 sstring_0.c 
sstring_cat.o:\
	cc sstring_cat.c sstring.h 
	./cc sstring_cat sstring_cat.c 
sstring_catb.o:\
	cc sstring_catb.c sstring.h 
	./cc sstring_catb sstring_catb.c 
sstring_cats.o:\
	cc sstring_cats.c sstring.h 
	./cc sstring_cats sstring_cats.c 
sstring_chop.o:\
	cc sstring_chop.c sstring.h 
	./cc sstring_chop sstring_chop.c 
sstring_copy.o:\
	cc sstring_copy.c sstring.h 
	./cc sstring_copy sstring_copy.c 
sstring_cpyb.o:\
	cc sstring_cpyb.c sstring.h 
	./cc sstring_cpyb sstring_cpyb.c 
sstring_cpys.o:\
	cc sstring_cpys.c sstring.h 
	./cc sstring_cpys sstring_cpys.c 
sstring_init.o:\
	cc sstring_init.c sstring.h 
	./cc sstring_init sstring_init.c 
sstring_trunc.o:\
	cc sstring_trunc.c sstring.h 
	./cc sstring_trunc sstring_trunc.c 
stalloc.o:\
	cc stalloc.c error.h stalloc.h 
	./cc stalloc stalloc.c 
str_char.o:\
	cc str_char.c str.h 
	./cc str_char str_char.c 
str_chr.o:\
	cc str_chr.c str.h 
	./cc str_chr str_chr.c 
str_diff.o:\
	cc str_diff.c str.h 
	./cc str_diff str_diff.c 
str_dup.o:\
	cc str_dup.c alloc.h bin.h str.h 
	./cc str_dup str_dup.c 
str_ends.o:\
	cc str_ends.c str.h 
	./cc str_ends str_ends.c 
str_len.o:\
	cc str_len.c str.h 
	./cc str_len str_len.c 
str_ndiff.o:\
	cc str_ndiff.c str.h 
	./cc str_ndiff str_ndiff.c 
str_rchar.o:\
	cc str_rchar.c str.h 
	./cc str_rchar str_rchar.c 
str_rchr.o:\
	cc str_rchr.c str.h 
	./cc str_rchr str_rchr.c 
str_starts.o:\
	cc str_starts.c str.h 
	./cc str_starts str_starts.c 
str_tolower.o:\
	cc str_tolower.c str.h 
	./cc str_tolower str_tolower.c 
str_toupper.o:\
	cc str_toupper.c str.h 
	./cc str_toupper str_toupper.c 
syserr_die.o:\
	cc syserr_die.c buffer.h exit.h syserr.h 
	./cc syserr_die syserr_die.c 
syserr_init.o:\
	cc syserr_init.c error.h syserr.h 
	./cc syserr_init syserr_init.c 
uint16_pack.o:\
	cc uint16_pack.c uint16.h 
	./cc uint16_pack uint16_pack.c 
uint16_unpack.o:\
	cc uint16_unpack.c uint16.h 
	./cc uint16_unpack uint16_unpack.c 
uint32_pack.o:\
	cc uint32_pack.c uint32.h 
	./cc uint32_pack uint32_pack.c 
uint32_unpack.o:\
	cc uint32_unpack.c uint32.h 
	./cc uint32_unpack uint32_unpack.c 
uint64_pack.o:\
	cc uint64_pack.c uint64.h 
	./cc uint64_pack uint64_pack.c 
uint64_unpack.o:\
	cc uint64_unpack.c uint64.h 
	./cc uint64_unpack uint64_unpack.c 
ctxt/ctxt_bindir.o:\
	cc ctxt/ctxt_bindir.c 
	./cc ctxt/ctxt_bindir ctxt/ctxt_bindir.c 
ctxt/ctxt_dlibdir.o:\
	cc ctxt/ctxt_dlibdir.c 
	./cc ctxt/ctxt_dlibdir ctxt/ctxt_dlibdir.c 
ctxt/ctxt_group.o:\
	cc ctxt/ctxt_group.c 
	./cc ctxt/ctxt_group ctxt/ctxt_group.c 
ctxt/ctxt_incdir.o:\
	cc ctxt/ctxt_incdir.c 
	./cc ctxt/ctxt_incdir ctxt/ctxt_incdir.c 
ctxt/ctxt_owner.o:\
	cc ctxt/ctxt_owner.c 
	./cc ctxt/ctxt_owner ctxt/ctxt_owner.c 
ctxt/ctxt_repos.o:\
	cc ctxt/ctxt_repos.c 
	./cc ctxt/ctxt_repos ctxt/ctxt_repos.c 
ctxt/ctxt_slibdir.o:\
	cc ctxt/ctxt_slibdir.c 
	./cc ctxt/ctxt_slibdir ctxt/ctxt_slibdir.c 
ctxt/ctxt_version.o:\
	cc ctxt/ctxt_version.c 
	./cc ctxt/ctxt_version ctxt/ctxt_version.c 

phase_compile: alloc.o array.o array_bytes.o array_cat.o \
	array_chop.o array_copy.o array_data.o array_index.o array_size.o \
	auto-text.o base_name.o bin_char.o bin_chr.o bin_copy.o bin_copyr.o \
	bin_count.o bin_diff.o bin_rchar.o bin_rchr.o bin_set.o \
	bin_tolower.o bin_toupper.o bin_zero.o buffer0.o buffer1.o buffer2.o \
	buffer_copy.o buffer_get.o buffer_init.o buffer_put.o closeonexec.o \
	corelib-conf.o deinstaller.o dir_array.o dir_hash.o dir_name.o \
	dstring_0.o dstring_cat.o dstring_cat0.o dstring_catb.o \
	dstring_cats.o dstring_chop.o dstring_copy.o dstring_cpyb.o \
	dstring_cpys.o dstring_init.o dstring_trunc.o env.o env_get.o \
	error.o error_str.o fd_dup.o fd_move.o fd_reset.o float32_pack.o \
	float32_upack.o float64_pack.o float64_upack.o fmt_nstr.o fmt_str.o \
	fmt_u32.o fmt_u32o.o fmt_u32x.o fmt_u64.o fmt_u64o.o fmt_u64x.o \
	fmt_uchar.o fmt_ucharo.o fmt_ucharx.o fmt_uint.o fmt_uinto.o \
	fmt_uintx.o fmt_ullong.o fmt_ullongo.o fmt_ullongx.o fmt_ulong.o \
	fmt_ulongo.o fmt_ulongx.o fmt_ushort.o fmt_ushorto.o fmt_ushortx.o \
	get_opt.o ht_addb.o ht_adds.o ht_bytes.o ht_deleteb.o ht_deletes.o \
	ht_free.o ht_getb.o ht_gets.o ht_hash.o ht_init.o ht_replaceb.o \
	ht_replaces.o inst-check.o inst-copy.o inst-dir.o inst-link.o \
	install_core.o install_error.o installer.o instchk.o insthier.o \
	int16_pack.o int16_unpack.o int32_pack.o int32_unpack.o int64_pack.o \
	int64_unpack.o mk-ctxt.o nonblock.o open_append.o open_creat.o \
	open_excl.o open_ro.o open_rw.o open_trunc.o open_wo.o \
	scan_charset.o scan_double.o scan_f32.o scan_f64.o scan_float.o \
	scan_ncharset.o scan_newline.o scan_space.o scan_u32.o scan_u32o.o \
	scan_u32x.o scan_u64.o scan_u64o.o scan_u64x.o scan_uchar.o \
	scan_ucharo.o scan_ucharx.o scan_uint.o scan_uinto.o scan_uintx.o \
	scan_ullong.o scan_ullongo.o scan_ullongx.o scan_ulong.o \
	scan_ulongo.o scan_ulongx.o scan_ushort.o scan_ushorto.o \
	scan_ushortx.o seek_cur.o seek_end.o seek_pos.o seek_start.o \
	sgetline.o sgetline_chop.o sgetline_get.o sig_block.o sig_catch.o \
	sig_pause.o signal.o sstring_0.o sstring_cat.o sstring_catb.o \
	sstring_cats.o sstring_chop.o sstring_copy.o sstring_cpyb.o \
	sstring_cpys.o sstring_init.o sstring_trunc.o stalloc.o str_char.o \
	str_chr.o str_diff.o str_dup.o str_ends.o str_len.o str_ndiff.o \
	str_rchar.o str_rchr.o str_starts.o str_tolower.o str_toupper.o \
	syserr_die.o syserr_init.o uint16_pack.o uint16_unpack.o \
	uint32_pack.o uint32_unpack.o uint64_pack.o uint64_unpack.o \
	ctxt/ctxt_bindir.o ctxt/ctxt_dlibdir.o ctxt/ctxt_group.o \
	ctxt/ctxt_incdir.o ctxt/ctxt_owner.o ctxt/ctxt_repos.o \
	ctxt/ctxt_slibdir.o ctxt/ctxt_version.o 
phase_compile_clean:
	rm -f alloc.o array.o array_bytes.o \
	array_cat.o array_chop.o array_copy.o array_data.o array_index.o \
	array_size.o auto-text.o base_name.o bin_char.o bin_chr.o bin_copy.o \
	bin_copyr.o bin_count.o bin_diff.o bin_rchar.o bin_rchr.o bin_set.o \
	bin_tolower.o bin_toupper.o bin_zero.o buffer0.o buffer1.o buffer2.o \
	buffer_copy.o buffer_get.o buffer_init.o buffer_put.o closeonexec.o \
	corelib-conf.o deinstaller.o dir_array.o dir_hash.o dir_name.o \
	dstring_0.o dstring_cat.o dstring_cat0.o dstring_catb.o \
	dstring_cats.o dstring_chop.o dstring_copy.o dstring_cpyb.o \
	dstring_cpys.o dstring_init.o dstring_trunc.o env.o env_get.o \
	error.o error_str.o fd_dup.o fd_move.o fd_reset.o float32_pack.o \
	float32_upack.o float64_pack.o float64_upack.o fmt_nstr.o fmt_str.o \
	fmt_u32.o fmt_u32o.o fmt_u32x.o fmt_u64.o fmt_u64o.o fmt_u64x.o \
	fmt_uchar.o fmt_ucharo.o fmt_ucharx.o fmt_uint.o fmt_uinto.o \
	fmt_uintx.o fmt_ullong.o fmt_ullongo.o fmt_ullongx.o fmt_ulong.o \
	fmt_ulongo.o fmt_ulongx.o fmt_ushort.o fmt_ushorto.o fmt_ushortx.o \
	get_opt.o ht_addb.o ht_adds.o ht_bytes.o ht_deleteb.o ht_deletes.o \
	ht_free.o ht_getb.o ht_gets.o ht_hash.o ht_init.o ht_replaceb.o \
	ht_replaces.o inst-check.o inst-copy.o inst-dir.o inst-link.o \
	install_core.o install_error.o installer.o instchk.o insthier.o \
	int16_pack.o int16_unpack.o int32_pack.o int32_unpack.o int64_pack.o \
	int64_unpack.o mk-ctxt.o nonblock.o open_append.o open_creat.o \
	open_excl.o open_ro.o open_rw.o open_trunc.o open_wo.o \
	scan_charset.o scan_double.o scan_f32.o scan_f64.o scan_float.o \
	scan_ncharset.o scan_newline.o scan_space.o scan_u32.o scan_u32o.o \
	scan_u32x.o scan_u64.o scan_u64o.o scan_u64x.o scan_uchar.o \
	scan_ucharo.o scan_ucharx.o scan_uint.o scan_uinto.o scan_uintx.o \
	scan_ullong.o scan_ullongo.o scan_ullongx.o scan_ulong.o \
	scan_ulongo.o scan_ulongx.o scan_ushort.o scan_ushorto.o \
	scan_ushortx.o seek_cur.o seek_end.o seek_pos.o seek_start.o \
	sgetline.o sgetline_chop.o sgetline_get.o sig_block.o sig_catch.o \
	sig_pause.o signal.o sstring_0.o sstring_cat.o sstring_catb.o \
	sstring_cats.o sstring_chop.o sstring_copy.o sstring_cpyb.o \
	sstring_cpys.o sstring_init.o sstring_trunc.o stalloc.o str_char.o \
	str_chr.o str_diff.o str_dup.o str_ends.o str_len.o str_ndiff.o \
	str_rchar.o str_rchr.o str_starts.o str_tolower.o str_toupper.o \
	syserr_die.o syserr_init.o uint16_pack.o uint16_unpack.o \
	uint32_pack.o uint32_unpack.o uint64_pack.o uint64_unpack.o \
	ctxt/ctxt_bindir.o ctxt/ctxt_dlibdir.o ctxt/ctxt_group.o \
	ctxt/ctxt_incdir.o ctxt/ctxt_owner.o ctxt/ctxt_repos.o \
	ctxt/ctxt_slibdir.o ctxt/ctxt_version.o 

#--PREGEN---------------------------------------------------------------------


phase_pregen: 
phase_pregen_clean:


#--LOCAL----------------------------------------------------------------------

phase_sysdeps_local:
phase_tools_local:
phase_pregen_local:
phase_compile_local:
phase_library_local:
phase_link_local:
phase_local_clean: ctxt_clean

ctxt_clean:
	rm -f ctxt/ctxt_slibdir.c ctxt/ctxt_repos.c ctxt/ctxt_group.c \
	ctxt/ctxt_owner.c ctxt/ctxt_bindir.c ctxt/ctxt_version.c \
	ctxt/ctxt_dlibdir.c ctxt/ctxt_incdir.c
	touch ctxt/ctxt_slibdir.c ctxt/ctxt_repos.c ctxt/ctxt_group.c \
	ctxt/ctxt_owner.c ctxt/ctxt_bindir.c ctxt/ctxt_version.c \
	ctxt/ctxt_dlibdir.c ctxt/ctxt_incdir.c

ctxt/ctxt_version.c: auto-text VERSION
	rm -f ctxt/ctxt_version.c
	./auto-text ctxt_version ../ctxt < VERSION > ctxt/ctxt_version.c

ctxt/ctxt_slibdir.c: auto-text conf-slibdir
	rm -f ctxt/ctxt_slibdir.c
	./auto-text ctxt_slibdir ../ctxt < conf-slibdir > ctxt/ctxt_slibdir.c

ctxt/ctxt_dlibdir.c: auto-text conf-dlibdir
	rm -f ctxt/ctxt_dlibdir.c
	./auto-text ctxt_dlibdir ../ctxt < conf-dlibdir > ctxt/ctxt_dlibdir.c

ctxt/ctxt_bindir.c: auto-text conf-bindir
	rm -f ctxt/ctxt_bindir.c
	./auto-text ctxt_bindir ../ctxt < conf-bindir > ctxt/ctxt_bindir.c

ctxt/ctxt_incdir.c: auto-text conf-incdir
	rm -f ctxt/ctxt_incdir.c
	./auto-text ctxt_incdir ../ctxt < conf-incdir > ctxt/ctxt_incdir.c

ctxt/ctxt_repos.c: auto-text conf-repos
	rm -f ctxt/ctxt_repos.c
	./auto-text ctxt_repos ../ctxt < conf-repos > ctxt/ctxt_repos.c

ctxt/ctxt_group.c: auto-text conf-group
	rm -f ctxt/ctxt_group.c
	./auto-text ctxt_group ../ctxt < conf-group > ctxt/ctxt_group.c

ctxt/ctxt_owner.c: auto-text conf-owner
	rm -f ctxt/ctxt_owner.c
	./auto-text ctxt_owner ../ctxt < conf-owner > ctxt/ctxt_owner.c

#--INSTALL--------------------------------------------------------------------

phase_install: installer
	./installer

install-dryrun: installer
	./installer dryrun

#--INSTALL-CHECK--------------------------------------------------------------

phase_install_check: instchk
	./instchk

#--TEST-----------------------------------------------------------------------

phase_test_clean:
	(cd UNIT_TESTS; make clean)

phase_test:
	(cd UNIT_TESTS; make && make tests)

#--SYSDEPS--------------------------------------------------------------------

phase_sysdeps: sysdeps.out
sysdeps.out:
	SYSDEPS/sysdep-header sysdeps.out
	(cd SYSDEPS && make )
phase_sysdeps_clean:
	(cd SYSDEPS && make clean)
	rm -f sysdeps.out

#--TOOLS----------------------------------------------------------------------

phase_tools: cc conf-cc conf-cctype conf-ld conf-systype ld \
	mk-cctype mk-slib mk-systype 
cc: conf-cctype conf-cc 

conf-cctype: conf-systype conf-cc 
	./mk-cctype > conf-cctype
conf-systype: 
	./mk-systype > conf-systype
ld: conf-ld libs-sysmath 

mk-cctype: conf-cc conf-systype 

mk-slib: conf-systype 


phase_tools_clean:
	rm -f conf-cctype conf-systype 
regen:
	cpj-genmk > Makefile.tmp
	mv Makefile.tmp Makefile
