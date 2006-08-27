# auto generated - do not edit
SHELL=/bin/sh
default: all
all: phase_tools_local phase_tools phase_pregen_local phase_pregen \
	phase_compile_local phase_compile phase_library_local phase_library \
	phase_link_local phase_link 
tests: phase_test
clean: phase_local_clean phase_tools_clean phase_pregen_clean \
	phase_compile_clean phase_library_clean phase_link_clean \
	phase_test_clean 

#--LINK-----------------------------------------------------------------------

t_alloc:\
	ld t_alloc.ld t_alloc.o ../alloc.a 
	./ld t_alloc t_alloc.o ../alloc.a 
t_array:\
	ld t_array.ld t_array.o ../array.a ../bin.a ../alloc.a 
	./ld t_array t_array.o ../array.a ../bin.a ../alloc.a 
t_base_name:\
	ld t_base_name.ld t_base_name.o ../base_name.a \
	../syserr.a ../buffer.a ../error.a ../bin.a ../str.a 
	./ld t_base_name t_base_name.o ../base_name.a ../syserr.a \
	../buffer.a ../error.a ../bin.a ../str.a 
t_bin:\
	ld t_bin.ld t_bin.o ../bin.a 
	./ld t_bin t_bin.o ../bin.a 
t_buffer:\
	ld t_buffer.ld t_buffer.o ../buffer.a ../error.a \
	../bin.a ../str.a 
	./ld t_buffer t_buffer.o ../buffer.a ../error.a ../bin.a ../str.a 
t_dir_array:\
	ld t_dir_array.ld t_dir_array.o ../dir_array.a \
	../alloc.a ../bin.a ../str.a 
	./ld t_dir_array t_dir_array.o ../dir_array.a ../alloc.a ../bin.a \
	../str.a 
t_dir_hash:\
	ld t_dir_hash.ld t_dir_hash.o ../dir_hash.a \
	../dir_array.a ../alloc.a ../syserr.a ../buffer.a ../error.a \
	../bin.a ../str.a 
	./ld t_dir_hash t_dir_hash.o ../dir_hash.a ../dir_array.a \
	../alloc.a ../syserr.a ../buffer.a ../error.a ../bin.a ../str.a 
t_dir_name:\
	ld t_dir_name.ld t_dir_name.o ../dir_name.a \
	../dir_array.a ../alloc.a ../syserr.a ../buffer.a ../error.a \
	../bin.a ../str.a 
	./ld t_dir_name t_dir_name.o ../dir_name.a ../dir_array.a \
	../alloc.a ../syserr.a ../buffer.a ../error.a ../bin.a ../str.a 
t_dstring:\
	ld t_dstring.ld t_dstring.o ../dstring.a ../alloc.a \
	../bin.a ../str.a 
	./ld t_dstring t_dstring.o ../dstring.a ../alloc.a ../bin.a \
	../str.a 
t_env:\
	ld t_env.ld t_env.o ../env.a ../alloc.a ../str.a ../bin.a 
	./ld t_env t_env.o ../env.a ../alloc.a ../str.a ../bin.a 
t_fd:\
	ld t_fd.ld t_fd.o ../fd.a 
	./ld t_fd t_fd.o ../fd.a 
t_float:\
	ld t_float.ld t_float.o ../float32.a ../float64.a 
	./ld t_float t_float.o ../float32.a ../float64.a 
t_fmt:\
	ld t_fmt.ld t_fmt.o ../fmt.a 
	./ld t_fmt t_fmt.o ../fmt.a 
t_fmt2:\
	ld t_fmt2.ld t_fmt2.o ../fmt.a ../str.a 
	./ld t_fmt2 t_fmt2.o ../fmt.a ../str.a 
t_fmt_spec:\
	ld t_fmt_spec.ld t_fmt_spec.o ../fmt_spec.a 
	./ld t_fmt_spec t_fmt_spec.o ../fmt_spec.a 
t_get_opt:\
	ld t_get_opt.ld t_get_opt.o ../get_opt.a ../buffer.a \
	../error.a ../bin.a ../str.a 
	./ld t_get_opt t_get_opt.o ../get_opt.a ../buffer.a ../error.a \
	../bin.a ../str.a 
t_hashtable1:\
	ld t_hashtable1.ld t_hashtable1.o t_hashtable_d.o \
	../hashtable.a ../error.a ../bin.a ../str.a ../alloc.a 
	./ld t_hashtable1 t_hashtable1.o t_hashtable_d.o ../hashtable.a \
	../error.a ../bin.a ../str.a ../alloc.a 
t_hashtable2:\
	ld t_hashtable2.ld t_hashtable2.o t_hashtable_d.o \
	t_hashtable_c.o ../hashtable.a ../error.a ../bin.a ../str.a \
	../alloc.a 
	./ld t_hashtable2 t_hashtable2.o t_hashtable_d.o t_hashtable_c.o \
	../hashtable.a ../error.a ../bin.a ../str.a ../alloc.a 
t_hashtable3:\
	ld t_hashtable3.ld t_hashtable3.o t_hashtable_d.o \
	t_hashtable_c.o ../hashtable.a ../error.a ../bin.a ../str.a \
	../alloc.a 
	./ld t_hashtable3 t_hashtable3.o t_hashtable_d.o t_hashtable_c.o \
	../hashtable.a ../error.a ../bin.a ../str.a ../alloc.a 
t_hashtable4:\
	ld t_hashtable4.ld t_hashtable4.o t_hashtable_d.o \
	t_hashtable_c.o ../hashtable.a ../error.a ../bin.a ../str.a \
	../alloc.a 
	./ld t_hashtable4 t_hashtable4.o t_hashtable_d.o t_hashtable_c.o \
	../hashtable.a ../error.a ../bin.a ../str.a ../alloc.a 
t_hashtable5:\
	ld t_hashtable5.ld t_hashtable5.o t_hashtable_d.o \
	t_hashtable_c.o ../hashtable.a ../error.a ../bin.a ../str.a \
	../alloc.a 
	./ld t_hashtable5 t_hashtable5.o t_hashtable_d.o t_hashtable_c.o \
	../hashtable.a ../error.a ../bin.a ../str.a ../alloc.a 
t_int:\
	ld t_int.ld t_int.o ../int16.a ../int32.a ../int64.a 
	./ld t_int t_int.o ../int16.a ../int32.a ../int64.a 
t_open:\
	ld t_open.ld t_open.o ../open.a 
	./ld t_open t_open.o ../open.a 
t_scan:\
	ld t_scan.ld t_scan.o ../scan.a 
	./ld t_scan t_scan.o ../scan.a 
t_scan2:\
	ld t_scan2.ld t_scan2.o ../scan.a 
	./ld t_scan2 t_scan2.o ../scan.a 
t_scan3:\
	ld t_scan3.ld t_scan3.o ../scan.a 
	./ld t_scan3 t_scan3.o ../scan.a 
t_scan_float:\
	ld t_scan_float.ld t_scan_float.o ../scan.a 
	./ld t_scan_float t_scan_float.o ../scan.a 
t_scan_fspec:\
	ld t_scan_fspec.ld t_scan_fspec.o ../scan_fspec.a 
	./ld t_scan_fspec t_scan_fspec.o ../scan_fspec.a 
t_scan_spec:\
	ld t_scan_spec.ld t_scan_spec.o ../scan_spec.a 
	./ld t_scan_spec t_scan_spec.o ../scan_spec.a 
t_seek:\
	ld t_seek.ld t_seek.o ../seek.a 
	./ld t_seek t_seek.o ../seek.a 
t_sgetline:\
	ld t_sgetline.ld t_sgetline.o ../sgetline.a \
	../sstring.a ../buffer.a ../error.a ../bin.a ../str.a 
	./ld t_sgetline t_sgetline.o ../sgetline.a ../sstring.a ../buffer.a \
	../error.a ../bin.a ../str.a 
t_signal:\
	ld t_signal.ld t_signal.o ../signal.a 
	./ld t_signal t_signal.o ../signal.a 
t_sstring:\
	ld t_sstring.ld t_sstring.o ../sstring.a 
	./ld t_sstring t_sstring.o ../sstring.a 
t_stalloc:\
	ld t_stalloc.ld t_stalloc.o ../alloc.a ../stalloc.a \
	../error.a 
	./ld t_stalloc t_stalloc.o ../alloc.a ../stalloc.a ../error.a 
t_str:\
	ld t_str.ld t_str.o ../str.a ../bin.a ../alloc.a 
	./ld t_str t_str.o ../str.a ../bin.a ../alloc.a 
t_uint:\
	ld t_uint.ld t_uint.o ../uint16.a ../uint32.a ../uint64.a 
	./ld t_uint t_uint.o ../uint16.a ../uint32.a ../uint64.a 

phase_link: t_alloc t_array t_base_name t_bin t_buffer t_dir_array \
	t_dir_hash t_dir_name t_dstring t_env t_fd t_float t_fmt t_fmt2 \
	t_fmt_spec t_get_opt t_hashtable1 t_hashtable2 t_hashtable3 \
	t_hashtable4 t_hashtable5 t_int t_open t_scan t_scan2 t_scan3 \
	t_scan_float t_scan_fspec t_scan_spec t_seek t_sgetline t_signal \
	t_sstring t_stalloc t_str t_uint 
phase_link_clean:
	rm -f t_alloc t_array t_base_name t_bin t_buffer \
	t_dir_array t_dir_hash t_dir_name t_dstring t_env t_fd t_float t_fmt \
	t_fmt2 t_fmt_spec t_get_opt t_hashtable1 t_hashtable2 t_hashtable3 \
	t_hashtable4 t_hashtable5 t_int t_open t_scan t_scan2 t_scan3 \
	t_scan_float t_scan_fspec t_scan_spec t_seek t_sgetline t_signal \
	t_sstring t_stalloc t_str t_uint 

#--LIBRARY--------------------------------------------------------------------


phase_library: 
phase_library_clean:


#--COMPILE--------------------------------------------------------------------

t_alloc.o:\
	cc t_alloc.c ../alloc.h 
	./cc t_alloc t_alloc.c 
t_array.o:\
	cc t_array.c ../array.h 
	./cc t_array t_array.c 
t_base_name.o:\
	cc t_base_name.c ../buffer.h ../base_name.h \
	../str.h ../syserr.h 
	./cc t_base_name t_base_name.c 
t_bin.o:\
	cc t_bin.c ../bin.h 
	./cc t_bin t_bin.c 
t_buffer.o:\
	cc t_buffer.c ../buffer.h 
	./cc t_buffer t_buffer.c 
t_dir_array.o:\
	cc t_dir_array.c ../dir_array.h 
	./cc t_dir_array t_dir_array.c 
t_dir_hash.o:\
	cc t_dir_hash.c ../dir_hash.h ../syserr.h 
	./cc t_dir_hash t_dir_hash.c 
t_dir_name.o:\
	cc t_dir_name.c ../buffer.h ../dir_name.h ../str.h \
	../syserr.h 
	./cc t_dir_name t_dir_name.c 
t_dstring.o:\
	cc t_dstring.c ../alloc.h ../dstring.h 
	./cc t_dstring t_dstring.c 
t_env.o:\
	cc t_env.c ../env.h ../str.h 
	./cc t_env t_env.c 
t_fd.o:\
	cc t_fd.c ../fd.h 
	./cc t_fd t_fd.c 
t_float.o:\
	cc t_float.c ../float32.h ../float64.h 
	./cc t_float t_float.c 
t_fmt.o:\
	cc t_fmt.c ../fmt.h 
	./cc t_fmt t_fmt.c 
t_fmt2.o:\
	cc t_fmt2.c ../fmt.h ../str.h 
	./cc t_fmt2 t_fmt2.c 
t_fmt_spec.o:\
	cc t_fmt_spec.c ../fmt_spec.h 
	./cc t_fmt_spec t_fmt_spec.c 
t_get_opt.o:\
	cc t_get_opt.c ../get_opt.h 
	./cc t_get_opt t_get_opt.c 
t_hashtable1.o:\
	cc t_hashtable1.c t_hashtable.h ../hashtable.h 
	./cc t_hashtable1 t_hashtable1.c 
t_hashtable2.o:\
	cc t_hashtable2.c t_hashtable.h ../hashtable.h \
	../bin.h ../alloc.h 
	./cc t_hashtable2 t_hashtable2.c 
t_hashtable3.o:\
	cc t_hashtable3.c t_hashtable.h ../hashtable.h \
	../bin.h ../str.h 
	./cc t_hashtable3 t_hashtable3.c 
t_hashtable4.o:\
	cc t_hashtable4.c t_hashtable.h ../hashtable.h \
	../bin.h ../alloc.h ../str.h 
	./cc t_hashtable4 t_hashtable4.c 
t_hashtable5.o:\
	cc t_hashtable5.c t_hashtable.h ../hashtable.h \
	../bin.h ../error.h ../alloc.h ../str.h 
	./cc t_hashtable5 t_hashtable5.c 
t_hashtable_c.o:\
	cc t_hashtable_c.c t_hashtable.h ../hashtable.h \
	../bin.h ../str.h 
	./cc t_hashtable_c t_hashtable_c.c 
t_hashtable_d.o:\
	cc t_hashtable_d.c 
	./cc t_hashtable_d t_hashtable_d.c 
t_int.o:\
	cc t_int.c ../int16.h ../int32.h ../int64.h 
	./cc t_int t_int.c 
t_open.o:\
	cc t_open.c ../open.h 
	./cc t_open t_open.c 
t_scan.o:\
	cc t_scan.c ../scan.h 
	./cc t_scan t_scan.c 
t_scan2.o:\
	cc t_scan2.c ../scan.h 
	./cc t_scan2 t_scan2.c 
t_scan3.o:\
	cc t_scan3.c ../scan.h 
	./cc t_scan3 t_scan3.c 
t_scan_float.o:\
	cc t_scan_float.c ../scan.h 
	./cc t_scan_float t_scan_float.c 
t_scan_fspec.o:\
	cc t_scan_fspec.c ../scan_fspec.h 
	./cc t_scan_fspec t_scan_fspec.c 
t_scan_spec.o:\
	cc t_scan_spec.c ../scan_spec.h ../uint32.h \
	../uint64.h 
	./cc t_scan_spec t_scan_spec.c 
t_seek.o:\
	cc t_seek.c ../seek.h ../int64.h 
	./cc t_seek t_seek.c 
t_sgetline.o:\
	cc t_sgetline.c ../buffer.h ../close.h ../read.h \
	../sgetline.h 
	./cc t_sgetline t_sgetline.c 
t_signal.o:\
	cc t_signal.c ../signal.h 
	./cc t_signal t_signal.c 
t_sstring.o:\
	cc t_sstring.c ../sstring.h 
	./cc t_sstring t_sstring.c 
t_stalloc.o:\
	cc t_stalloc.c ../alloc.h ../stalloc.h 
	./cc t_stalloc t_stalloc.c 
t_str.o:\
	cc t_str.c ../error.h ../str.h 
	./cc t_str t_str.c 
t_uint.o:\
	cc t_uint.c ../uint16.h ../uint32.h ../uint64.h 
	./cc t_uint t_uint.c 

phase_compile: t_alloc.o t_array.o t_base_name.o t_bin.o t_buffer.o \
	t_dir_array.o t_dir_hash.o t_dir_name.o t_dstring.o t_env.o t_fd.o \
	t_float.o t_fmt.o t_fmt2.o t_fmt_spec.o t_get_opt.o t_hashtable1.o \
	t_hashtable2.o t_hashtable3.o t_hashtable4.o t_hashtable5.o \
	t_hashtable_c.o t_hashtable_d.o t_int.o t_open.o t_scan.o t_scan2.o \
	t_scan3.o t_scan_float.o t_scan_fspec.o t_scan_spec.o t_seek.o \
	t_sgetline.o t_signal.o t_sstring.o t_stalloc.o t_str.o t_uint.o 
phase_compile_clean:
	rm -f t_alloc.o t_array.o t_base_name.o \
	t_bin.o t_buffer.o t_dir_array.o t_dir_hash.o t_dir_name.o \
	t_dstring.o t_env.o t_fd.o t_float.o t_fmt.o t_fmt2.o t_fmt_spec.o \
	t_get_opt.o t_hashtable1.o t_hashtable2.o t_hashtable3.o \
	t_hashtable4.o t_hashtable5.o t_hashtable_c.o t_hashtable_d.o \
	t_int.o t_open.o t_scan.o t_scan2.o t_scan3.o t_scan_float.o \
	t_scan_fspec.o t_scan_spec.o t_seek.o t_sgetline.o t_signal.o \
	t_sstring.o t_stalloc.o t_str.o t_uint.o 

#--PREGEN---------------------------------------------------------------------


phase_pregen: 
phase_pregen_clean:


#--LOCAL----------------------------------------------------------------------

phase_tools_local: tools
phase_pregen_local:
phase_compile_local:
phase_library_local:
phase_link_local:
phase_local_clean: toollink_clean

phase_tools:
phase_tools_clean:

toollink_clean:
	rm -f cc ld conf-systype conf-cctype conf-cc conf-ld

tools: cc ld conf-systype conf-cctype conf-cc conf-ld

cc: ../cc
	ln -s ../cc cc
ld: ../ld
	ln -s ../ld ld
conf-cc: ../conf-cc
	ln -s ../conf-cc conf-cc
conf-ld: ../conf-ld
	ln -s ../conf-ld conf-ld
conf-systype:
	ln -s ../conf-systype conf-systype
conf-cctype:
	ln -s ../conf-cctype conf-cctype

#--TEST-----------------------------------------------------------------------

phase_test: list_tests run_tests
phase_test_clean: tests_clean

tests_clean:
	rm -f testlist

list_tests:
	./list-tests > testlist

run_tests:
	./run-tests -v
regen:
	cpj-genmk -t > Makefile.tmp
	mv Makefile.tmp Makefile
