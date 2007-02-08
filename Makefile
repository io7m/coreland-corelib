# auto generated - do not edit

default: all

all: sysdeps.out \
	alloc.a array.a base_name.a bin.a buffer.a closeonexec.a \
	corelib-conf ctxt/ctxt.a deinstaller dir_array.a dir_hash.a \
	dir_name.a dstring.a env.a error.a fd.a float32.a float64.a fmt.a \
	fmt_spec.a get_opt.a hashtable.a iarray.a inst-check inst-copy \
	inst-dir inst-link installer instchk int16.a int32.a int64.a \
	nonblock.a open.a sarray.a scan.a scan_fspec.a scan_spec.a seek.a \
	sgetline.a sig.a squeue.a sstack.a sstring.a stalloc.a str.a \
	syserr.a uint16.a uint32.a uint64.a 

sysdeps: sysdeps.out
sysdeps.out:
	SYSDEPS/sysdep-header sysdeps.out
	(cd SYSDEPS && make)
sysdeps_clean:
	(cd SYSDEPS && make clean)
	rm -f sysdeps.out

alloc.a:\
	cc-slib alloc.sld alloc.o 
	./cc-slib alloc alloc.o 
alloc.o:\
	cc-compile alloc.c alloc.h 
	./cc-compile alloc.c
array.a:\
	cc-slib array.sld array.o array_bytes.o array_cat.o array_chop.o \
	array_copy.o array_index.o array_size.o array_trunc.o array_zero.o 
	./cc-slib array array.o array_bytes.o array_cat.o array_chop.o \
	array_copy.o array_index.o array_size.o array_trunc.o array_zero.o 
array.o:\
	cc-compile array.c alloc.h array.h 
	./cc-compile array.c
array_bytes.o:\
	cc-compile array_bytes.c array.h 
	./cc-compile array_bytes.c
array_cat.o:\
	cc-compile array_cat.c alloc.h array.h bin.h 
	./cc-compile array_cat.c
array_chop.o:\
	cc-compile array_chop.c array.h 
	./cc-compile array_chop.c
array_copy.o:\
	cc-compile array_copy.c array.h bin.h 
	./cc-compile array_copy.c
array_data.o:\
	cc-compile array_data.c array.h 
	./cc-compile array_data.c
array_index.o:\
	cc-compile array_index.c array.h 
	./cc-compile array_index.c
array_size.o:\
	cc-compile array_size.c array.h 
	./cc-compile array_size.c
array_trunc.o:\
	cc-compile array_trunc.c array.h 
	./cc-compile array_trunc.c
array_zero.o:\
	cc-compile array_zero.c array.h 
	./cc-compile array_zero.c
base_name.a:\
	cc-slib base_name.sld base_name.o 
	./cc-slib base_name base_name.o 
base_name.o:\
	cc-compile base_name.c bin.h base_name.h str.h 
	./cc-compile base_name.c
bin.a:\
	cc-slib bin.sld bin_char.o bin_rchar.o bin_chr.o bin_copy.o \
	bin_copyr.o bin_count.o bin_diff.o bin_rchr.o bin_set.o \
	bin_tolower.o bin_toupper.o bin_zero.o 
	./cc-slib bin bin_char.o bin_rchar.o bin_chr.o bin_copy.o \
	bin_copyr.o bin_count.o bin_diff.o bin_rchr.o bin_set.o \
	bin_tolower.o bin_toupper.o bin_zero.o 
bin_char.o:\
	cc-compile bin_char.c bin.h 
	./cc-compile bin_char.c
bin_chr.o:\
	cc-compile bin_chr.c bin.h 
	./cc-compile bin_chr.c
bin_copy.o:\
	cc-compile bin_copy.c bin.h 
	./cc-compile bin_copy.c
bin_copyr.o:\
	cc-compile bin_copyr.c bin.h 
	./cc-compile bin_copyr.c
bin_count.o:\
	cc-compile bin_count.c bin.h 
	./cc-compile bin_count.c
bin_diff.o:\
	cc-compile bin_diff.c bin.h 
	./cc-compile bin_diff.c
bin_rchar.o:\
	cc-compile bin_rchar.c bin.h 
	./cc-compile bin_rchar.c
bin_rchr.o:\
	cc-compile bin_rchr.c bin.h 
	./cc-compile bin_rchr.c
bin_set.o:\
	cc-compile bin_set.c bin.h 
	./cc-compile bin_set.c
bin_tolower.o:\
	cc-compile bin_tolower.c bin.h 
	./cc-compile bin_tolower.c
bin_toupper.o:\
	cc-compile bin_toupper.c bin.h 
	./cc-compile bin_toupper.c
bin_zero.o:\
	cc-compile bin_zero.c bin.h 
	./cc-compile bin_zero.c
buffer.a:\
	cc-slib buffer.sld buffer0.o buffer1.o buffer2.o buffer_get.o \
	buffer_init.o buffer_put.o buffer_copy.o 
	./cc-slib buffer buffer0.o buffer1.o buffer2.o buffer_get.o \
	buffer_init.o buffer_put.o buffer_copy.o 
buffer0.o:\
	cc-compile buffer0.c buffer.h read.h 
	./cc-compile buffer0.c
buffer1.o:\
	cc-compile buffer1.c buffer.h write.h 
	./cc-compile buffer1.c
buffer2.o:\
	cc-compile buffer2.c buffer.h write.h 
	./cc-compile buffer2.c
buffer_copy.o:\
	cc-compile buffer_copy.c buffer.h 
	./cc-compile buffer_copy.c
buffer_get.o:\
	cc-compile buffer_get.c bin.h buffer.h error.h 
	./cc-compile buffer_get.c
buffer_init.o:\
	cc-compile buffer_init.c buffer.h 
	./cc-compile buffer_init.c
buffer_put.o:\
	cc-compile buffer_put.c bin.h buffer.h error.h str.h 
	./cc-compile buffer_put.c
cc-compile: conf-cc conf-cctype conf-cflags sysdeps.out 
cc-link: conf-ld sysdeps.out libs-sysmath 
cc-slib: conf-systype 
closeonexec.a:\
	cc-slib closeonexec.sld closeonexec.o 
	./cc-slib closeonexec closeonexec.o 
closeonexec.o:\
	cc-compile closeonexec.c closeonexec.h 
	./cc-compile closeonexec.c
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
	cc-link corelib-conf.ld corelib-conf.o ctxt/ctxt.a 
	./cc-link corelib-conf corelib-conf.o ctxt/ctxt.a 
corelib-conf.o:\
	cc-compile corelib-conf.c ctxt.h 
	./cc-compile corelib-conf.c
ctxt/bindir.c: mk-ctxt conf-bindir
	rm -f ctxt/bindir.c
	./mk-ctxt ctxt_bindir < conf-bindir > ctxt/bindir.c

ctxt/bindir.o:\
	cc-compile ctxt/bindir.c 
	./cc-compile ctxt/bindir.c
ctxt/ctxt.a:\
	cc-slib ctxt/ctxt.sld ctxt/bindir.o ctxt/dlibdir.o ctxt/incdir.o \
	ctxt/repos.o ctxt/slibdir.o ctxt/version.o 
	./cc-slib ctxt/ctxt ctxt/bindir.o ctxt/dlibdir.o ctxt/incdir.o \
	ctxt/repos.o ctxt/slibdir.o ctxt/version.o 
ctxt/dlibdir.c: mk-ctxt conf-dlibdir
	rm -f ctxt/dlibdir.c
	./mk-ctxt ctxt_dlibdir < conf-dlibdir > ctxt/dlibdir.c

ctxt/dlibdir.o:\
	cc-compile ctxt/dlibdir.c 
	./cc-compile ctxt/dlibdir.c
ctxt/incdir.c: mk-ctxt conf-incdir
	rm -f ctxt/incdir.c
	./mk-ctxt ctxt_incdir < conf-incdir > ctxt/incdir.c

ctxt/incdir.o:\
	cc-compile ctxt/incdir.c 
	./cc-compile ctxt/incdir.c
ctxt/repos.c: mk-ctxt conf-repos
	rm -f ctxt/repos.c
	./mk-ctxt ctxt_repos < conf-repos > ctxt/repos.c

ctxt/repos.o:\
	cc-compile ctxt/repos.c 
	./cc-compile ctxt/repos.c
ctxt/slibdir.c: mk-ctxt conf-slibdir
	rm -f ctxt/slibdir.c
	./mk-ctxt ctxt_slibdir < conf-slibdir > ctxt/slibdir.c

ctxt/slibdir.o:\
	cc-compile ctxt/slibdir.c 
	./cc-compile ctxt/slibdir.c
ctxt/version.c: mk-ctxt VERSION
	rm -f ctxt/version.c
	./mk-ctxt ctxt_version < VERSION > ctxt/version.c

ctxt/version.o:\
	cc-compile ctxt/version.c 
	./cc-compile ctxt/version.c
deinstaller:\
	cc-link deinstaller.ld deinstaller.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
	./cc-link deinstaller deinstaller.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
deinstaller.o:\
	cc-compile deinstaller.c install.h 
	./cc-compile deinstaller.c
dir_array.a:\
	cc-slib dir_array.sld dir_array.o 
	./cc-slib dir_array dir_array.o 
dir_array.o:\
	cc-compile dir_array.c alloc.h bin.h dir_array.h direntry.h str.h 
	./cc-compile dir_array.c
dir_hash.a:\
	cc-slib dir_hash.sld dir_hash.o 
	./cc-slib dir_hash dir_hash.o 
dir_hash.o:\
	cc-compile dir_hash.c alloc.h bin.h dir_array.h dir_hash.h str.h 
	./cc-compile dir_hash.c
dir_name.a:\
	cc-slib dir_name.sld dir_name.o 
	./cc-slib dir_name dir_name.o 
dir_name.o:\
	cc-compile dir_name.c bin.h dir_name.h str.h 
	./cc-compile dir_name.c
dstring.a:\
	cc-slib dstring.sld dstring_cpyb.o dstring_cpys.o dstring_copy.o \
	dstring_cat.o dstring_catb.o dstring_cats.o dstring_cat0.o \
	dstring_0.o dstring_chop.o dstring_init.o dstring_trunc.o 
	./cc-slib dstring dstring_cpyb.o dstring_cpys.o dstring_copy.o \
	dstring_cat.o dstring_catb.o dstring_cats.o dstring_cat0.o \
	dstring_0.o dstring_chop.o dstring_init.o dstring_trunc.o 
dstring_0.o:\
	cc-compile dstring_0.c dstring.h 
	./cc-compile dstring_0.c
dstring_cat.o:\
	cc-compile dstring_cat.c dstring.h 
	./cc-compile dstring_cat.c
dstring_cat0.o:\
	cc-compile dstring_cat0.c dstring.h 
	./cc-compile dstring_cat0.c
dstring_catb.o:\
	cc-compile dstring_catb.c alloc.h bin.h dstring.h 
	./cc-compile dstring_catb.c
dstring_cats.o:\
	cc-compile dstring_cats.c alloc.h bin.h dstring.h str.h 
	./cc-compile dstring_cats.c
dstring_chop.o:\
	cc-compile dstring_chop.c dstring.h 
	./cc-compile dstring_chop.c
dstring_copy.o:\
	cc-compile dstring_copy.c dstring.h 
	./cc-compile dstring_copy.c
dstring_cpyb.o:\
	cc-compile dstring_cpyb.c alloc.h bin.h dstring.h 
	./cc-compile dstring_cpyb.c
dstring_cpys.o:\
	cc-compile dstring_cpys.c dstring.h str.h 
	./cc-compile dstring_cpys.c
dstring_init.o:\
	cc-compile dstring_init.c alloc.h dstring.h 
	./cc-compile dstring_init.c
dstring_trunc.o:\
	cc-compile dstring_trunc.c dstring.h 
	./cc-compile dstring_trunc.c
env.a:\
	cc-slib env.sld env.o env_get.o 
	./cc-slib env env.o env_get.o 
env.o:\
	cc-compile env.c alloc.h bin.h env.h str.h 
	./cc-compile env.c
env_get.o:\
	cc-compile env_get.c env.h str.h 
	./cc-compile env_get.c
error.a:\
	cc-slib error.sld error.o error_str.o 
	./cc-slib error error.o error_str.o 
error.o:\
	cc-compile error.c error.h 
	./cc-compile error.c
error_str.o:\
	cc-compile error_str.c error.h 
	./cc-compile error_str.c
fd.a:\
	cc-slib fd.sld fd_dup.o fd_move.o fd_reset.o 
	./cc-slib fd fd_dup.o fd_move.o fd_reset.o 
fd_dup.o:\
	cc-compile fd_dup.c close.h fd.h 
	./cc-compile fd_dup.c
fd_move.o:\
	cc-compile fd_move.c close.h fd.h 
	./cc-compile fd_move.c
fd_reset.o:\
	cc-compile fd_reset.c fd.h 
	./cc-compile fd_reset.c
float32.a:\
	cc-slib float32.sld float32_pack.o float32_upack.o 
	./cc-slib float32 float32_pack.o float32_upack.o 
float32_pack.o:\
	cc-compile float32_pack.c byteorder.h float32.h 
	./cc-compile float32_pack.c
float32_upack.o:\
	cc-compile float32_upack.c byteorder.h float32.h 
	./cc-compile float32_upack.c
float64.a:\
	cc-slib float64.sld float64_pack.o float64_upack.o 
	./cc-slib float64 float64_pack.o float64_upack.o 
float64_pack.o:\
	cc-compile float64_pack.c byteorder.h float64.h 
	./cc-compile float64_pack.c
float64_upack.o:\
	cc-compile float64_upack.c byteorder.h float64.h 
	./cc-compile float64_upack.c
fmt.a:\
	cc-slib fmt.sld fmt_nstr.o fmt_str.o fmt_uchar.o fmt_ucharb.o \
	fmt_ucharo.o fmt_ucharx.o fmt_uint.o fmt_uintb.o fmt_uinto.o \
	fmt_uintx.o fmt_ullong.o fmt_ullongo.o fmt_ullongx.o fmt_ulong.o \
	fmt_ulongb.o fmt_ulongo.o fmt_ulongx.o fmt_ushort.o fmt_ushortb.o \
	fmt_ushorto.o fmt_ushortx.o 
	./cc-slib fmt fmt_nstr.o fmt_str.o fmt_uchar.o fmt_ucharb.o \
	fmt_ucharo.o fmt_ucharx.o fmt_uint.o fmt_uintb.o fmt_uinto.o \
	fmt_uintx.o fmt_ullong.o fmt_ullongo.o fmt_ullongx.o fmt_ulong.o \
	fmt_ulongb.o fmt_ulongo.o fmt_ulongx.o fmt_ushort.o fmt_ushortb.o \
	fmt_ushorto.o fmt_ushortx.o 
fmt_nstr.o:\
	cc-compile fmt_nstr.c fmt.h 
	./cc-compile fmt_nstr.c
fmt_spec.a:\
	cc-slib fmt_spec.sld fmt_u32.o fmt_u32b.o fmt_u32o.o fmt_u32x.o \
	fmt_u64.o fmt_u64b.o fmt_u64o.o fmt_u64x.o 
	./cc-slib fmt_spec fmt_u32.o fmt_u32b.o fmt_u32o.o fmt_u32x.o \
	fmt_u64.o fmt_u64b.o fmt_u64o.o fmt_u64x.o 
fmt_str.o:\
	cc-compile fmt_str.c fmt.h 
	./cc-compile fmt_str.c
fmt_u32.o:\
	cc-compile fmt_u32.c fmt_spec.h uint32.h uint64.h 
	./cc-compile fmt_u32.c
fmt_u32b.o:\
	cc-compile fmt_u32b.c fmt_spec.h uint32.h uint64.h 
	./cc-compile fmt_u32b.c
fmt_u32o.o:\
	cc-compile fmt_u32o.c fmt_spec.h uint32.h uint64.h 
	./cc-compile fmt_u32o.c
fmt_u32x.o:\
	cc-compile fmt_u32x.c fmt_spec.h uint32.h uint64.h 
	./cc-compile fmt_u32x.c
fmt_u64.o:\
	cc-compile fmt_u64.c fmt_spec.h uint64.h 
	./cc-compile fmt_u64.c
fmt_u64b.o:\
	cc-compile fmt_u64b.c fmt_spec.h uint64.h 
	./cc-compile fmt_u64b.c
fmt_u64o.o:\
	cc-compile fmt_u64o.c fmt_spec.h uint64.h 
	./cc-compile fmt_u64o.c
fmt_u64x.o:\
	cc-compile fmt_u64x.c fmt_spec.h uint64.h 
	./cc-compile fmt_u64x.c
fmt_uchar.o:\
	cc-compile fmt_uchar.c fmt.h 
	./cc-compile fmt_uchar.c
fmt_ucharb.o:\
	cc-compile fmt_ucharb.c fmt.h 
	./cc-compile fmt_ucharb.c
fmt_ucharo.o:\
	cc-compile fmt_ucharo.c fmt.h 
	./cc-compile fmt_ucharo.c
fmt_ucharx.o:\
	cc-compile fmt_ucharx.c fmt.h 
	./cc-compile fmt_ucharx.c
fmt_uint.o:\
	cc-compile fmt_uint.c fmt.h 
	./cc-compile fmt_uint.c
fmt_uintb.o:\
	cc-compile fmt_uintb.c fmt.h 
	./cc-compile fmt_uintb.c
fmt_uinto.o:\
	cc-compile fmt_uinto.c fmt.h 
	./cc-compile fmt_uinto.c
fmt_uintx.o:\
	cc-compile fmt_uintx.c fmt.h 
	./cc-compile fmt_uintx.c
fmt_ullong.o:\
	cc-compile fmt_ullong.c fmt.h 
	./cc-compile fmt_ullong.c
fmt_ullongo.o:\
	cc-compile fmt_ullongo.c fmt.h 
	./cc-compile fmt_ullongo.c
fmt_ullongx.o:\
	cc-compile fmt_ullongx.c fmt.h 
	./cc-compile fmt_ullongx.c
fmt_ulong.o:\
	cc-compile fmt_ulong.c fmt.h 
	./cc-compile fmt_ulong.c
fmt_ulongb.o:\
	cc-compile fmt_ulongb.c fmt.h 
	./cc-compile fmt_ulongb.c
fmt_ulongo.o:\
	cc-compile fmt_ulongo.c fmt.h 
	./cc-compile fmt_ulongo.c
fmt_ulongx.o:\
	cc-compile fmt_ulongx.c fmt.h 
	./cc-compile fmt_ulongx.c
fmt_ushort.o:\
	cc-compile fmt_ushort.c fmt.h 
	./cc-compile fmt_ushort.c
fmt_ushortb.o:\
	cc-compile fmt_ushortb.c fmt.h 
	./cc-compile fmt_ushortb.c
fmt_ushorto.o:\
	cc-compile fmt_ushorto.c fmt.h 
	./cc-compile fmt_ushorto.c
fmt_ushortx.o:\
	cc-compile fmt_ushortx.c fmt.h 
	./cc-compile fmt_ushortx.c
get_opt.a:\
	cc-slib get_opt.sld get_opt.o 
	./cc-slib get_opt get_opt.o 
get_opt.o:\
	cc-compile get_opt.c buffer.h get_opt.h 
	./cc-compile get_opt.c
hashtable.a:\
	cc-slib hashtable.sld ht_init.o ht_hash.o ht_free.o ht_addb.o \
	ht_adds.o ht_deleteb.o ht_deletes.o ht_getb.o ht_gets.o \
	ht_replaceb.o ht_replaces.o ht_bytes.o 
	./cc-slib hashtable ht_init.o ht_hash.o ht_free.o ht_addb.o \
	ht_adds.o ht_deleteb.o ht_deletes.o ht_getb.o ht_gets.o \
	ht_replaceb.o ht_replaces.o ht_bytes.o 
ht_addb.o:\
	cc-compile ht_addb.c alloc.h bin.h error.h hashtable.h 
	./cc-compile ht_addb.c
ht_adds.o:\
	cc-compile ht_adds.c hashtable.h str.h 
	./cc-compile ht_adds.c
ht_bytes.o:\
	cc-compile ht_bytes.c hashtable.h 
	./cc-compile ht_bytes.c
ht_deleteb.o:\
	cc-compile ht_deleteb.c alloc.h bin.h hashtable.h 
	./cc-compile ht_deleteb.c
ht_deletes.o:\
	cc-compile ht_deletes.c hashtable.h str.h 
	./cc-compile ht_deletes.c
ht_free.o:\
	cc-compile ht_free.c alloc.h hashtable.h 
	./cc-compile ht_free.c
ht_getb.o:\
	cc-compile ht_getb.c bin.h hashtable.h 
	./cc-compile ht_getb.c
ht_gets.o:\
	cc-compile ht_gets.c hashtable.h str.h 
	./cc-compile ht_gets.c
ht_hash.o:\
	cc-compile ht_hash.c hashtable.h 
	./cc-compile ht_hash.c
ht_init.o:\
	cc-compile ht_init.c bin.h hashtable.h 
	./cc-compile ht_init.c
ht_replaceb.o:\
	cc-compile ht_replaceb.c alloc.h bin.h hashtable.h 
	./cc-compile ht_replaceb.c
ht_replaces.o:\
	cc-compile ht_replaces.c hashtable.h str.h 
	./cc-compile ht_replaces.c
iarray.a:\
	cc-slib iarray.sld iarray_bytes.o iarray_cat.o iarray_chop.o \
	iarray_copy.o iarray_free.o iarray_index.o iarray_init.o \
	iarray_insert.o iarray_node.o iarray_remove.o iarray_size.o \
	iarray_trunc.o iarray_zero.o 
	./cc-slib iarray iarray_bytes.o iarray_cat.o iarray_chop.o \
	iarray_copy.o iarray_free.o iarray_index.o iarray_init.o \
	iarray_insert.o iarray_node.o iarray_remove.o iarray_size.o \
	iarray_trunc.o iarray_zero.o 
iarray_bytes.o:\
	cc-compile iarray_bytes.c iarray.h 
	./cc-compile iarray_bytes.c
iarray_cat.o:\
	cc-compile iarray_cat.c alloc.h iarray.h 
	./cc-compile iarray_cat.c
iarray_chop.o:\
	cc-compile iarray_chop.c alloc.h iarray.h 
	./cc-compile iarray_chop.c
iarray_copy.o:\
	cc-compile iarray_copy.c alloc.h iarray.h 
	./cc-compile iarray_copy.c
iarray_free.o:\
	cc-compile iarray_free.c alloc.h iarray.h 
	./cc-compile iarray_free.c
iarray_index.o:\
	cc-compile iarray_index.c iarray.h 
	./cc-compile iarray_index.c
iarray_init.o:\
	cc-compile iarray_init.c alloc.h iarray.h 
	./cc-compile iarray_init.c
iarray_insert.o:\
	cc-compile iarray_insert.c alloc.h iarray.h 
	./cc-compile iarray_insert.c
iarray_node.o:\
	cc-compile iarray_node.c alloc.h bin.h iarray.h 
	./cc-compile iarray_node.c
iarray_remove.o:\
	cc-compile iarray_remove.c alloc.h iarray.h 
	./cc-compile iarray_remove.c
iarray_size.o:\
	cc-compile iarray_size.c iarray.h 
	./cc-compile iarray_size.c
iarray_trunc.o:\
	cc-compile iarray_trunc.c iarray.h 
	./cc-compile iarray_trunc.c
iarray_zero.o:\
	cc-compile iarray_zero.c iarray.h 
	./cc-compile iarray_zero.c
inst-check:\
	cc-link inst-check.ld inst-check.o install_error.o 
	./cc-link inst-check inst-check.o install_error.o 
inst-check.o:\
	cc-compile inst-check.c install.h 
	./cc-compile inst-check.c
inst-copy:\
	cc-link inst-copy.ld inst-copy.o install_error.o 
	./cc-link inst-copy inst-copy.o install_error.o 
inst-copy.o:\
	cc-compile inst-copy.c install.h 
	./cc-compile inst-copy.c
inst-dir:\
	cc-link inst-dir.ld inst-dir.o install_error.o 
	./cc-link inst-dir inst-dir.o install_error.o 
inst-dir.o:\
	cc-compile inst-dir.c install.h 
	./cc-compile inst-dir.c
inst-link:\
	cc-link inst-link.ld inst-link.o install_error.o 
	./cc-link inst-link inst-link.o install_error.o 
inst-link.o:\
	cc-compile inst-link.c install.h 
	./cc-compile inst-link.c
install_core.o:\
	cc-compile install_core.c install.h 
	./cc-compile install_core.c
install_error.o:\
	cc-compile install_error.c install.h 
	./cc-compile install_error.c
installer:\
	cc-link installer.ld installer.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
	./cc-link installer installer.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
installer.o:\
	cc-compile installer.c install.h 
	./cc-compile installer.c
instchk:\
	cc-link instchk.ld instchk.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
	./cc-link instchk instchk.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 
instchk.o:\
	cc-compile instchk.c install.h 
	./cc-compile instchk.c
insthier.o:\
	cc-compile insthier.c install.h ctxt.h 
	./cc-compile insthier.c
int16.a:\
	cc-slib int16.sld int16_pack.o int16_unpack.o 
	./cc-slib int16 int16_pack.o int16_unpack.o 
int16_pack.o:\
	cc-compile int16_pack.c int16.h 
	./cc-compile int16_pack.c
int16_unpack.o:\
	cc-compile int16_unpack.c int16.h 
	./cc-compile int16_unpack.c
int32.a:\
	cc-slib int32.sld int32_pack.o int32_unpack.o 
	./cc-slib int32 int32_pack.o int32_unpack.o 
int32_pack.o:\
	cc-compile int32_pack.c int32.h 
	./cc-compile int32_pack.c
int32_unpack.o:\
	cc-compile int32_unpack.c int32.h 
	./cc-compile int32_unpack.c
int64.a:\
	cc-slib int64.sld int64_pack.o int64_unpack.o 
	./cc-slib int64 int64_pack.o int64_unpack.o 
int64_pack.o:\
	cc-compile int64_pack.c int64.h 
	./cc-compile int64_pack.c
int64_unpack.o:\
	cc-compile int64_unpack.c int64.h 
	./cc-compile int64_unpack.c
mk-cctype: conf-cc conf-systype 
mk-ctxt.o:\
	cc-compile mk-ctxt.c
	./cc-compile mk-ctxt.c
mk-ctxt:\
	cc-link mk-ctxt.o mk-ctxt.ld
	./cc-link mk-ctxt mk-ctxt.o
mk-sosuffix: conf-systype 
mk-systype: conf-cc 
nonblock.a:\
	cc-slib nonblock.sld nonblock.o 
	./cc-slib nonblock nonblock.o 
nonblock.o:\
	cc-compile nonblock.c nonblock.h 
	./cc-compile nonblock.c
open.a:\
	cc-slib open.sld open_append.o open_creat.o open_excl.o open_ro.o \
	open_rw.o open_trunc.o open_wo.o 
	./cc-slib open open_append.o open_creat.o open_excl.o open_ro.o \
	open_rw.o open_trunc.o open_wo.o 
open_append.o:\
	cc-compile open_append.c open.h 
	./cc-compile open_append.c
open_creat.o:\
	cc-compile open_creat.c open.h 
	./cc-compile open_creat.c
open_excl.o:\
	cc-compile open_excl.c open.h 
	./cc-compile open_excl.c
open_ro.o:\
	cc-compile open_ro.c open.h 
	./cc-compile open_ro.c
open_rw.o:\
	cc-compile open_rw.c open.h 
	./cc-compile open_rw.c
open_trunc.o:\
	cc-compile open_trunc.c open.h 
	./cc-compile open_trunc.c
open_wo.o:\
	cc-compile open_wo.c open.h 
	./cc-compile open_wo.c
sarray.a:\
	cc-slib sarray.sld sarray_bytes.o sarray_cat.o sarray_chop.o \
	sarray_data.o sarray_index.o sarray_init.o sarray_size.o \
	sarray_trunc.o 
	./cc-slib sarray sarray_bytes.o sarray_cat.o sarray_chop.o \
	sarray_data.o sarray_index.o sarray_init.o sarray_size.o \
	sarray_trunc.o 
sarray_bytes.o:\
	cc-compile sarray_bytes.c sarray.h 
	./cc-compile sarray_bytes.c
sarray_cat.o:\
	cc-compile sarray_cat.c sarray.h 
	./cc-compile sarray_cat.c
sarray_chop.o:\
	cc-compile sarray_chop.c sarray.h 
	./cc-compile sarray_chop.c
sarray_data.o:\
	cc-compile sarray_data.c sarray.h 
	./cc-compile sarray_data.c
sarray_index.o:\
	cc-compile sarray_index.c sarray.h 
	./cc-compile sarray_index.c
sarray_init.o:\
	cc-compile sarray_init.c sarray.h 
	./cc-compile sarray_init.c
sarray_size.o:\
	cc-compile sarray_size.c sarray.h 
	./cc-compile sarray_size.c
sarray_trunc.o:\
	cc-compile sarray_trunc.c sarray.h 
	./cc-compile sarray_trunc.c
scan.a:\
	cc-slib scan.sld scan_charset.o scan_double.o scan_float.o \
	scan_ncharset.o scan_newline.o scan_space.o scan_uchar.o \
	scan_ucharo.o scan_ucharx.o scan_uint.o scan_uinto.o scan_uintx.o \
	scan_ullong.o scan_ullongo.o scan_ullongx.o scan_ulong.o \
	scan_ulongo.o scan_ulongx.o scan_ushort.o scan_ushorto.o \
	scan_ushortx.o 
	./cc-slib scan scan_charset.o scan_double.o scan_float.o \
	scan_ncharset.o scan_newline.o scan_space.o scan_uchar.o \
	scan_ucharo.o scan_ucharx.o scan_uint.o scan_uinto.o scan_uintx.o \
	scan_ullong.o scan_ullongo.o scan_ullongx.o scan_ulong.o \
	scan_ulongo.o scan_ulongx.o scan_ushort.o scan_ushorto.o \
	scan_ushortx.o 
scan_charset.o:\
	cc-compile scan_charset.c scan.h 
	./cc-compile scan_charset.c
scan_double.o:\
	cc-compile scan_double.c scan.h 
	./cc-compile scan_double.c
scan_f32.o:\
	cc-compile scan_f32.c scan_fspec.h 
	./cc-compile scan_f32.c
scan_f64.o:\
	cc-compile scan_f64.c scan_fspec.h 
	./cc-compile scan_f64.c
scan_float.o:\
	cc-compile scan_float.c scan.h 
	./cc-compile scan_float.c
scan_fspec.a:\
	cc-slib scan_fspec.sld scan_f32.o scan_f64.o 
	./cc-slib scan_fspec scan_f32.o scan_f64.o 
scan_ncharset.o:\
	cc-compile scan_ncharset.c scan.h 
	./cc-compile scan_ncharset.c
scan_newline.o:\
	cc-compile scan_newline.c scan.h 
	./cc-compile scan_newline.c
scan_space.o:\
	cc-compile scan_space.c scan.h 
	./cc-compile scan_space.c
scan_spec.a:\
	cc-slib scan_spec.sld scan_u32.o scan_u32o.o scan_u32x.o scan_u64.o \
	scan_u64o.o scan_u64x.o 
	./cc-slib scan_spec scan_u32.o scan_u32o.o scan_u32x.o scan_u64.o \
	scan_u64o.o scan_u64x.o 
scan_u32.o:\
	cc-compile scan_u32.c scan_spec.h uint32.h uint64.h 
	./cc-compile scan_u32.c
scan_u32o.o:\
	cc-compile scan_u32o.c scan_spec.h uint32.h uint64.h 
	./cc-compile scan_u32o.c
scan_u32x.o:\
	cc-compile scan_u32x.c scan_spec.h uint32.h uint64.h 
	./cc-compile scan_u32x.c
scan_u64.o:\
	cc-compile scan_u64.c scan_spec.h uint64.h 
	./cc-compile scan_u64.c
scan_u64o.o:\
	cc-compile scan_u64o.c scan_spec.h uint64.h 
	./cc-compile scan_u64o.c
scan_u64x.o:\
	cc-compile scan_u64x.c scan_spec.h uint64.h 
	./cc-compile scan_u64x.c
scan_uchar.o:\
	cc-compile scan_uchar.c scan.h 
	./cc-compile scan_uchar.c
scan_ucharo.o:\
	cc-compile scan_ucharo.c scan.h 
	./cc-compile scan_ucharo.c
scan_ucharx.o:\
	cc-compile scan_ucharx.c scan.h 
	./cc-compile scan_ucharx.c
scan_uint.o:\
	cc-compile scan_uint.c scan.h 
	./cc-compile scan_uint.c
scan_uinto.o:\
	cc-compile scan_uinto.c scan.h 
	./cc-compile scan_uinto.c
scan_uintx.o:\
	cc-compile scan_uintx.c scan.h 
	./cc-compile scan_uintx.c
scan_ullong.o:\
	cc-compile scan_ullong.c scan.h 
	./cc-compile scan_ullong.c
scan_ullongo.o:\
	cc-compile scan_ullongo.c scan.h 
	./cc-compile scan_ullongo.c
scan_ullongx.o:\
	cc-compile scan_ullongx.c scan.h 
	./cc-compile scan_ullongx.c
scan_ulong.o:\
	cc-compile scan_ulong.c scan.h 
	./cc-compile scan_ulong.c
scan_ulongo.o:\
	cc-compile scan_ulongo.c scan.h 
	./cc-compile scan_ulongo.c
scan_ulongx.o:\
	cc-compile scan_ulongx.c scan.h 
	./cc-compile scan_ulongx.c
scan_ushort.o:\
	cc-compile scan_ushort.c scan.h 
	./cc-compile scan_ushort.c
scan_ushorto.o:\
	cc-compile scan_ushorto.c scan.h 
	./cc-compile scan_ushorto.c
scan_ushortx.o:\
	cc-compile scan_ushortx.c scan.h 
	./cc-compile scan_ushortx.c
seek.a:\
	cc-slib seek.sld seek_cur.o seek_end.o seek_pos.o seek_start.o 
	./cc-slib seek seek_cur.o seek_end.o seek_pos.o seek_start.o 
seek_cur.o:\
	cc-compile seek_cur.c int64.h seek.h 
	./cc-compile seek_cur.c
seek_end.o:\
	cc-compile seek_end.c int64.h seek.h 
	./cc-compile seek_end.c
seek_pos.o:\
	cc-compile seek_pos.c int64.h seek.h 
	./cc-compile seek_pos.c
seek_start.o:\
	cc-compile seek_start.c int64.h seek.h 
	./cc-compile seek_start.c
sgetline.a:\
	cc-slib sgetline.sld sgetline.o sgetline_chop.o sgetline_get.o 
	./cc-slib sgetline sgetline.o sgetline_chop.o sgetline_get.o 
sgetline.o:\
	cc-compile sgetline.c sgetline.h 
	./cc-compile sgetline.c
sgetline_chop.o:\
	cc-compile sgetline_chop.c sgetline.h 
	./cc-compile sgetline_chop.c
sgetline_get.o:\
	cc-compile sgetline_get.c bin.h buffer.h sgetline.h sstring.h 
	./cc-compile sgetline_get.c
sig.a:\
	cc-slib sig.sld sig.o sig_block.o sig_catch.o sig_pause.o 
	./cc-slib sig sig.o sig_block.o sig_catch.o sig_pause.o 
sig.o:\
	cc-compile sig.c sig.h 
	./cc-compile sig.c
sig_block.o:\
	cc-compile sig_block.c sig.h sig_pmask.h 
	./cc-compile sig_block.c
sig_catch.o:\
	cc-compile sig_catch.c sig.h sig_action.h 
	./cc-compile sig_catch.c
sig_pause.o:\
	cc-compile sig_pause.c sig.h sig_pmask.h 
	./cc-compile sig_pause.c
squeue.a:\
	cc-slib squeue.sld squeue_bytes.o squeue_data.o squeue_deq.o \
	squeue_enq.o squeue_init.o squeue_peek.o squeue_size.o 
	./cc-slib squeue squeue_bytes.o squeue_data.o squeue_deq.o \
	squeue_enq.o squeue_init.o squeue_peek.o squeue_size.o 
squeue_bytes.o:\
	cc-compile squeue_bytes.c squeue.h 
	./cc-compile squeue_bytes.c
squeue_data.o:\
	cc-compile squeue_data.c squeue.h 
	./cc-compile squeue_data.c
squeue_deq.o:\
	cc-compile squeue_deq.c squeue.h 
	./cc-compile squeue_deq.c
squeue_enq.o:\
	cc-compile squeue_enq.c squeue.h 
	./cc-compile squeue_enq.c
squeue_init.o:\
	cc-compile squeue_init.c squeue.h 
	./cc-compile squeue_init.c
squeue_peek.o:\
	cc-compile squeue_peek.c squeue.h 
	./cc-compile squeue_peek.c
squeue_size.o:\
	cc-compile squeue_size.c squeue.h 
	./cc-compile squeue_size.c
sstack.a:\
	cc-slib sstack.sld sstack_bytes.o sstack_data.o sstack_init.o \
	sstack_peek.o sstack_pop.o sstack_push.o sstack_size.o 
	./cc-slib sstack sstack_bytes.o sstack_data.o sstack_init.o \
	sstack_peek.o sstack_pop.o sstack_push.o sstack_size.o 
sstack_bytes.o:\
	cc-compile sstack_bytes.c sstack.h 
	./cc-compile sstack_bytes.c
sstack_data.o:\
	cc-compile sstack_data.c sstack.h 
	./cc-compile sstack_data.c
sstack_init.o:\
	cc-compile sstack_init.c sstack.h 
	./cc-compile sstack_init.c
sstack_peek.o:\
	cc-compile sstack_peek.c sstack.h 
	./cc-compile sstack_peek.c
sstack_pop.o:\
	cc-compile sstack_pop.c sstack.h 
	./cc-compile sstack_pop.c
sstack_push.o:\
	cc-compile sstack_push.c sstack.h 
	./cc-compile sstack_push.c
sstack_size.o:\
	cc-compile sstack_size.c sstack.h 
	./cc-compile sstack_size.c
sstring.a:\
	cc-slib sstring.sld sstring_0.o sstring_cat.o sstring_catb.o \
	sstring_cats.o sstring_copy.o sstring_cpyb.o sstring_cpys.o \
	sstring_init.o sstring_chop.o 
	./cc-slib sstring sstring_0.o sstring_cat.o sstring_catb.o \
	sstring_cats.o sstring_copy.o sstring_cpyb.o sstring_cpys.o \
	sstring_init.o sstring_chop.o 
sstring_0.o:\
	cc-compile sstring_0.c sstring.h 
	./cc-compile sstring_0.c
sstring_cat.o:\
	cc-compile sstring_cat.c sstring.h 
	./cc-compile sstring_cat.c
sstring_catb.o:\
	cc-compile sstring_catb.c sstring.h 
	./cc-compile sstring_catb.c
sstring_cats.o:\
	cc-compile sstring_cats.c sstring.h 
	./cc-compile sstring_cats.c
sstring_chop.o:\
	cc-compile sstring_chop.c sstring.h 
	./cc-compile sstring_chop.c
sstring_copy.o:\
	cc-compile sstring_copy.c sstring.h 
	./cc-compile sstring_copy.c
sstring_cpyb.o:\
	cc-compile sstring_cpyb.c sstring.h 
	./cc-compile sstring_cpyb.c
sstring_cpys.o:\
	cc-compile sstring_cpys.c sstring.h 
	./cc-compile sstring_cpys.c
sstring_init.o:\
	cc-compile sstring_init.c sstring.h 
	./cc-compile sstring_init.c
stalloc.a:\
	cc-slib stalloc.sld stalloc.o 
	./cc-slib stalloc stalloc.o 
stalloc.o:\
	cc-compile stalloc.c error.h stalloc.h 
	./cc-compile stalloc.c
str.a:\
	cc-slib str.sld str_char.o str_chr.o str_ci_diff.o str_ci_ndiff.o \
	str_diff.o str_dup.o str_ends.o str_len.o str_ndiff.o str_rchar.o \
	str_rchr.o str_starts.o str_tolower.o str_toupper.o 
	./cc-slib str str_char.o str_chr.o str_ci_diff.o str_ci_ndiff.o \
	str_diff.o str_dup.o str_ends.o str_len.o str_ndiff.o str_rchar.o \
	str_rchr.o str_starts.o str_tolower.o str_toupper.o 
str_char.o:\
	cc-compile str_char.c str.h 
	./cc-compile str_char.c
str_chr.o:\
	cc-compile str_chr.c str.h 
	./cc-compile str_chr.c
str_ci_diff.o:\
	cc-compile str_ci_diff.c str.h 
	./cc-compile str_ci_diff.c
str_ci_ndiff.o:\
	cc-compile str_ci_ndiff.c str.h 
	./cc-compile str_ci_ndiff.c
str_diff.o:\
	cc-compile str_diff.c str.h 
	./cc-compile str_diff.c
str_dup.o:\
	cc-compile str_dup.c alloc.h bin.h str.h 
	./cc-compile str_dup.c
str_ends.o:\
	cc-compile str_ends.c str.h 
	./cc-compile str_ends.c
str_len.o:\
	cc-compile str_len.c str.h 
	./cc-compile str_len.c
str_ndiff.o:\
	cc-compile str_ndiff.c str.h 
	./cc-compile str_ndiff.c
str_rchar.o:\
	cc-compile str_rchar.c str.h 
	./cc-compile str_rchar.c
str_rchr.o:\
	cc-compile str_rchr.c str.h 
	./cc-compile str_rchr.c
str_starts.o:\
	cc-compile str_starts.c str.h 
	./cc-compile str_starts.c
str_tolower.o:\
	cc-compile str_tolower.c str.h 
	./cc-compile str_tolower.c
str_toupper.o:\
	cc-compile str_toupper.c str.h 
	./cc-compile str_toupper.c
syserr.a:\
	cc-slib syserr.sld syserr_die.o syserr_init.o 
	./cc-slib syserr syserr_die.o syserr_init.o 
syserr_die.o:\
	cc-compile syserr_die.c buffer.h exit.h syserr.h 
	./cc-compile syserr_die.c
syserr_init.o:\
	cc-compile syserr_init.c error.h syserr.h 
	./cc-compile syserr_init.c
uint16.a:\
	cc-slib uint16.sld uint16_pack.o uint16_unpack.o 
	./cc-slib uint16 uint16_pack.o uint16_unpack.o 
uint16_pack.o:\
	cc-compile uint16_pack.c uint16.h 
	./cc-compile uint16_pack.c
uint16_unpack.o:\
	cc-compile uint16_unpack.c uint16.h 
	./cc-compile uint16_unpack.c
uint32.a:\
	cc-slib uint32.sld uint32_pack.o uint32_unpack.o 
	./cc-slib uint32 uint32_pack.o uint32_unpack.o 
uint32_pack.o:\
	cc-compile uint32_pack.c uint32.h 
	./cc-compile uint32_pack.c
uint32_unpack.o:\
	cc-compile uint32_unpack.c uint32.h 
	./cc-compile uint32_unpack.c
uint64.a:\
	cc-slib uint64.sld uint64_pack.o uint64_unpack.o 
	./cc-slib uint64 uint64_pack.o uint64_unpack.o 
uint64_pack.o:\
	cc-compile uint64_pack.c uint64.h 
	./cc-compile uint64_pack.c
uint64_unpack.o:\
	cc-compile uint64_unpack.c uint64.h 
	./cc-compile uint64_unpack.c
clean: sysdeps_clean tests_clean 
	rm -f alloc.a alloc.o array.a array.o array_bytes.o array_cat.o \
	array_chop.o array_copy.o array_data.o array_index.o array_size.o \
	array_trunc.o array_zero.o base_name.a base_name.o bin.a bin_char.o \
	bin_chr.o bin_copy.o bin_copyr.o bin_count.o bin_diff.o bin_rchar.o \
	bin_rchr.o bin_set.o bin_tolower.o bin_toupper.o bin_zero.o buffer.a \
	buffer0.o buffer1.o buffer2.o buffer_copy.o buffer_get.o \
	buffer_init.o buffer_put.o closeonexec.a closeonexec.o conf-cctype \
	conf-systype corelib-conf corelib-conf.o ctxt/bindir.c ctxt/bindir.o \
	ctxt/ctxt.a ctxt/dlibdir.c ctxt/dlibdir.o ctxt/incdir.c \
	ctxt/incdir.o ctxt/repos.c ctxt/repos.o ctxt/slibdir.c \
	ctxt/slibdir.o ctxt/version.c ctxt/version.o deinstaller \
	deinstaller.o dir_array.a dir_array.o dir_hash.a dir_hash.o \
	dir_name.a dir_name.o dstring.a 
	rm -f dstring_0.o dstring_cat.o dstring_cat0.o dstring_catb.o \
	dstring_cats.o dstring_chop.o dstring_copy.o dstring_cpyb.o \
	dstring_cpys.o dstring_init.o dstring_trunc.o env.a env.o env_get.o \
	error.a error.o error_str.o fd.a fd_dup.o fd_move.o fd_reset.o \
	float32.a float32_pack.o float32_upack.o float64.a float64_pack.o \
	float64_upack.o fmt.a fmt_nstr.o fmt_spec.a fmt_str.o fmt_u32.o \
	fmt_u32b.o fmt_u32o.o fmt_u32x.o fmt_u64.o fmt_u64b.o fmt_u64o.o \
	fmt_u64x.o fmt_uchar.o fmt_ucharb.o fmt_ucharo.o fmt_ucharx.o \
	fmt_uint.o fmt_uintb.o fmt_uinto.o fmt_uintx.o fmt_ullong.o \
	fmt_ullongo.o fmt_ullongx.o fmt_ulong.o fmt_ulongb.o fmt_ulongo.o \
	fmt_ulongx.o fmt_ushort.o fmt_ushortb.o fmt_ushorto.o fmt_ushortx.o \
	get_opt.a get_opt.o hashtable.a ht_addb.o ht_adds.o ht_bytes.o 
	rm -f ht_deleteb.o ht_deletes.o ht_free.o ht_getb.o ht_gets.o \
	ht_hash.o ht_init.o ht_replaceb.o ht_replaces.o iarray.a \
	iarray_bytes.o iarray_cat.o iarray_chop.o iarray_copy.o \
	iarray_free.o iarray_index.o iarray_init.o iarray_insert.o \
	iarray_node.o iarray_remove.o iarray_size.o iarray_trunc.o \
	iarray_zero.o inst-check inst-check.o inst-copy inst-copy.o inst-dir \
	inst-dir.o inst-link inst-link.o install_core.o install_error.o \
	installer installer.o instchk instchk.o insthier.o int16.a \
	int16_pack.o int16_unpack.o int32.a int32_pack.o int32_unpack.o \
	int64.a int64_pack.o int64_unpack.o mk-ctxt mk-ctxt.o nonblock.a \
	nonblock.o open.a open_append.o open_creat.o open_excl.o open_ro.o \
	open_rw.o open_trunc.o open_wo.o sarray.a sarray_bytes.o \
	sarray_cat.o sarray_chop.o sarray_data.o 
	rm -f sarray_index.o sarray_init.o sarray_size.o sarray_trunc.o \
	scan.a scan_charset.o scan_double.o scan_f32.o scan_f64.o \
	scan_float.o scan_fspec.a scan_ncharset.o scan_newline.o \
	scan_space.o scan_spec.a scan_u32.o scan_u32o.o scan_u32x.o \
	scan_u64.o scan_u64o.o scan_u64x.o scan_uchar.o scan_ucharo.o \
	scan_ucharx.o scan_uint.o scan_uinto.o scan_uintx.o scan_ullong.o \
	scan_ullongo.o scan_ullongx.o scan_ulong.o scan_ulongo.o \
	scan_ulongx.o scan_ushort.o scan_ushorto.o scan_ushortx.o seek.a \
	seek_cur.o seek_end.o seek_pos.o seek_start.o sgetline.a sgetline.o \
	sgetline_chop.o sgetline_get.o sig.a sig.o sig_block.o sig_catch.o \
	sig_pause.o squeue.a squeue_bytes.o squeue_data.o squeue_deq.o \
	squeue_enq.o squeue_init.o squeue_peek.o squeue_size.o sstack.a \
	sstack_bytes.o sstack_data.o sstack_init.o sstack_peek.o \
	sstack_pop.o 
	rm -f sstack_push.o sstack_size.o sstring.a sstring_0.o \
	sstring_cat.o sstring_catb.o sstring_cats.o sstring_chop.o \
	sstring_copy.o sstring_cpyb.o sstring_cpys.o sstring_init.o \
	stalloc.a stalloc.o str.a str_char.o str_chr.o str_ci_diff.o \
	str_ci_ndiff.o str_diff.o str_dup.o str_ends.o str_len.o str_ndiff.o \
	str_rchar.o str_rchr.o str_starts.o str_tolower.o str_toupper.o \
	syserr.a syserr_die.o syserr_init.o uint16.a uint16_pack.o \
	uint16_unpack.o uint32.a uint32_pack.o uint32_unpack.o uint64.a \
	uint64_pack.o uint64_unpack.o 

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

