# auto generated - do not edit

default: all

all: sysdeps.out \
	alloc.a array.a base_name.a bin.a buffer.a closeonexec.a \
	corelib-conf ctxt/ctxt.a deinstaller dir_array.a dir_hash.a \
	dir_name.a dstring.a env.a error.a fd.a float32.a float64.a fmt.a \
	fmt_spec.a get_opt.a hashtable.a iarray.a inst-check inst-copy \
	inst-dir inst-link installer instchk int16.a int32.a int64.a \
	nonblock.a open.a scan.a scan_fspec.a scan_spec.a seek.a sgetline.a \
	sig.a sstring.a stalloc.a str.a syserr.a uint16.a uint32.a uint64.a \
	

sysdeps: sysdeps.out
sysdeps.out:
	SYSDEPS/sysdep-header sysdeps.out
	(cd SYSDEPS && make)
sysdeps_clean:
	(cd SYSDEPS && make clean)
	rm -f sysdeps.out

alloc.a:\
	mk-slib alloc.sld alloc.o 
	./mk-slib alloc alloc.o 
alloc.o:\
	cc alloc.c alloc.h 
	./cc alloc.c
array.a:\
	mk-slib array.sld array.o array_bytes.o array_cat.o array_copy.o \
	array_index.o array_size.o array_chop.o 
	./mk-slib array array.o array_bytes.o array_cat.o array_copy.o \
	array_index.o array_size.o array_chop.o 
array.o:\
	cc array.c alloc.h array.h 
	./cc array.c
array_bytes.o:\
	cc array_bytes.c array.h 
	./cc array_bytes.c
array_cat.o:\
	cc array_cat.c alloc.h array.h 
	./cc array_cat.c
array_chop.o:\
	cc array_chop.c array.h 
	./cc array_chop.c
array_copy.o:\
	cc array_copy.c array.h 
	./cc array_copy.c
array_data.o:\
	cc array_data.c array.h 
	./cc array_data.c
array_index.o:\
	cc array_index.c array.h 
	./cc array_index.c
array_size.o:\
	cc array_size.c array.h 
	./cc array_size.c
base_name.a:\
	mk-slib base_name.sld base_name.o 
	./mk-slib base_name base_name.o 
base_name.o:\
	cc base_name.c bin.h base_name.h str.h 
	./cc base_name.c
bin.a:\
	mk-slib bin.sld bin_char.o bin_rchar.o bin_chr.o bin_copy.o \
	bin_copyr.o bin_count.o bin_diff.o bin_rchr.o bin_set.o \
	bin_tolower.o bin_toupper.o bin_zero.o 
	./mk-slib bin bin_char.o bin_rchar.o bin_chr.o bin_copy.o \
	bin_copyr.o bin_count.o bin_diff.o bin_rchr.o bin_set.o \
	bin_tolower.o bin_toupper.o bin_zero.o 
bin_char.o:\
	cc bin_char.c bin.h 
	./cc bin_char.c
bin_chr.o:\
	cc bin_chr.c bin.h 
	./cc bin_chr.c
bin_copy.o:\
	cc bin_copy.c bin.h 
	./cc bin_copy.c
bin_copyr.o:\
	cc bin_copyr.c bin.h 
	./cc bin_copyr.c
bin_count.o:\
	cc bin_count.c bin.h 
	./cc bin_count.c
bin_diff.o:\
	cc bin_diff.c bin.h 
	./cc bin_diff.c
bin_rchar.o:\
	cc bin_rchar.c bin.h 
	./cc bin_rchar.c
bin_rchr.o:\
	cc bin_rchr.c bin.h 
	./cc bin_rchr.c
bin_set.o:\
	cc bin_set.c bin.h 
	./cc bin_set.c
bin_tolower.o:\
	cc bin_tolower.c bin.h 
	./cc bin_tolower.c
bin_toupper.o:\
	cc bin_toupper.c bin.h 
	./cc bin_toupper.c
bin_zero.o:\
	cc bin_zero.c bin.h 
	./cc bin_zero.c
buffer.a:\
	mk-slib buffer.sld buffer0.o buffer1.o buffer2.o buffer_get.o \
	buffer_init.o buffer_put.o buffer_copy.o 
	./mk-slib buffer buffer0.o buffer1.o buffer2.o buffer_get.o \
	buffer_init.o buffer_put.o buffer_copy.o 
buffer0.o:\
	cc buffer0.c buffer.h read.h 
	./cc buffer0.c
buffer1.o:\
	cc buffer1.c buffer.h write.h 
	./cc buffer1.c
buffer2.o:\
	cc buffer2.c buffer.h write.h 
	./cc buffer2.c
buffer_copy.o:\
	cc buffer_copy.c buffer.h 
	./cc buffer_copy.c
buffer_get.o:\
	cc buffer_get.c bin.h buffer.h error.h 
	./cc buffer_get.c
buffer_init.o:\
	cc buffer_init.c buffer.h 
	./cc buffer_init.c
buffer_put.o:\
	cc buffer_put.c bin.h buffer.h error.h str.h 
	./cc buffer_put.c
cc: conf-cc conf-cctype conf-cflags sysdeps.out 
closeonexec.a:\
	mk-slib closeonexec.sld closeonexec.o 
	./mk-slib closeonexec closeonexec.o 
closeonexec.o:\
	cc closeonexec.c closeonexec.h 
	./cc closeonexec.c
conf-cctype:\
	conf-systype conf-cc mk-cctype 
	./mk-cctype > conf-cctype
conf-sosuffix:\
	mk-sosuffix 
	./mk-sosuffix > conf-sosuffix
conf-systype:\
	mk-systype 
	./mk-systype > conf-systype
corelib-conf:\
	ld corelib-conf.ld corelib-conf.o ctxt/ctxt.a get_opt.a syserr.a \
	buffer.a error.a bin.a str.a 
	./ld corelib-conf corelib-conf.o ctxt/ctxt.a get_opt.a syserr.a \
	buffer.a error.a bin.a str.a 
corelib-conf.o:\
	cc corelib-conf.c buffer.h ctxt.h get_opt.h str.h syserr.h 
	./cc corelib-conf.c
ctxt/bindir.c: mk-ctxt conf-bindir
	rm -f ctxt/bindir.c
	./mk-ctxt ctxt_bindir < conf-bindir > ctxt/bindir.c

ctxt/bindir.o:\
	cc ctxt/bindir.c 
	./cc ctxt/bindir.c
ctxt/ctxt.a:\
	mk-slib ctxt/ctxt.sld ctxt/bindir.o ctxt/dlibdir.o ctxt/incdir.o \
	ctxt/repos.o ctxt/slibdir.o ctxt/version.o 
	./mk-slib ctxt/ctxt ctxt/bindir.o ctxt/dlibdir.o ctxt/incdir.o \
	ctxt/repos.o ctxt/slibdir.o ctxt/version.o 
ctxt/dlibdir.c: mk-ctxt conf-dlibdir
	rm -f ctxt/dlibdir.c
	./mk-ctxt ctxt_dlibdir < conf-dlibdir > ctxt/dlibdir.c

ctxt/dlibdir.o:\
	cc ctxt/dlibdir.c 
	./cc ctxt/dlibdir.c
ctxt/incdir.c: mk-ctxt conf-incdir
	rm -f ctxt/incdir.c
	./mk-ctxt ctxt_incdir < conf-incdir > ctxt/incdir.c

ctxt/incdir.o:\
	cc ctxt/incdir.c 
	./cc ctxt/incdir.c
ctxt/repos.c: mk-ctxt conf-repos
	rm -f ctxt/repos.c
	./mk-ctxt ctxt_repos < conf-repos > ctxt/repos.c

ctxt/repos.o:\
	cc ctxt/repos.c 
	./cc ctxt/repos.c
ctxt/slibdir.c: mk-ctxt conf-slibdir
	rm -f ctxt/slibdir.c
	./mk-ctxt ctxt_slibdir < conf-slibdir > ctxt/slibdir.c

ctxt/slibdir.o:\
	cc ctxt/slibdir.c 
	./cc ctxt/slibdir.c
ctxt/version.c: mk-ctxt VERSION
	rm -f ctxt/version.c
	./mk-ctxt ctxt_version < VERSION > ctxt/version.c

ctxt/version.o:\
	cc ctxt/version.c 
	./cc ctxt/version.c
deinstaller:\
	ld deinstaller.ld deinstaller.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
	./ld deinstaller deinstaller.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
deinstaller.o:\
	cc deinstaller.c install.h 
	./cc deinstaller.c
dir_array.a:\
	mk-slib dir_array.sld dir_array.o 
	./mk-slib dir_array dir_array.o 
dir_array.o:\
	cc dir_array.c alloc.h bin.h dir_array.h direntry.h str.h 
	./cc dir_array.c
dir_hash.a:\
	mk-slib dir_hash.sld dir_hash.o 
	./mk-slib dir_hash dir_hash.o 
dir_hash.o:\
	cc dir_hash.c alloc.h bin.h dir_array.h dir_hash.h str.h 
	./cc dir_hash.c
dir_name.a:\
	mk-slib dir_name.sld dir_name.o 
	./mk-slib dir_name dir_name.o 
dir_name.o:\
	cc dir_name.c bin.h dir_name.h str.h 
	./cc dir_name.c
dstring.a:\
	mk-slib dstring.sld dstring_cpyb.o dstring_cpys.o dstring_copy.o \
	dstring_cat.o dstring_catb.o dstring_cats.o dstring_cat0.o \
	dstring_0.o dstring_chop.o dstring_init.o dstring_trunc.o 
	./mk-slib dstring dstring_cpyb.o dstring_cpys.o dstring_copy.o \
	dstring_cat.o dstring_catb.o dstring_cats.o dstring_cat0.o \
	dstring_0.o dstring_chop.o dstring_init.o dstring_trunc.o 
dstring_0.o:\
	cc dstring_0.c dstring.h 
	./cc dstring_0.c
dstring_cat.o:\
	cc dstring_cat.c dstring.h 
	./cc dstring_cat.c
dstring_cat0.o:\
	cc dstring_cat0.c dstring.h 
	./cc dstring_cat0.c
dstring_catb.o:\
	cc dstring_catb.c alloc.h bin.h dstring.h 
	./cc dstring_catb.c
dstring_cats.o:\
	cc dstring_cats.c alloc.h bin.h dstring.h str.h 
	./cc dstring_cats.c
dstring_chop.o:\
	cc dstring_chop.c dstring.h 
	./cc dstring_chop.c
dstring_copy.o:\
	cc dstring_copy.c dstring.h 
	./cc dstring_copy.c
dstring_cpyb.o:\
	cc dstring_cpyb.c alloc.h bin.h dstring.h 
	./cc dstring_cpyb.c
dstring_cpys.o:\
	cc dstring_cpys.c dstring.h str.h 
	./cc dstring_cpys.c
dstring_init.o:\
	cc dstring_init.c alloc.h dstring.h 
	./cc dstring_init.c
dstring_trunc.o:\
	cc dstring_trunc.c dstring.h 
	./cc dstring_trunc.c
env.a:\
	mk-slib env.sld env.o env_get.o 
	./mk-slib env env.o env_get.o 
env.o:\
	cc env.c alloc.h bin.h env.h str.h 
	./cc env.c
env_get.o:\
	cc env_get.c env.h str.h 
	./cc env_get.c
error.a:\
	mk-slib error.sld error.o error_str.o 
	./mk-slib error error.o error_str.o 
error.o:\
	cc error.c error.h 
	./cc error.c
error_str.o:\
	cc error_str.c error.h 
	./cc error_str.c
fd.a:\
	mk-slib fd.sld fd_dup.o fd_move.o fd_reset.o 
	./mk-slib fd fd_dup.o fd_move.o fd_reset.o 
fd_dup.o:\
	cc fd_dup.c close.h fd.h 
	./cc fd_dup.c
fd_move.o:\
	cc fd_move.c close.h fd.h 
	./cc fd_move.c
fd_reset.o:\
	cc fd_reset.c fd.h 
	./cc fd_reset.c
float32.a:\
	mk-slib float32.sld float32_pack.o float32_upack.o 
	./mk-slib float32 float32_pack.o float32_upack.o 
float32_pack.o:\
	cc float32_pack.c byteorder.h float32.h 
	./cc float32_pack.c
float32_upack.o:\
	cc float32_upack.c byteorder.h float32.h 
	./cc float32_upack.c
float64.a:\
	mk-slib float64.sld float64_pack.o float64_upack.o 
	./mk-slib float64 float64_pack.o float64_upack.o 
float64_pack.o:\
	cc float64_pack.c byteorder.h float64.h 
	./cc float64_pack.c
float64_upack.o:\
	cc float64_upack.c byteorder.h float64.h 
	./cc float64_upack.c
fmt.a:\
	mk-slib fmt.sld fmt_nstr.o fmt_str.o fmt_uchar.o fmt_ucharo.o \
	fmt_ucharx.o fmt_uint.o fmt_uinto.o fmt_uintx.o fmt_ullong.o \
	fmt_ullongo.o fmt_ullongx.o fmt_ulong.o fmt_ulongo.o fmt_ulongx.o \
	fmt_ushort.o fmt_ushorto.o fmt_ushortx.o 
	./mk-slib fmt fmt_nstr.o fmt_str.o fmt_uchar.o fmt_ucharo.o \
	fmt_ucharx.o fmt_uint.o fmt_uinto.o fmt_uintx.o fmt_ullong.o \
	fmt_ullongo.o fmt_ullongx.o fmt_ulong.o fmt_ulongo.o fmt_ulongx.o \
	fmt_ushort.o fmt_ushorto.o fmt_ushortx.o 
fmt_nstr.o:\
	cc fmt_nstr.c fmt.h 
	./cc fmt_nstr.c
fmt_spec.a:\
	mk-slib fmt_spec.sld fmt_u32.o fmt_u32o.o fmt_u32x.o fmt_u64.o \
	fmt_u64o.o fmt_u64x.o 
	./mk-slib fmt_spec fmt_u32.o fmt_u32o.o fmt_u32x.o fmt_u64.o \
	fmt_u64o.o fmt_u64x.o 
fmt_str.o:\
	cc fmt_str.c fmt.h 
	./cc fmt_str.c
fmt_u32.o:\
	cc fmt_u32.c fmt_spec.h uint32.h uint64.h 
	./cc fmt_u32.c
fmt_u32o.o:\
	cc fmt_u32o.c fmt_spec.h uint32.h uint64.h 
	./cc fmt_u32o.c
fmt_u32x.o:\
	cc fmt_u32x.c fmt_spec.h uint32.h uint64.h 
	./cc fmt_u32x.c
fmt_u64.o:\
	cc fmt_u64.c fmt_spec.h uint64.h 
	./cc fmt_u64.c
fmt_u64o.o:\
	cc fmt_u64o.c fmt_spec.h uint64.h 
	./cc fmt_u64o.c
fmt_u64x.o:\
	cc fmt_u64x.c fmt_spec.h uint64.h 
	./cc fmt_u64x.c
fmt_uchar.o:\
	cc fmt_uchar.c fmt.h 
	./cc fmt_uchar.c
fmt_ucharo.o:\
	cc fmt_ucharo.c fmt.h 
	./cc fmt_ucharo.c
fmt_ucharx.o:\
	cc fmt_ucharx.c fmt.h 
	./cc fmt_ucharx.c
fmt_uint.o:\
	cc fmt_uint.c fmt.h 
	./cc fmt_uint.c
fmt_uinto.o:\
	cc fmt_uinto.c fmt.h 
	./cc fmt_uinto.c
fmt_uintx.o:\
	cc fmt_uintx.c fmt.h 
	./cc fmt_uintx.c
fmt_ullong.o:\
	cc fmt_ullong.c fmt.h 
	./cc fmt_ullong.c
fmt_ullongo.o:\
	cc fmt_ullongo.c fmt.h 
	./cc fmt_ullongo.c
fmt_ullongx.o:\
	cc fmt_ullongx.c fmt.h 
	./cc fmt_ullongx.c
fmt_ulong.o:\
	cc fmt_ulong.c fmt.h 
	./cc fmt_ulong.c
fmt_ulongo.o:\
	cc fmt_ulongo.c fmt.h 
	./cc fmt_ulongo.c
fmt_ulongx.o:\
	cc fmt_ulongx.c fmt.h 
	./cc fmt_ulongx.c
fmt_ushort.o:\
	cc fmt_ushort.c fmt.h 
	./cc fmt_ushort.c
fmt_ushorto.o:\
	cc fmt_ushorto.c fmt.h 
	./cc fmt_ushorto.c
fmt_ushortx.o:\
	cc fmt_ushortx.c fmt.h 
	./cc fmt_ushortx.c
get_opt.a:\
	mk-slib get_opt.sld get_opt.o 
	./mk-slib get_opt get_opt.o 
get_opt.o:\
	cc get_opt.c buffer.h get_opt.h 
	./cc get_opt.c
hashtable.a:\
	mk-slib hashtable.sld ht_init.o ht_hash.o ht_free.o ht_addb.o \
	ht_adds.o ht_deleteb.o ht_deletes.o ht_getb.o ht_gets.o \
	ht_replaceb.o ht_replaces.o ht_bytes.o 
	./mk-slib hashtable ht_init.o ht_hash.o ht_free.o ht_addb.o \
	ht_adds.o ht_deleteb.o ht_deletes.o ht_getb.o ht_gets.o \
	ht_replaceb.o ht_replaces.o ht_bytes.o 
ht_addb.o:\
	cc ht_addb.c alloc.h bin.h error.h hashtable.h 
	./cc ht_addb.c
ht_adds.o:\
	cc ht_adds.c hashtable.h str.h 
	./cc ht_adds.c
ht_bytes.o:\
	cc ht_bytes.c hashtable.h 
	./cc ht_bytes.c
ht_deleteb.o:\
	cc ht_deleteb.c alloc.h bin.h hashtable.h 
	./cc ht_deleteb.c
ht_deletes.o:\
	cc ht_deletes.c hashtable.h str.h 
	./cc ht_deletes.c
ht_free.o:\
	cc ht_free.c alloc.h hashtable.h 
	./cc ht_free.c
ht_getb.o:\
	cc ht_getb.c bin.h hashtable.h 
	./cc ht_getb.c
ht_gets.o:\
	cc ht_gets.c hashtable.h str.h 
	./cc ht_gets.c
ht_hash.o:\
	cc ht_hash.c hashtable.h 
	./cc ht_hash.c
ht_init.o:\
	cc ht_init.c bin.h hashtable.h 
	./cc ht_init.c
ht_replaceb.o:\
	cc ht_replaceb.c alloc.h bin.h hashtable.h 
	./cc ht_replaceb.c
ht_replaces.o:\
	cc ht_replaces.c hashtable.h str.h 
	./cc ht_replaces.c
iarray.a:\
	mk-slib iarray.sld iarray_bytes.o iarray_cat.o iarray_chop.o \
	iarray_copy.o iarray_free.o iarray_index.o iarray_init.o \
	iarray_insert.o iarray_node.o iarray_remove.o iarray_size.o \
	iarray_zero.o 
	./mk-slib iarray iarray_bytes.o iarray_cat.o iarray_chop.o \
	iarray_copy.o iarray_free.o iarray_index.o iarray_init.o \
	iarray_insert.o iarray_node.o iarray_remove.o iarray_size.o \
	iarray_zero.o 
iarray_bytes.o:\
	cc iarray_bytes.c iarray.h 
	./cc iarray_bytes.c
iarray_cat.o:\
	cc iarray_cat.c alloc.h iarray.h 
	./cc iarray_cat.c
iarray_chop.o:\
	cc iarray_chop.c alloc.h iarray.h 
	./cc iarray_chop.c
iarray_copy.o:\
	cc iarray_copy.c alloc.h iarray.h 
	./cc iarray_copy.c
iarray_free.o:\
	cc iarray_free.c alloc.h iarray.h 
	./cc iarray_free.c
iarray_index.o:\
	cc iarray_index.c iarray.h 
	./cc iarray_index.c
iarray_init.o:\
	cc iarray_init.c alloc.h iarray.h 
	./cc iarray_init.c
iarray_insert.o:\
	cc iarray_insert.c alloc.h iarray.h 
	./cc iarray_insert.c
iarray_node.o:\
	cc iarray_node.c alloc.h bin.h iarray.h 
	./cc iarray_node.c
iarray_remove.o:\
	cc iarray_remove.c alloc.h iarray.h 
	./cc iarray_remove.c
iarray_size.o:\
	cc iarray_size.c iarray.h 
	./cc iarray_size.c
iarray_zero.o:\
	cc iarray_zero.c iarray.h 
	./cc iarray_zero.c
inst-check:\
	ld inst-check.ld inst-check.o install_error.o 
	./ld inst-check inst-check.o install_error.o 
inst-check.o:\
	cc inst-check.c install.h 
	./cc inst-check.c
inst-copy:\
	ld inst-copy.ld inst-copy.o install_error.o 
	./ld inst-copy inst-copy.o install_error.o 
inst-copy.o:\
	cc inst-copy.c install.h 
	./cc inst-copy.c
inst-dir:\
	ld inst-dir.ld inst-dir.o install_error.o 
	./ld inst-dir inst-dir.o install_error.o 
inst-dir.o:\
	cc inst-dir.c install.h 
	./cc inst-dir.c
inst-link:\
	ld inst-link.ld inst-link.o install_error.o 
	./ld inst-link inst-link.o install_error.o 
inst-link.o:\
	cc inst-link.c install.h 
	./cc inst-link.c
install_core.o:\
	cc install_core.c install.h 
	./cc install_core.c
install_error.o:\
	cc install_error.c install.h 
	./cc install_error.c
installer:\
	ld installer.ld installer.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
	./ld installer installer.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
installer.o:\
	cc installer.c install.h 
	./cc installer.c
instchk:\
	ld instchk.ld instchk.o insthier.o install_core.o install_error.o \
	ctxt/ctxt.a 
	./ld instchk instchk.o insthier.o install_core.o install_error.o \
	ctxt/ctxt.a 
instchk.o:\
	cc instchk.c install.h 
	./cc instchk.c
insthier.o:\
	cc insthier.c install.h ctxt.h 
	./cc insthier.c
int16.a:\
	mk-slib int16.sld int16_pack.o int16_unpack.o 
	./mk-slib int16 int16_pack.o int16_unpack.o 
int16_pack.o:\
	cc int16_pack.c int16.h 
	./cc int16_pack.c
int16_unpack.o:\
	cc int16_unpack.c int16.h 
	./cc int16_unpack.c
int32.a:\
	mk-slib int32.sld int32_pack.o int32_unpack.o 
	./mk-slib int32 int32_pack.o int32_unpack.o 
int32_pack.o:\
	cc int32_pack.c int32.h 
	./cc int32_pack.c
int32_unpack.o:\
	cc int32_unpack.c int32.h 
	./cc int32_unpack.c
int64.a:\
	mk-slib int64.sld int64_pack.o int64_unpack.o 
	./mk-slib int64 int64_pack.o int64_unpack.o 
int64_pack.o:\
	cc int64_pack.c int64.h 
	./cc int64_pack.c
int64_unpack.o:\
	cc int64_unpack.c int64.h 
	./cc int64_unpack.c
ld: conf-ld sysdeps.out libs-sysmath 
mk-cctype: conf-cc conf-systype 
mk-ctxt.o:\
	cc mk-ctxt.c
	./cc mk-ctxt.c
mk-ctxt:\
	ld mk-ctxt.o mk-ctxt.ld
	./ld mk-ctxt mk-ctxt.o
mk-slib: conf-systype 
mk-sosuffix: conf-systype 
nonblock.a:\
	mk-slib nonblock.sld nonblock.o 
	./mk-slib nonblock nonblock.o 
nonblock.o:\
	cc nonblock.c nonblock.h 
	./cc nonblock.c
open.a:\
	mk-slib open.sld open_append.o open_creat.o open_excl.o open_ro.o \
	open_rw.o open_trunc.o open_wo.o 
	./mk-slib open open_append.o open_creat.o open_excl.o open_ro.o \
	open_rw.o open_trunc.o open_wo.o 
open_append.o:\
	cc open_append.c open.h 
	./cc open_append.c
open_creat.o:\
	cc open_creat.c open.h 
	./cc open_creat.c
open_excl.o:\
	cc open_excl.c open.h 
	./cc open_excl.c
open_ro.o:\
	cc open_ro.c open.h 
	./cc open_ro.c
open_rw.o:\
	cc open_rw.c open.h 
	./cc open_rw.c
open_trunc.o:\
	cc open_trunc.c open.h 
	./cc open_trunc.c
open_wo.o:\
	cc open_wo.c open.h 
	./cc open_wo.c
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
scan_charset.o:\
	cc scan_charset.c scan.h 
	./cc scan_charset.c
scan_double.o:\
	cc scan_double.c scan.h 
	./cc scan_double.c
scan_f32.o:\
	cc scan_f32.c scan_fspec.h 
	./cc scan_f32.c
scan_f64.o:\
	cc scan_f64.c scan_fspec.h 
	./cc scan_f64.c
scan_float.o:\
	cc scan_float.c scan.h 
	./cc scan_float.c
scan_fspec.a:\
	mk-slib scan_fspec.sld scan_f32.o scan_f64.o 
	./mk-slib scan_fspec scan_f32.o scan_f64.o 
scan_ncharset.o:\
	cc scan_ncharset.c scan.h 
	./cc scan_ncharset.c
scan_newline.o:\
	cc scan_newline.c scan.h 
	./cc scan_newline.c
scan_space.o:\
	cc scan_space.c scan.h 
	./cc scan_space.c
scan_spec.a:\
	mk-slib scan_spec.sld scan_u32.o scan_u32o.o scan_u32x.o scan_u64.o \
	scan_u64o.o scan_u64x.o 
	./mk-slib scan_spec scan_u32.o scan_u32o.o scan_u32x.o scan_u64.o \
	scan_u64o.o scan_u64x.o 
scan_u32.o:\
	cc scan_u32.c scan_spec.h uint32.h uint64.h 
	./cc scan_u32.c
scan_u32o.o:\
	cc scan_u32o.c scan_spec.h uint32.h uint64.h 
	./cc scan_u32o.c
scan_u32x.o:\
	cc scan_u32x.c scan_spec.h uint32.h uint64.h 
	./cc scan_u32x.c
scan_u64.o:\
	cc scan_u64.c scan_spec.h uint64.h 
	./cc scan_u64.c
scan_u64o.o:\
	cc scan_u64o.c scan_spec.h uint64.h 
	./cc scan_u64o.c
scan_u64x.o:\
	cc scan_u64x.c scan_spec.h uint64.h 
	./cc scan_u64x.c
scan_uchar.o:\
	cc scan_uchar.c scan.h 
	./cc scan_uchar.c
scan_ucharo.o:\
	cc scan_ucharo.c scan.h 
	./cc scan_ucharo.c
scan_ucharx.o:\
	cc scan_ucharx.c scan.h 
	./cc scan_ucharx.c
scan_uint.o:\
	cc scan_uint.c scan.h 
	./cc scan_uint.c
scan_uinto.o:\
	cc scan_uinto.c scan.h 
	./cc scan_uinto.c
scan_uintx.o:\
	cc scan_uintx.c scan.h 
	./cc scan_uintx.c
scan_ullong.o:\
	cc scan_ullong.c scan.h 
	./cc scan_ullong.c
scan_ullongo.o:\
	cc scan_ullongo.c scan.h 
	./cc scan_ullongo.c
scan_ullongx.o:\
	cc scan_ullongx.c scan.h 
	./cc scan_ullongx.c
scan_ulong.o:\
	cc scan_ulong.c scan.h 
	./cc scan_ulong.c
scan_ulongo.o:\
	cc scan_ulongo.c scan.h 
	./cc scan_ulongo.c
scan_ulongx.o:\
	cc scan_ulongx.c scan.h 
	./cc scan_ulongx.c
scan_ushort.o:\
	cc scan_ushort.c scan.h 
	./cc scan_ushort.c
scan_ushorto.o:\
	cc scan_ushorto.c scan.h 
	./cc scan_ushorto.c
scan_ushortx.o:\
	cc scan_ushortx.c scan.h 
	./cc scan_ushortx.c
seek.a:\
	mk-slib seek.sld seek_cur.o seek_end.o seek_pos.o seek_start.o 
	./mk-slib seek seek_cur.o seek_end.o seek_pos.o seek_start.o 
seek_cur.o:\
	cc seek_cur.c int64.h seek.h 
	./cc seek_cur.c
seek_end.o:\
	cc seek_end.c int64.h seek.h 
	./cc seek_end.c
seek_pos.o:\
	cc seek_pos.c int64.h seek.h 
	./cc seek_pos.c
seek_start.o:\
	cc seek_start.c int64.h seek.h 
	./cc seek_start.c
sgetline.a:\
	mk-slib sgetline.sld sgetline.o sgetline_chop.o sgetline_get.o 
	./mk-slib sgetline sgetline.o sgetline_chop.o sgetline_get.o 
sgetline.o:\
	cc sgetline.c sgetline.h 
	./cc sgetline.c
sgetline_chop.o:\
	cc sgetline_chop.c sgetline.h 
	./cc sgetline_chop.c
sgetline_get.o:\
	cc sgetline_get.c bin.h buffer.h sgetline.h sstring.h 
	./cc sgetline_get.c
sig.a:\
	mk-slib sig.sld sig.o sig_block.o sig_catch.o sig_pause.o 
	./mk-slib sig sig.o sig_block.o sig_catch.o sig_pause.o 
sig.o:\
	cc sig.c sig.h 
	./cc sig.c
sig_block.o:\
	cc sig_block.c sig.h sig_pmask.h 
	./cc sig_block.c
sig_catch.o:\
	cc sig_catch.c sig.h sig_action.h 
	./cc sig_catch.c
sig_pause.o:\
	cc sig_pause.c sig.h sig_pmask.h 
	./cc sig_pause.c
sstring.a:\
	mk-slib sstring.sld sstring_0.o sstring_cat.o sstring_catb.o \
	sstring_cats.o sstring_copy.o sstring_cpyb.o sstring_cpys.o \
	sstring_init.o sstring_chop.o 
	./mk-slib sstring sstring_0.o sstring_cat.o sstring_catb.o \
	sstring_cats.o sstring_copy.o sstring_cpyb.o sstring_cpys.o \
	sstring_init.o sstring_chop.o 
sstring_0.o:\
	cc sstring_0.c sstring.h 
	./cc sstring_0.c
sstring_cat.o:\
	cc sstring_cat.c sstring.h 
	./cc sstring_cat.c
sstring_catb.o:\
	cc sstring_catb.c sstring.h 
	./cc sstring_catb.c
sstring_cats.o:\
	cc sstring_cats.c sstring.h 
	./cc sstring_cats.c
sstring_chop.o:\
	cc sstring_chop.c sstring.h 
	./cc sstring_chop.c
sstring_copy.o:\
	cc sstring_copy.c sstring.h 
	./cc sstring_copy.c
sstring_cpyb.o:\
	cc sstring_cpyb.c sstring.h 
	./cc sstring_cpyb.c
sstring_cpys.o:\
	cc sstring_cpys.c sstring.h 
	./cc sstring_cpys.c
sstring_init.o:\
	cc sstring_init.c sstring.h 
	./cc sstring_init.c
stalloc.a:\
	mk-slib stalloc.sld stalloc.o 
	./mk-slib stalloc stalloc.o 
stalloc.o:\
	cc stalloc.c error.h stalloc.h 
	./cc stalloc.c
str.a:\
	mk-slib str.sld str_char.o str_chr.o str_ci_diff.o str_ci_ndiff.o \
	str_diff.o str_dup.o str_ends.o str_len.o str_ndiff.o str_rchar.o \
	str_rchr.o str_starts.o str_tolower.o str_toupper.o 
	./mk-slib str str_char.o str_chr.o str_ci_diff.o str_ci_ndiff.o \
	str_diff.o str_dup.o str_ends.o str_len.o str_ndiff.o str_rchar.o \
	str_rchr.o str_starts.o str_tolower.o str_toupper.o 
str_char.o:\
	cc str_char.c str.h 
	./cc str_char.c
str_chr.o:\
	cc str_chr.c str.h 
	./cc str_chr.c
str_ci_diff.o:\
	cc str_ci_diff.c str.h 
	./cc str_ci_diff.c
str_ci_ndiff.o:\
	cc str_ci_ndiff.c str.h 
	./cc str_ci_ndiff.c
str_diff.o:\
	cc str_diff.c str.h 
	./cc str_diff.c
str_dup.o:\
	cc str_dup.c alloc.h bin.h str.h 
	./cc str_dup.c
str_ends.o:\
	cc str_ends.c str.h 
	./cc str_ends.c
str_len.o:\
	cc str_len.c str.h 
	./cc str_len.c
str_ndiff.o:\
	cc str_ndiff.c str.h 
	./cc str_ndiff.c
str_rchar.o:\
	cc str_rchar.c str.h 
	./cc str_rchar.c
str_rchr.o:\
	cc str_rchr.c str.h 
	./cc str_rchr.c
str_starts.o:\
	cc str_starts.c str.h 
	./cc str_starts.c
str_tolower.o:\
	cc str_tolower.c str.h 
	./cc str_tolower.c
str_toupper.o:\
	cc str_toupper.c str.h 
	./cc str_toupper.c
syserr.a:\
	mk-slib syserr.sld syserr_die.o syserr_init.o 
	./mk-slib syserr syserr_die.o syserr_init.o 
syserr_die.o:\
	cc syserr_die.c buffer.h exit.h syserr.h 
	./cc syserr_die.c
syserr_init.o:\
	cc syserr_init.c error.h syserr.h 
	./cc syserr_init.c
uint16.a:\
	mk-slib uint16.sld uint16_pack.o uint16_unpack.o 
	./mk-slib uint16 uint16_pack.o uint16_unpack.o 
uint16_pack.o:\
	cc uint16_pack.c uint16.h 
	./cc uint16_pack.c
uint16_unpack.o:\
	cc uint16_unpack.c uint16.h 
	./cc uint16_unpack.c
uint32.a:\
	mk-slib uint32.sld uint32_pack.o uint32_unpack.o 
	./mk-slib uint32 uint32_pack.o uint32_unpack.o 
uint32_pack.o:\
	cc uint32_pack.c uint32.h 
	./cc uint32_pack.c
uint32_unpack.o:\
	cc uint32_unpack.c uint32.h 
	./cc uint32_unpack.c
uint64.a:\
	mk-slib uint64.sld uint64_pack.o uint64_unpack.o 
	./mk-slib uint64 uint64_pack.o uint64_unpack.o 
uint64_pack.o:\
	cc uint64_pack.c uint64.h 
	./cc uint64_pack.c
uint64_unpack.o:\
	cc uint64_unpack.c uint64.h 
	./cc uint64_unpack.c
clean: sysdeps_clean tests_clean 
	rm -f alloc.a alloc.o array.a array.o array_bytes.o array_cat.o \
	array_chop.o array_copy.o array_data.o array_index.o array_size.o \
	base_name.a base_name.o bin.a bin_char.o bin_chr.o bin_copy.o \
	bin_copyr.o bin_count.o bin_diff.o bin_rchar.o bin_rchr.o bin_set.o \
	bin_tolower.o bin_toupper.o bin_zero.o buffer.a buffer0.o buffer1.o \
	buffer2.o buffer_copy.o buffer_get.o buffer_init.o buffer_put.o \
	closeonexec.a closeonexec.o corelib-conf corelib-conf.o \
	ctxt/bindir.c ctxt/bindir.o ctxt/ctxt.a ctxt/dlibdir.c \
	ctxt/dlibdir.o ctxt/incdir.c ctxt/incdir.o ctxt/repos.c ctxt/repos.o \
	ctxt/slibdir.c ctxt/slibdir.o ctxt/version.c ctxt/version.o \
	deinstaller deinstaller.o dir_array.a dir_array.o dir_hash.a \
	dir_hash.o dir_name.a dir_name.o dstring.a dstring_0.o dstring_cat.o \
	dstring_cat0.o dstring_catb.o 
	rm -f dstring_cats.o dstring_chop.o dstring_copy.o dstring_cpyb.o \
	dstring_cpys.o dstring_init.o dstring_trunc.o env.a env.o env_get.o \
	error.a error.o error_str.o fd.a fd_dup.o fd_move.o fd_reset.o \
	float32.a float32_pack.o float32_upack.o float64.a float64_pack.o \
	float64_upack.o fmt.a fmt_nstr.o fmt_spec.a fmt_str.o fmt_u32.o \
	fmt_u32o.o fmt_u32x.o fmt_u64.o fmt_u64o.o fmt_u64x.o fmt_uchar.o \
	fmt_ucharo.o fmt_ucharx.o fmt_uint.o fmt_uinto.o fmt_uintx.o \
	fmt_ullong.o fmt_ullongo.o fmt_ullongx.o fmt_ulong.o fmt_ulongo.o \
	fmt_ulongx.o fmt_ushort.o fmt_ushorto.o fmt_ushortx.o get_opt.a \
	get_opt.o hashtable.a ht_addb.o ht_adds.o ht_bytes.o ht_deleteb.o \
	ht_deletes.o ht_free.o ht_getb.o ht_gets.o ht_hash.o ht_init.o \
	ht_replaceb.o ht_replaces.o iarray.a 
	rm -f iarray_bytes.o iarray_cat.o iarray_chop.o iarray_copy.o \
	iarray_free.o iarray_index.o iarray_init.o iarray_insert.o \
	iarray_node.o iarray_remove.o iarray_size.o iarray_zero.o inst-check \
	inst-check.o inst-copy inst-copy.o inst-dir inst-dir.o inst-link \
	inst-link.o install_core.o install_error.o installer installer.o \
	instchk instchk.o insthier.o int16.a int16_pack.o int16_unpack.o \
	int32.a int32_pack.o int32_unpack.o int64.a int64_pack.o \
	int64_unpack.o nonblock.a nonblock.o open.a open_append.o \
	open_creat.o open_excl.o open_ro.o open_rw.o open_trunc.o open_wo.o \
	scan.a scan_charset.o scan_double.o scan_f32.o scan_f64.o \
	scan_float.o scan_fspec.a scan_ncharset.o scan_newline.o \
	scan_space.o scan_spec.a scan_u32.o scan_u32o.o scan_u32x.o \
	scan_u64.o scan_u64o.o scan_u64x.o scan_uchar.o 
	rm -f scan_ucharo.o scan_ucharx.o scan_uint.o scan_uinto.o \
	scan_uintx.o scan_ullong.o scan_ullongo.o scan_ullongx.o \
	scan_ulong.o scan_ulongo.o scan_ulongx.o scan_ushort.o \
	scan_ushorto.o scan_ushortx.o seek.a seek_cur.o seek_end.o \
	seek_pos.o seek_start.o sgetline.a sgetline.o sgetline_chop.o \
	sgetline_get.o sig.a sig.o sig_block.o sig_catch.o sig_pause.o \
	sstring.a sstring_0.o sstring_cat.o sstring_catb.o sstring_cats.o \
	sstring_chop.o sstring_copy.o sstring_cpyb.o sstring_cpys.o \
	sstring_init.o stalloc.a stalloc.o str.a str_char.o str_chr.o \
	str_ci_diff.o str_ci_ndiff.o str_diff.o str_dup.o str_ends.o \
	str_len.o str_ndiff.o str_rchar.o str_rchr.o str_starts.o \
	str_tolower.o str_toupper.o syserr.a syserr_die.o syserr_init.o \
	uint16.a uint16_pack.o uint16_unpack.o uint32.a uint32_pack.o \
	uint32_unpack.o 
	rm -f uint64.a uint64_pack.o uint64_unpack.o 

deinstall: deinstaller inst-check inst-copy inst-dir inst-link
	./deinstaller
deinstall-dryrun: deinstaller inst-check inst-copy inst-dir inst-link
	./deinstaller dryrun
install: installer inst-check inst-copy inst-dir inst-link postinstall
	./installer
	./postinstall

install-dryrun: installer inst-check inst-copy inst-dir inst-link
	./installer dryrun
install-check: instchk inst-check
	./instchk
tests:
	(cd UNIT_TESTS; make && make tests)
tests_clean:
	(cd UNIT_TESTS; make clean)
regen:
	cpj-genmk > Makefile.tmp
	mv Makefile.tmp Makefile

