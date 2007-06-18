# auto generated - do not edit

default: all

all:\
alloc.a array.a base_name.a bin.a buffer.a closeonexec.a corelib-conf \
ctxt/ctxt.a deinstaller dgetline.a dir_array.a dir_hash.a dir_name.a \
dstring.a env.a error.a fd.a fd_seek.a fmt.a get_opt.a hashtable.a iarray.a \
inst-check inst-copy inst-dir inst-link installer instchk nonblock.a open.a \
rmkdir.a sarray.a scan.a sgetline.a sig.a squeue.a sstack.a sstring.a \
stalloc.a str.a syserr.a sysinfo uint.a 

# -- SYSDEPS start
_byteorder.h:
	@echo SYSDEPS byteorder run create _byteorder.h 
	@(cd SYSDEPS/modules/byteorder && ./run)
_direntry.h:
	@echo SYSDEPS direntry run create _direntry.h 
	@(cd SYSDEPS/modules/direntry && ./run)
_sd_fcntl.h:
	@echo SYSDEPS sd-fcntl run create libs-fcntl flags-fcntl _sd_fcntl.h 
	@(cd SYSDEPS/modules/sd-fcntl && ./run)
flags-fcntl: _sd_fcntl.h
libs-fcntl: _sd_fcntl.h
_sd_fd.h:
	@echo SYSDEPS sd-fd run create _sd_fd.h 
	@(cd SYSDEPS/modules/sd-fd && ./run)
_sd_inline.h:
	@echo SYSDEPS sd-inline run create _sd_inline.h 
	@(cd SYSDEPS/modules/sd-inline && ./run)
_sd_longlong.h:
	@echo SYSDEPS sd-longlong run create _sd_longlong.h 
	@(cd SYSDEPS/modules/sd-longlong && ./run)
libs-math:
	@echo SYSDEPS sd-math run create _sd_math.h flags-math libs-math 
	@(cd SYSDEPS/modules/sd-math && ./run)
flags-math: libs-math
_sd_math.h: libs-math
_sig_action.h:
	@echo SYSDEPS sd-signal run create _sig_pmask.h _sig_action.h 
	@(cd SYSDEPS/modules/sd-signal && ./run)
_sig_pmask.h: _sig_action.h
_sysinfo.h:
	@echo SYSDEPS sysinfo run create _sysinfo.h 
	@(cd SYSDEPS/modules/sysinfo && ./run)


byteorder_clean:
	@echo SYSDEPS byteorder clean _byteorder.h 
	@(cd SYSDEPS/modules/byteorder && ./clean)
direntry_clean:
	@echo SYSDEPS direntry clean _direntry.h 
	@(cd SYSDEPS/modules/direntry && ./clean)
sd-fcntl_clean:
	@echo SYSDEPS sd-fcntl clean libs-fcntl flags-fcntl _sd_fcntl.h 
	@(cd SYSDEPS/modules/sd-fcntl && ./clean)
sd-fd_clean:
	@echo SYSDEPS sd-fd clean _sd_fd.h 
	@(cd SYSDEPS/modules/sd-fd && ./clean)
sd-inline_clean:
	@echo SYSDEPS sd-inline clean _sd_inline.h 
	@(cd SYSDEPS/modules/sd-inline && ./clean)
sd-longlong_clean:
	@echo SYSDEPS sd-longlong clean _sd_longlong.h 
	@(cd SYSDEPS/modules/sd-longlong && ./clean)
sd-math_clean:
	@echo SYSDEPS sd-math clean _sd_math.h flags-math libs-math 
	@(cd SYSDEPS/modules/sd-math && ./clean)
sd-signal_clean:
	@echo SYSDEPS sd-signal clean _sig_pmask.h _sig_action.h 
	@(cd SYSDEPS/modules/sd-signal && ./clean)
sysinfo_clean:
	@echo SYSDEPS sysinfo clean _sysinfo.h 
	@(cd SYSDEPS/modules/sysinfo && ./clean)


sysdeps_clean:\
byteorder_clean \
direntry_clean \
sd-fcntl_clean \
sd-fd_clean \
sd-inline_clean \
sd-longlong_clean \
sd-math_clean \
sd-signal_clean \
sysinfo_clean \


# -- SYSDEPS end

alloc.a:\
cc-slib alloc.sld alloc.o 
	./cc-slib alloc alloc.o 

alloc.o:\
cc-compile alloc.c alloc.h 
	./cc-compile alloc.c

array.a:\
cc-slib array.sld array.o array_bytes.o array_cat.o array_chop.o \
array_copy.o array_data.o array_index.o array_size.o array_trunc.o \
array_zero.o 
	./cc-slib array array.o array_bytes.o array_cat.o array_chop.o \
	array_copy.o array_data.o array_index.o array_size.o array_trunc.o \
	array_zero.o 

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
cc-slib bin.sld bin_char.o bin_rchar.o bin_chr.o bin_copy.o bin_copyr.o \
bin_count.o bin_diff.o bin_rchr.o bin_set.o bin_tolower.o bin_toupper.o \
bin_zero.o 
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
cc-slib buffer.sld buffer0.o buffer1.o buffer2.o buffer_get.o buffer_init.o \
buffer_put.o buffer_copy.o 
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

byteorder.h:\
_byteorder.h 

cc-compile:\
conf-cc conf-cctype conf-systype conf-cflags flags-math 

cc-link:\
conf-ld conf-ldtype conf-systype conf-ldflags libs-math 

cc-slib:\
conf-systype 

closeonexec.a:\
cc-slib closeonexec.sld closeonexec.o 
	./cc-slib closeonexec closeonexec.o 

closeonexec.o:\
cc-compile closeonexec.c closeonexec.h 
	./cc-compile closeonexec.c

conf-cctype:\
conf-systype conf-cc mk-cctype 
	./mk-cctype > conf-cctype.tmp && mv conf-cctype.tmp conf-cctype

conf-ldtype:\
conf-systype conf-ld conf-cctype mk-ldtype 
	./mk-ldtype > conf-ldtype.tmp && mv conf-ldtype.tmp conf-ldtype

conf-sosuffix:\
mk-sosuffix 
	./mk-sosuffix > conf-sosuffix.tmp && mv conf-sosuffix.tmp \
	conf-sosuffix

conf-systype:\
mk-systype 
	./mk-systype > conf-systype.tmp && mv conf-systype.tmp conf-systype

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

dgetline.a:\
cc-slib dgetline.sld dgetline_chop.o dgetline_data.o dgetline_free.o \
dgetline_get.o dgetline_init.o dgetline_lnum.o dgetline_size.o 
	./cc-slib dgetline dgetline_chop.o dgetline_data.o dgetline_free.o \
	dgetline_get.o dgetline_init.o dgetline_lnum.o dgetline_size.o 

dgetline.h:\
buffer.h dstring.h 

dgetline_chop.o:\
cc-compile dgetline_chop.c dgetline.h 
	./cc-compile dgetline_chop.c

dgetline_data.o:\
cc-compile dgetline_data.c dgetline.h dstring.h 
	./cc-compile dgetline_data.c

dgetline_free.o:\
cc-compile dgetline_free.c dgetline.h dstring.h 
	./cc-compile dgetline_free.c

dgetline_get.o:\
cc-compile dgetline_get.c bin.h buffer.h dstring.h dgetline.h 
	./cc-compile dgetline_get.c

dgetline_init.o:\
cc-compile dgetline_init.c buffer.h dgetline.h dstring.h 
	./cc-compile dgetline_init.c

dgetline_lnum.o:\
cc-compile dgetline_lnum.c dgetline.h 
	./cc-compile dgetline_lnum.c

dgetline_size.o:\
cc-compile dgetline_size.c dgetline.h dstring.h 
	./cc-compile dgetline_size.c

dir_array.a:\
cc-slib dir_array.sld dir_array.o 
	./cc-slib dir_array dir_array.o 

dir_array.o:\
cc-compile dir_array.c alloc.h bin.h dir_array.h direntry.h str.h 
	./cc-compile dir_array.c

dir_hash.a:\
cc-slib dir_hash.sld dir_hash.o 
	./cc-slib dir_hash dir_hash.o 

dir_hash.h:\
dir_array.h 

dir_hash.o:\
cc-compile dir_hash.c alloc.h bin.h dir_array.h dir_hash.h str.h 
	./cc-compile dir_hash.c

dir_name.a:\
cc-slib dir_name.sld dir_name.o 
	./cc-slib dir_name dir_name.o 

dir_name.o:\
cc-compile dir_name.c bin.h dir_name.h str.h 
	./cc-compile dir_name.c

direntry.h:\
_direntry.h 

dstring.a:\
cc-slib dstring.sld dstring_0.o dstring_cat.o dstring_catb.o dstring_cats.o \
dstring_chop.o dstring_copy.o dstring_cpyb.o dstring_cpys.o dstring_data.o \
dstring_init.o dstring_size.o dstring_trunc.o 
	./cc-slib dstring dstring_0.o dstring_cat.o dstring_catb.o \
	dstring_cats.o dstring_chop.o dstring_copy.o dstring_cpyb.o \
	dstring_cpys.o dstring_data.o dstring_init.o dstring_size.o \
	dstring_trunc.o 

dstring_0.o:\
cc-compile dstring_0.c dstring.h 
	./cc-compile dstring_0.c

dstring_cat.o:\
cc-compile dstring_cat.c dstring.h 
	./cc-compile dstring_cat.c

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

dstring_data.o:\
cc-compile dstring_data.c dstring.h 
	./cc-compile dstring_data.c

dstring_init.o:\
cc-compile dstring_init.c alloc.h dstring.h 
	./cc-compile dstring_init.c

dstring_size.o:\
cc-compile dstring_size.c dstring.h 
	./cc-compile dstring_size.c

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
cc-compile fd_dup.c sd_fd.h sd_fcntl.h close.h fd.h 
	./cc-compile fd_dup.c

fd_move.o:\
cc-compile fd_move.c close.h fd.h 
	./cc-compile fd_move.c

fd_reset.o:\
cc-compile fd_reset.c fd.h sd_fcntl.h 
	./cc-compile fd_reset.c

fd_seek.a:\
cc-slib fd_seek.sld fd_seek_cur.o fd_seek_end.o fd_seek_pos.o \
fd_seek_start.o 
	./cc-slib fd_seek fd_seek_cur.o fd_seek_end.o fd_seek_pos.o \
	fd_seek_start.o 

fd_seek_cur.o:\
cc-compile fd_seek_cur.c fd_seek.h 
	./cc-compile fd_seek_cur.c

fd_seek_end.o:\
cc-compile fd_seek_end.c fd_seek.h 
	./cc-compile fd_seek_end.c

fd_seek_pos.o:\
cc-compile fd_seek_pos.c fd_seek.h 
	./cc-compile fd_seek_pos.c

fd_seek_start.o:\
cc-compile fd_seek_start.c fd_seek.h 
	./cc-compile fd_seek_start.c

fmt.a:\
cc-slib fmt.sld fmt_char.o fmt_charb.o fmt_charo.o fmt_charx.o fmt_double.o \
fmt_float.o fmt_int.o fmt_intb.o fmt_into.o fmt_intx.o fmt_llong.o \
fmt_llongb.o fmt_llongo.o fmt_llongx.o fmt_long.o fmt_longb.o fmt_longo.o \
fmt_longx.o fmt_nstr.o fmt_pad_c.o fmt_pad_i.o fmt_pad_l.o fmt_pad_ll.o \
fmt_pad_s.o fmt_short.o fmt_shortb.o fmt_shorto.o fmt_shortx.o fmt_str.o 
	./cc-slib fmt fmt_char.o fmt_charb.o fmt_charo.o fmt_charx.o \
	fmt_double.o fmt_float.o fmt_int.o fmt_intb.o fmt_into.o fmt_intx.o \
	fmt_llong.o fmt_llongb.o fmt_llongo.o fmt_llongx.o fmt_long.o \
	fmt_longb.o fmt_longo.o fmt_longx.o fmt_nstr.o fmt_pad_c.o \
	fmt_pad_i.o fmt_pad_l.o fmt_pad_ll.o fmt_pad_s.o fmt_short.o \
	fmt_shortb.o fmt_shorto.o fmt_shortx.o fmt_str.o 

fmt_char.o:\
cc-compile fmt_char.c fmt.h 
	./cc-compile fmt_char.c

fmt_charb.o:\
cc-compile fmt_charb.c fmt.h 
	./cc-compile fmt_charb.c

fmt_charo.o:\
cc-compile fmt_charo.c fmt.h 
	./cc-compile fmt_charo.c

fmt_charx.o:\
cc-compile fmt_charx.c fmt.h 
	./cc-compile fmt_charx.c

fmt_double.o:\
cc-compile fmt_double.c sd_math.h sd_inline.h sd_longlong.h fmt.h 
	./cc-compile fmt_double.c

fmt_float.o:\
cc-compile fmt_float.c fmt.h sd_math.h sd_inline.h 
	./cc-compile fmt_float.c

fmt_int.o:\
cc-compile fmt_int.c fmt.h 
	./cc-compile fmt_int.c

fmt_intb.o:\
cc-compile fmt_intb.c fmt.h 
	./cc-compile fmt_intb.c

fmt_into.o:\
cc-compile fmt_into.c fmt.h 
	./cc-compile fmt_into.c

fmt_intx.o:\
cc-compile fmt_intx.c fmt.h 
	./cc-compile fmt_intx.c

fmt_llong.o:\
cc-compile fmt_llong.c sd_longlong.h fmt.h 
	./cc-compile fmt_llong.c

fmt_llongb.o:\
cc-compile fmt_llongb.c sd_longlong.h fmt.h 
	./cc-compile fmt_llongb.c

fmt_llongo.o:\
cc-compile fmt_llongo.c sd_longlong.h fmt.h 
	./cc-compile fmt_llongo.c

fmt_llongx.o:\
cc-compile fmt_llongx.c sd_longlong.h fmt.h 
	./cc-compile fmt_llongx.c

fmt_long.o:\
cc-compile fmt_long.c fmt.h 
	./cc-compile fmt_long.c

fmt_longb.o:\
cc-compile fmt_longb.c fmt.h 
	./cc-compile fmt_longb.c

fmt_longo.o:\
cc-compile fmt_longo.c fmt.h 
	./cc-compile fmt_longo.c

fmt_longx.o:\
cc-compile fmt_longx.c fmt.h 
	./cc-compile fmt_longx.c

fmt_nstr.o:\
cc-compile fmt_nstr.c fmt.h 
	./cc-compile fmt_nstr.c

fmt_pad_c.o:\
cc-compile fmt_pad_c.c fmt.h fmt_pad.h 
	./cc-compile fmt_pad_c.c

fmt_pad_i.o:\
cc-compile fmt_pad_i.c fmt.h fmt_pad.h 
	./cc-compile fmt_pad_i.c

fmt_pad_l.o:\
cc-compile fmt_pad_l.c fmt.h fmt_pad.h 
	./cc-compile fmt_pad_l.c

fmt_pad_ll.o:\
cc-compile fmt_pad_ll.c sd_longlong.h fmt.h fmt_pad.h 
	./cc-compile fmt_pad_ll.c

fmt_pad_s.o:\
cc-compile fmt_pad_s.c fmt.h fmt_pad.h 
	./cc-compile fmt_pad_s.c

fmt_short.o:\
cc-compile fmt_short.c fmt.h 
	./cc-compile fmt_short.c

fmt_shortb.o:\
cc-compile fmt_shortb.c fmt.h 
	./cc-compile fmt_shortb.c

fmt_shorto.o:\
cc-compile fmt_shorto.c fmt.h 
	./cc-compile fmt_shorto.c

fmt_shortx.o:\
cc-compile fmt_shortx.c fmt.h 
	./cc-compile fmt_shortx.c

fmt_str.o:\
cc-compile fmt_str.c fmt.h 
	./cc-compile fmt_str.c

get_opt.a:\
cc-slib get_opt.sld get_opt.o 
	./cc-slib get_opt get_opt.o 

get_opt.o:\
cc-compile get_opt.c buffer.h get_opt.h 
	./cc-compile get_opt.c

hashtable.a:\
cc-slib hashtable.sld ht_addb.o ht_adds.o ht_bytes.o ht_checkb.o ht_checks.o \
ht_deleteb.o ht_deletes.o ht_free.o ht_getb.o ht_gets.o ht_hash.o ht_init.o \
ht_iter.o ht_replaceb.o ht_replaces.o 
	./cc-slib hashtable ht_addb.o ht_adds.o ht_bytes.o ht_checkb.o \
	ht_checks.o ht_deleteb.o ht_deletes.o ht_free.o ht_getb.o ht_gets.o \
	ht_hash.o ht_init.o ht_iter.o ht_replaceb.o ht_replaces.o 

ht_addb.o:\
cc-compile ht_addb.c alloc.h bin.h error.h hashtable.h 
	./cc-compile ht_addb.c

ht_adds.o:\
cc-compile ht_adds.c hashtable.h str.h 
	./cc-compile ht_adds.c

ht_bytes.o:\
cc-compile ht_bytes.c hashtable.h 
	./cc-compile ht_bytes.c

ht_checkb.o:\
cc-compile ht_checkb.c hashtable.h 
	./cc-compile ht_checkb.c

ht_checks.o:\
cc-compile ht_checks.c hashtable.h str.h 
	./cc-compile ht_checks.c

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

ht_iter.o:\
cc-compile ht_iter.c hashtable.h 
	./cc-compile ht_iter.c

ht_replaceb.o:\
cc-compile ht_replaceb.c alloc.h bin.h hashtable.h 
	./cc-compile ht_replaceb.c

ht_replaces.o:\
cc-compile ht_replaces.c hashtable.h str.h 
	./cc-compile ht_replaces.c

iarray.a:\
cc-slib iarray.sld iarray_bytes.o iarray_cat.o iarray_chop.o iarray_copy.o \
iarray_free.o iarray_index.o iarray_init.o iarray_insert.o iarray_node.o \
iarray_remove.o iarray_size.o iarray_sort.o iarray_trunc.o iarray_zero.o 
	./cc-slib iarray iarray_bytes.o iarray_cat.o iarray_chop.o \
	iarray_copy.o iarray_free.o iarray_index.o iarray_init.o \
	iarray_insert.o iarray_node.o iarray_remove.o iarray_size.o \
	iarray_sort.o iarray_trunc.o iarray_zero.o 

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

iarray_sort.o:\
cc-compile iarray_sort.c iarray.h 
	./cc-compile iarray_sort.c

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
cc-link installer.ld installer.o insthier.o install_core.o install_error.o \
ctxt/ctxt.a 
	./cc-link installer installer.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 

installer.o:\
cc-compile installer.c install.h 
	./cc-compile installer.c

instchk:\
cc-link instchk.ld instchk.o insthier.o install_core.o install_error.o \
ctxt/ctxt.a 
	./cc-link instchk instchk.o insthier.o install_core.o \
	install_error.o ctxt/ctxt.a 

instchk.o:\
cc-compile instchk.c install.h 
	./cc-compile instchk.c

insthier.o:\
cc-compile insthier.c install.h ctxt.h 
	./cc-compile insthier.c

mk-cctype:\
conf-cc conf-systype 

mk-ctxt:\
mk-mk-ctxt 
	./mk-mk-ctxt

mk-ldtype:\
conf-cctype conf-systype 

mk-mk-ctxt:\
conf-cc 

mk-sosuffix:\
conf-systype 

mk-systype:\
conf-cc 

nonblock.a:\
cc-slib nonblock.sld nonblock.o 
	./cc-slib nonblock nonblock.o 

nonblock.o:\
cc-compile nonblock.c nonblock.h 
	./cc-compile nonblock.c

open.a:\
cc-slib open.sld open_append.o open_creat.o open_excl.o open_ro.o open_rw.o \
open_trunc.o open_wo.o 
	./cc-slib open open_append.o open_creat.o open_excl.o open_ro.o \
	open_rw.o open_trunc.o open_wo.o 

open_append.o:\
cc-compile open_append.c sd_fcntl.h open.h 
	./cc-compile open_append.c

open_creat.o:\
cc-compile open_creat.c sd_fcntl.h open.h 
	./cc-compile open_creat.c

open_excl.o:\
cc-compile open_excl.c sd_fcntl.h open.h 
	./cc-compile open_excl.c

open_ro.o:\
cc-compile open_ro.c sd_fcntl.h open.h 
	./cc-compile open_ro.c

open_rw.o:\
cc-compile open_rw.c sd_fcntl.h open.h 
	./cc-compile open_rw.c

open_trunc.o:\
cc-compile open_trunc.c sd_fcntl.h open.h 
	./cc-compile open_trunc.c

open_wo.o:\
cc-compile open_wo.c sd_fcntl.h open.h 
	./cc-compile open_wo.c

rmkdir.a:\
cc-slib rmkdir.sld rmkdir.o 
	./cc-slib rmkdir rmkdir.o 

rmkdir.o:\
cc-compile rmkdir.c bin.h error.h rmkdir.h str.h 
	./cc-compile rmkdir.c

sarray.a:\
cc-slib sarray.sld sarray_bytes.o sarray_cat.o sarray_chop.o sarray_data.o \
sarray_index.o sarray_init.o sarray_size.o sarray_trunc.o 
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
cc-slib scan.sld scan_char.o scan_charb.o scan_charo.o scan_chars.o \
scan_charsn.o scan_charx.o scan_double.o scan_float.o scan_int.o scan_intb.o \
scan_into.o scan_intx.o scan_llong.o scan_llongb.o scan_llongo.o \
scan_llongx.o scan_long.o scan_longb.o scan_longb.o scan_longo.o \
scan_longx.o scan_nchars.o scan_ncharsn.o scan_newline.o scan_short.o \
scan_shortb.o scan_shorto.o scan_shortx.o scan_space.o 
	./cc-slib scan scan_char.o scan_charb.o scan_charo.o scan_chars.o \
	scan_charsn.o scan_charx.o scan_double.o scan_float.o scan_int.o \
	scan_intb.o scan_into.o scan_intx.o scan_llong.o scan_llongb.o \
	scan_llongo.o scan_llongx.o scan_long.o scan_longb.o scan_longb.o \
	scan_longo.o scan_longx.o scan_nchars.o scan_ncharsn.o \
	scan_newline.o scan_short.o scan_shortb.o scan_shorto.o \
	scan_shortx.o scan_space.o 

scan_char.o:\
cc-compile scan_char.c scan.h 
	./cc-compile scan_char.c

scan_charb.o:\
cc-compile scan_charb.c scan.h 
	./cc-compile scan_charb.c

scan_charo.o:\
cc-compile scan_charo.c scan.h 
	./cc-compile scan_charo.c

scan_chars.o:\
cc-compile scan_chars.c scan.h 
	./cc-compile scan_chars.c

scan_charsn.o:\
cc-compile scan_charsn.c scan.h 
	./cc-compile scan_charsn.c

scan_charx.o:\
cc-compile scan_charx.c scan.h 
	./cc-compile scan_charx.c

scan_double.o:\
cc-compile scan_double.c scan.h 
	./cc-compile scan_double.c

scan_float.o:\
cc-compile scan_float.c sd_math.h scan.h 
	./cc-compile scan_float.c

scan_int.o:\
cc-compile scan_int.c scan.h 
	./cc-compile scan_int.c

scan_intb.o:\
cc-compile scan_intb.c scan.h 
	./cc-compile scan_intb.c

scan_into.o:\
cc-compile scan_into.c scan.h 
	./cc-compile scan_into.c

scan_intx.o:\
cc-compile scan_intx.c scan.h 
	./cc-compile scan_intx.c

scan_llong.o:\
cc-compile scan_llong.c sd_longlong.h scan.h 
	./cc-compile scan_llong.c

scan_llongb.o:\
cc-compile scan_llongb.c scan.h sd_inline.h sd_longlong.h 
	./cc-compile scan_llongb.c

scan_llongo.o:\
cc-compile scan_llongo.c scan.h sd_longlong.h 
	./cc-compile scan_llongo.c

scan_llongx.o:\
cc-compile scan_llongx.c scan.h sd_longlong.h 
	./cc-compile scan_llongx.c

scan_long.o:\
cc-compile scan_long.c scan.h 
	./cc-compile scan_long.c

scan_longb.o:\
cc-compile scan_longb.c scan.h sd_inline.h 
	./cc-compile scan_longb.c

scan_longo.o:\
cc-compile scan_longo.c scan.h 
	./cc-compile scan_longo.c

scan_longx.o:\
cc-compile scan_longx.c scan.h 
	./cc-compile scan_longx.c

scan_nchars.o:\
cc-compile scan_nchars.c scan.h 
	./cc-compile scan_nchars.c

scan_ncharsn.o:\
cc-compile scan_ncharsn.c scan.h 
	./cc-compile scan_ncharsn.c

scan_newline.o:\
cc-compile scan_newline.c scan.h 
	./cc-compile scan_newline.c

scan_short.o:\
cc-compile scan_short.c scan.h 
	./cc-compile scan_short.c

scan_shortb.o:\
cc-compile scan_shortb.c scan.h 
	./cc-compile scan_shortb.c

scan_shorto.o:\
cc-compile scan_shorto.c scan.h 
	./cc-compile scan_shorto.c

scan_shortx.o:\
cc-compile scan_shortx.c scan.h 
	./cc-compile scan_shortx.c

scan_space.o:\
cc-compile scan_space.c scan.h 
	./cc-compile scan_space.c

sd_fcntl.h:\
_sd_fcntl.h 

sd_fd.h:\
_sd_fd.h 

sd_inline.h:\
_sd_inline.h 

sd_longlong.h:\
_sd_longlong.h 

sd_math.h:\
_sd_math.h 

sgetline.a:\
cc-slib sgetline.sld sgetline.o sgetline_chop.o sgetline_data.o \
sgetline_get.o sgetline_lnum.o sgetline_size.o 
	./cc-slib sgetline sgetline.o sgetline_chop.o sgetline_data.o \
	sgetline_get.o sgetline_lnum.o sgetline_size.o 

sgetline.h:\
buffer.h 

sgetline.o:\
cc-compile sgetline.c sgetline.h 
	./cc-compile sgetline.c

sgetline_chop.o:\
cc-compile sgetline_chop.c sgetline.h 
	./cc-compile sgetline_chop.c

sgetline_data.o:\
cc-compile sgetline_data.c sgetline.h 
	./cc-compile sgetline_data.c

sgetline_get.o:\
cc-compile sgetline_get.c bin.h buffer.h sgetline.h sstring.h 
	./cc-compile sgetline_get.c

sgetline_lnum.o:\
cc-compile sgetline_lnum.c sgetline.h 
	./cc-compile sgetline_lnum.c

sgetline_size.o:\
cc-compile sgetline_size.c sgetline.h 
	./cc-compile sgetline_size.c

sig.a:\
cc-slib sig.sld sig.o sig_block.o sig_catch.o sig_pause.o 
	./cc-slib sig sig.o sig_block.o sig_catch.o sig_pause.o 

sig.o:\
cc-compile sig.c sig.h 
	./cc-compile sig.c

sig_action.h:\
_sig_action.h 

sig_block.o:\
cc-compile sig_block.c sig.h sig_pmask.h 
	./cc-compile sig_block.c

sig_catch.o:\
cc-compile sig_catch.c sig.h sig_action.h 
	./cc-compile sig_catch.c

sig_pause.o:\
cc-compile sig_pause.c sig.h sig_pmask.h 
	./cc-compile sig_pause.c

sig_pmask.h:\
_sig_pmask.h 

squeue.a:\
cc-slib squeue.sld squeue_bytes.o squeue_data.o squeue_deq.o squeue_enq.o \
squeue_init.o squeue_peek.o squeue_size.o 
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
cc-slib sstack.sld sstack_bytes.o sstack_data.o sstack_init.o sstack_peek.o \
sstack_pop.o sstack_push.o sstack_size.o 
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
cc-slib sstring.sld sstring_0.o sstring_cat.o sstring_catb.o sstring_cats.o \
sstring_copy.o sstring_cpyb.o sstring_cpys.o sstring_init.o sstring_chop.o 
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
cc-slib str.sld str_char.o str_chr.o str_ci_diff.o str_ci_ndiff.o str_diff.o \
str_dup.o str_ends.o str_len.o str_ndiff.o str_rchar.o str_rchr.o \
str_starts.o str_tolower.o str_toupper.o 
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

sysinfo:\
cc-link sysinfo.ld sysinfo.o 
	./cc-link sysinfo sysinfo.o 

sysinfo.o:\
cc-compile sysinfo.c _sysinfo.h 
	./cc-compile sysinfo.c

uint.a:\
cc-slib uint.sld uint_pack.o uint_unpack.o 
	./cc-slib uint uint_pack.o uint_unpack.o 

uint_pack.o:\
cc-compile uint_pack.c uint.h 
	./cc-compile uint_pack.c

uint_unpack.o:\
cc-compile uint_unpack.c uint.h 
	./cc-compile uint_unpack.c

clean-all: sysdeps_clean tests_clean obj_clean 
clean: obj_clean
obj_clean: 
	rm -f alloc.a alloc.o array.a array.o array_bytes.o array_cat.o \
	array_chop.o array_copy.o array_data.o array_index.o array_size.o \
	array_trunc.o array_zero.o base_name.a base_name.o bin.a bin_char.o \
	bin_chr.o bin_copy.o bin_copyr.o bin_count.o bin_diff.o bin_rchar.o \
	bin_rchr.o bin_set.o bin_tolower.o bin_toupper.o bin_zero.o buffer.a \
	buffer0.o buffer1.o buffer2.o buffer_copy.o buffer_get.o \
	buffer_init.o buffer_put.o closeonexec.a closeonexec.o conf-ldtype \
	corelib-conf corelib-conf.o ctxt/bindir.c ctxt/bindir.o ctxt/ctxt.a \
	ctxt/dlibdir.c ctxt/dlibdir.o ctxt/incdir.c ctxt/incdir.o \
	ctxt/repos.c ctxt/repos.o ctxt/slibdir.c ctxt/slibdir.o \
	ctxt/version.c ctxt/version.o deinstaller deinstaller.o dgetline.a \
	dgetline_chop.o dgetline_data.o dgetline_free.o dgetline_get.o \
	dgetline_init.o dgetline_lnum.o dgetline_size.o 
	rm -f dir_array.a dir_array.o dir_hash.a dir_hash.o dir_name.a \
	dir_name.o dstring.a dstring_0.o dstring_cat.o dstring_catb.o \
	dstring_cats.o dstring_chop.o dstring_copy.o dstring_cpyb.o \
	dstring_cpys.o dstring_data.o dstring_init.o dstring_size.o \
	dstring_trunc.o env.a env.o env_get.o error.a error.o error_str.o \
	fd.a fd_dup.o fd_move.o fd_reset.o fd_seek.a fd_seek_cur.o \
	fd_seek_end.o fd_seek_pos.o fd_seek_start.o fmt.a fmt_char.o \
	fmt_charb.o fmt_charo.o fmt_charx.o fmt_double.o fmt_float.o \
	fmt_int.o fmt_intb.o fmt_into.o fmt_intx.o fmt_llong.o fmt_llongb.o \
	fmt_llongo.o fmt_llongx.o fmt_long.o fmt_longb.o fmt_longo.o \
	fmt_longx.o fmt_nstr.o fmt_pad_c.o fmt_pad_i.o fmt_pad_l.o \
	fmt_pad_ll.o fmt_pad_s.o fmt_short.o fmt_shortb.o fmt_shorto.o \
	fmt_shortx.o fmt_str.o 
	rm -f get_opt.a get_opt.o hashtable.a ht_addb.o ht_adds.o \
	ht_bytes.o ht_checkb.o ht_checks.o ht_deleteb.o ht_deletes.o \
	ht_free.o ht_getb.o ht_gets.o ht_hash.o ht_init.o ht_iter.o \
	ht_replaceb.o ht_replaces.o iarray.a iarray_bytes.o iarray_cat.o \
	iarray_chop.o iarray_copy.o iarray_free.o iarray_index.o \
	iarray_init.o iarray_insert.o iarray_node.o iarray_remove.o \
	iarray_size.o iarray_sort.o iarray_trunc.o iarray_zero.o inst-check \
	inst-check.o inst-copy inst-copy.o inst-dir inst-dir.o inst-link \
	inst-link.o install_core.o install_error.o installer installer.o \
	instchk instchk.o insthier.o mk-ctxt nonblock.a nonblock.o open.a \
	open_append.o open_creat.o open_excl.o open_ro.o open_rw.o \
	open_trunc.o open_wo.o rmkdir.a rmkdir.o sarray.a sarray_bytes.o \
	sarray_cat.o 
	rm -f sarray_chop.o sarray_data.o sarray_index.o sarray_init.o \
	sarray_size.o sarray_trunc.o scan.a scan_char.o scan_charb.o \
	scan_charo.o scan_chars.o scan_charsn.o scan_charx.o scan_double.o \
	scan_float.o scan_int.o scan_intb.o scan_into.o scan_intx.o \
	scan_llong.o scan_llongb.o scan_llongo.o scan_llongx.o scan_long.o \
	scan_longb.o scan_longo.o scan_longx.o scan_nchars.o scan_ncharsn.o \
	scan_newline.o scan_short.o scan_shortb.o scan_shorto.o \
	scan_shortx.o scan_space.o sgetline.a sgetline.o sgetline_chop.o \
	sgetline_data.o sgetline_get.o sgetline_lnum.o sgetline_size.o sig.a \
	sig.o sig_block.o sig_catch.o sig_pause.o squeue.a squeue_bytes.o \
	squeue_data.o squeue_deq.o squeue_enq.o squeue_init.o squeue_peek.o \
	squeue_size.o sstack.a sstack_bytes.o sstack_data.o sstack_init.o \
	sstack_peek.o sstack_pop.o sstack_push.o sstack_size.o sstring.a 
	rm -f sstring_0.o sstring_cat.o sstring_catb.o sstring_cats.o \
	sstring_chop.o sstring_copy.o sstring_cpyb.o sstring_cpys.o \
	sstring_init.o stalloc.a stalloc.o str.a str_char.o str_chr.o \
	str_ci_diff.o str_ci_ndiff.o str_diff.o str_dup.o str_ends.o \
	str_len.o str_ndiff.o str_rchar.o str_rchr.o str_starts.o \
	str_tolower.o str_toupper.o syserr.a syserr_die.o syserr_init.o \
	sysinfo sysinfo.o uint.a uint_pack.o uint_unpack.o 

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
	(cd UNIT_TESTS; make clean-all)
regen:
	cpj-genmk > Makefile.tmp && mv Makefile.tmp Makefile

