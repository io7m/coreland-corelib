# auto generated - do not edit
# cpj-genmk-0.70

SHELL=/bin/sh
default: all
all: phase_tools_local phase_compile_local phase_compile \
	phase_library_local phase_library phase_link_local phase_link 

tests: phase_test 

clean: phase_local_clean phase_compile_clean phase_library_clean \
	phase_link_clean phase_test_clean 


#--COMPILE--------------------------------------------------------------------

t_alloc.o:\
	compile t_alloc.c ../alloc.h 
	./compile t_alloc t_alloc.c 
t_array.o:\
	compile t_array.c ../array.h 
	./compile t_array t_array.c 
t_bin.o:\
	compile t_bin.c ../bin.h 
	./compile t_bin t_bin.c 
t_buffer.o:\
	compile t_buffer.c ../buffer.h 
	./compile t_buffer t_buffer.c 
t_dir_array.o:\
	compile t_dir_array.c ../dir_array.h 
	./compile t_dir_array t_dir_array.c 
t_dstring.o:\
	compile t_dstring.c ../dstring.h 
	./compile t_dstring t_dstring.c 
t_fd.o:\
	compile t_fd.c ../fd.h 
	./compile t_fd t_fd.c 
t_float.o:\
	compile t_float.c ../float32.h ../float64.h 
	./compile t_float t_float.c 
t_fmt.o:\
	compile t_fmt.c ../fmt.h 
	./compile t_fmt t_fmt.c 
t_get_opt.o:\
	compile t_get_opt.c ../get_opt.h 
	./compile t_get_opt t_get_opt.c 
t_hashtable.o:\
	compile t_hashtable.c ../hashtable.h 
	./compile t_hashtable t_hashtable.c 
t_int.o:\
	compile t_int.c ../int16.h ../int32.h ../int64.h 
	./compile t_int t_int.c 
t_open.o:\
	compile t_open.c ../open.h 
	./compile t_open t_open.c 
t_scan.o:\
	compile t_scan.c ../scan.h ../uint32.h ../uint64.h 
	./compile t_scan t_scan.c 
t_scan2.o:\
	compile t_scan2.c ../scan.h 
	./compile t_scan2 t_scan2.c 
t_scan_float.o:\
	compile t_scan_float.c ../scan_float.h ../int32.h ../int64.h \
	../float32.h ../float64.h 
	./compile t_scan_float t_scan_float.c 
t_seek.o:\
	compile t_seek.c ../seek.h ../int64.h 
	./compile t_seek t_seek.c 
t_sgetline.o:\
	compile t_sgetline.c ../buffer.h ../close.h ../read.h ../sgetline.h 
	./compile t_sgetline t_sgetline.c 
t_sstring.o:\
	compile t_sstring.c ../sstring.h 
	./compile t_sstring t_sstring.c 
t_stalloc.o:\
	compile t_stalloc.c ../alloc.h ../stalloc.h 
	./compile t_stalloc t_stalloc.c 
t_str.o:\
	compile t_str.c ../error.h ../str.h 
	./compile t_str t_str.c 
t_uint.o:\
	compile t_uint.c ../uint16.h ../uint32.h ../uint64.h 
	./compile t_uint t_uint.c 

phase_compile:\
	t_alloc.o t_array.o t_bin.o t_buffer.o t_dir_array.o t_dstring.o \
	t_fd.o t_float.o t_fmt.o t_get_opt.o t_hashtable.o t_int.o t_open.o \
	t_scan.o t_scan2.o t_scan_float.o t_seek.o t_sgetline.o t_sstring.o \
	t_stalloc.o t_str.o t_uint.o 
phase_compile_clean:
	rm -f t_alloc.o t_array.o t_bin.o t_buffer.o t_dir_array.o \
	t_dstring.o t_fd.o t_float.o t_fmt.o t_get_opt.o t_hashtable.o \
	t_int.o t_open.o t_scan.o t_scan2.o t_scan_float.o t_seek.o \
	t_sgetline.o t_sstring.o t_stalloc.o t_str.o t_uint.o 

#--LIBRARY--------------------------------------------------------------------


phase_library:
phase_library_clean:

#--LINK-----------------------------------------------------------------------

t_alloc:\
	link t_alloc.ld t_alloc.o ../alloc.a 
	./link t_alloc t_alloc.o ../alloc.a 
t_array:\
	link t_array.ld t_array.o ../array.a ../bin.a ../alloc.a 
	./link t_array t_array.o ../array.a ../bin.a ../alloc.a 
t_bin:\
	link t_bin.ld t_bin.o ../bin.a 
	./link t_bin t_bin.o ../bin.a 
t_buffer:\
	link t_buffer.ld t_buffer.o ../buffer.a ../error.a ../bin.a \
	../str.a 
	./link t_buffer t_buffer.o ../buffer.a ../error.a ../bin.a ../str.a 
t_dir_array:\
	link t_dir_array.ld t_dir_array.o ../dir_array.a ../alloc.a \
	../bin.a ../str.a 
	./link t_dir_array t_dir_array.o ../dir_array.a ../alloc.a ../bin.a \
	../str.a 
t_dstring:\
	link t_dstring.ld t_dstring.o ../dstring.a ../alloc.a ../bin.a \
	../str.a 
	./link t_dstring t_dstring.o ../dstring.a ../alloc.a ../bin.a \
	../str.a 
t_fd:\
	link t_fd.ld t_fd.o ../fd.a 
	./link t_fd t_fd.o ../fd.a 
t_float:\
	link t_float.ld t_float.o ../float32.a ../float64.a 
	./link t_float t_float.o ../float32.a ../float64.a 
t_fmt:\
	link t_fmt.ld t_fmt.o ../fmt.a 
	./link t_fmt t_fmt.o ../fmt.a 
t_get_opt:\
	link t_get_opt.ld t_get_opt.o ../get_opt.a ../buffer.a ../error.a \
	../bin.a ../str.a 
	./link t_get_opt t_get_opt.o ../get_opt.a ../buffer.a ../error.a \
	../bin.a ../str.a 
t_hashtable:\
	link t_hashtable.ld t_hashtable.o ../hashtable.a ../uint32.a \
	../str.a ../bin.a ../alloc.a 
	./link t_hashtable t_hashtable.o ../hashtable.a ../uint32.a \
	../str.a ../bin.a ../alloc.a 
t_int:\
	link t_int.ld t_int.o ../int16.a ../int32.a ../int64.a 
	./link t_int t_int.o ../int16.a ../int32.a ../int64.a 
t_open:\
	link t_open.ld t_open.o ../open.a 
	./link t_open t_open.o ../open.a 
t_scan:\
	link t_scan.ld t_scan.o ../scan.a 
	./link t_scan t_scan.o ../scan.a 
t_scan2:\
	link t_scan2.ld t_scan2.o ../scan.a 
	./link t_scan2 t_scan2.o ../scan.a 
t_scan_float:\
	link t_scan_float.ld t_scan_float.o ../scan_float.a 
	./link t_scan_float t_scan_float.o ../scan_float.a 
t_seek:\
	link t_seek.ld t_seek.o ../seek.a 
	./link t_seek t_seek.o ../seek.a 
t_sgetline:\
	link t_sgetline.ld t_sgetline.o ../sgetline.a ../sstring.a \
	../buffer.a ../error.a ../bin.a ../str.a 
	./link t_sgetline t_sgetline.o ../sgetline.a ../sstring.a \
	../buffer.a ../error.a ../bin.a ../str.a 
t_sstring:\
	link t_sstring.ld t_sstring.o ../sstring.a 
	./link t_sstring t_sstring.o ../sstring.a 
t_stalloc:\
	link t_stalloc.ld t_stalloc.o ../alloc.a ../stalloc.a 
	./link t_stalloc t_stalloc.o ../alloc.a ../stalloc.a 
t_str:\
	link t_str.ld t_str.o ../str.a ../bin.a ../alloc.a 
	./link t_str t_str.o ../str.a ../bin.a ../alloc.a 
t_uint:\
	link t_uint.ld t_uint.o ../uint16.a ../uint32.a ../uint64.a 
	./link t_uint t_uint.o ../uint16.a ../uint32.a ../uint64.a 

phase_link:\
	t_alloc t_array t_bin t_buffer t_dir_array t_dstring t_fd t_float \
	t_fmt t_get_opt t_hashtable t_int t_open t_scan t_scan2 t_scan_float \
	t_seek t_sgetline t_sstring t_stalloc t_str t_uint 
phase_link_clean:
	rm -f t_alloc t_array t_bin t_buffer t_dir_array t_dstring t_fd \
	t_float t_fmt t_get_opt t_hashtable t_int t_open t_scan t_scan2 \
	t_scan_float t_seek t_sgetline t_sstring t_stalloc t_str t_uint 

#--TEST-----------------------------------------------------------------------

phase_test: list_tests run_tests
phase_test_clean: tests_clean

tests_clean:
	rm -f testlist

list_tests:
	./list-tests > testlist

run_tests:
	./run-tests -v

#--LOCAL----------------------------------------------------------------------

phase_tools_local: tools
phase_compile_local:
phase_library_local:
phase_link_local:
phase_local_clean: toollink_clean

toollink_clean:
	rm -f compile link makeso makelib

tools: compile link makeso makelib

compile: ../compile
	ln -s ../compile compile
link: ../link
	ln -s ../link link
makeso: ../makeso
	ln -s ../makeso makeso
makelib: ../makelib
	ln -s ../makelib makelib

#--TOOLS----------------------------------------------------------------------

regen:
	cpj-genmk > Makefile.tmp
	mv Makefile.tmp Makefile
