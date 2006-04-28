# $Id: Makefile,v 1.22 2006/03/12 21:43:22 mzero Exp $
# auto generated - do not edit

SHELL=/bin/sh
default: all
all:\
  local_pre\
  compile link makelib makeso local \
  targets objects dlibs slibs execs local_post 

dlibs:\
	

slibs:\
	

execs:\
	t_alloc t_bin t_buffer t_array t_str t_dstring t_hashtable \
	t_fd t_int t_uint t_open t_scan t_scan_float t_fmt t_scan2 \
	t_seek t_sstring t_get_opt t_dir_array t_sgetline t_stalloc \
	t_float 

t_alloc:\
	link t_alloc.o\
	../alloc.a 
	./link t_alloc\
	../alloc.a 

t_bin:\
	link t_bin.o\
	../bin.a 
	./link t_bin\
	../bin.a 

t_buffer:\
	link t_buffer.o\
	../buffer.a ../error.a ../bin.a ../str.a 
	./link t_buffer\
	../buffer.a ../error.a ../bin.a ../str.a 

t_array:\
	link t_array.o\
	../array.a ../bin.a ../alloc.a 
	./link t_array\
	../array.a ../bin.a ../alloc.a 

t_str:\
	link t_str.o\
	../str.a ../bin.a ../alloc.a 
	./link t_str\
	../str.a ../bin.a ../alloc.a 

t_dstring:\
	link t_dstring.o\
	../dstring.a ../alloc.a ../bin.a ../str.a 
	./link t_dstring\
	../dstring.a ../alloc.a ../bin.a ../str.a 

t_hashtable:\
	link t_hashtable.o\
	../hashtable.a ../uint32.a ../str.a ../bin.a ../alloc.a 
	./link t_hashtable\
	../hashtable.a ../uint32.a ../str.a ../bin.a ../alloc.a 

t_fd:\
	link t_fd.o\
	../fd.a 
	./link t_fd\
	../fd.a 

t_int:\
	link t_int.o\
	../int16.a ../int32.a ../int64.a 
	./link t_int\
	../int16.a ../int32.a ../int64.a 

t_uint:\
	link t_uint.o\
	../uint16.a ../uint32.a ../uint64.a 
	./link t_uint\
	../uint16.a ../uint32.a ../uint64.a 

t_open:\
	link t_open.o\
	../open.a 
	./link t_open\
	../open.a 

t_scan:\
	link t_scan.o\
	../scan.a 
	./link t_scan\
	../scan.a 

t_scan_float:\
	link t_scan_float.o\
	../scan_float.a 
	./link t_scan_float\
	../scan_float.a 

t_fmt:\
	link t_fmt.o\
	../fmt.a 
	./link t_fmt\
	../fmt.a 

t_scan2:\
	link t_scan2.o\
	../scan.a 
	./link t_scan2\
	../scan.a 

t_seek:\
	link t_seek.o\
	../seek.a 
	./link t_seek\
	../seek.a 

t_sstring:\
	link t_sstring.o\
	../sstring.a 
	./link t_sstring\
	../sstring.a 

t_get_opt:\
	link t_get_opt.o\
	../get_opt.a ../buffer.a ../error.a ../bin.a ../str.a 
	./link t_get_opt\
	../get_opt.a ../buffer.a ../error.a ../bin.a ../str.a 

t_dir_array:\
	link t_dir_array.o\
	../dir_array.a ../alloc.a ../bin.a ../str.a 
	./link t_dir_array\
	../dir_array.a ../alloc.a ../bin.a ../str.a 

t_sgetline:\
	link t_sgetline.o\
	../sgetline.a ../sstring.a ../buffer.a ../error.a ../bin.a \
	../str.a 
	./link t_sgetline\
	../sgetline.a ../sstring.a ../buffer.a ../error.a ../bin.a \
	../str.a 

t_stalloc:\
	link t_stalloc.o\
	../alloc.a ../stalloc.a 
	./link t_stalloc\
	../alloc.a ../stalloc.a 

t_float:\
	link t_float.o\
	../float32.a ../float64.a 
	./link t_float\
	../float32.a ../float64.a 

objects:\
	t_str.o t_alloc.o t_bin.o t_array.o t_buffer.o t_dstring.o \
	t_fd.o t_fmt.o t_uint.o t_int.o t_hashtable.o t_open.o \
	t_scan.o t_scan_float.o t_scan2.o t_seek.o t_sstring.o \
	t_get_opt.o t_stalloc.o t_dir_array.o t_sgetline.o t_float.o 

#------------------------------------------------------------------
proj_clean:
	rm -f t_alloc t_bin t_buffer t_array t_str t_dstring t_hashtable \
	t_fd t_int t_uint t_open t_scan t_scan_float t_fmt t_scan2 \
	t_seek t_sstring t_get_opt t_dir_array t_sgetline t_stalloc \
	t_float 

#------------------------------------------------------------------
local_pre: tools
local:
local_clean: tests_clean toollink_clean
local_post: list_tests run_tests

tests_clean:
	rm -f testlist

toollink_clean:
	rm -f compile link makelib config-cc config-ld shebang make-compile \
	make-link make-makelib make-targets make-makeso make-targets targets

tools: compile link makeso makelib targets
 
compile:
	ln -s ../compile compile
link:
	ln -s ../link link
makeso:
	ln -s ../makeso makeso
makelib:
	ln -s ../makelib makelib
make-targets:
	ln -s ../make-targets make-targets
targets: make-targets
	./make-targets > targets

list_tests:
	./list-tests > testlist

run_tests:
	./run-tests -v

#------------------------------------------------------------------
t_str.o:\
	compile t_str.c\
	../error.h ../str.h 
	./compile t_str.c

t_alloc.o:\
	compile t_alloc.c\
	../alloc.h 
	./compile t_alloc.c

t_bin.o:\
	compile t_bin.c\
	../bin.h 
	./compile t_bin.c

t_array.o:\
	compile t_array.c\
	../array.h 
	./compile t_array.c

t_buffer.o:\
	compile t_buffer.c\
	../buffer.h 
	./compile t_buffer.c

t_dstring.o:\
	compile t_dstring.c\
	../dstring.h 
	./compile t_dstring.c

t_fd.o:\
	compile t_fd.c\
	../fd.h 
	./compile t_fd.c

t_fmt.o:\
	compile t_fmt.c\
	../fmt.h 
	./compile t_fmt.c

t_uint.o:\
	compile t_uint.c\
	../uint16.h ../uint32.h ../uint64.h 
	./compile t_uint.c

t_int.o:\
	compile t_int.c\
	../int16.h ../int32.h ../int64.h 
	./compile t_int.c

t_hashtable.o:\
	compile t_hashtable.c\
	../hashtable.h 
	./compile t_hashtable.c

t_open.o:\
	compile t_open.c\
	../open.h 
	./compile t_open.c

t_scan.o:\
	compile t_scan.c\
	../scan.h ../uint32.h ../uint64.h 
	./compile t_scan.c

t_scan_float.o:\
	compile t_scan_float.c\
	../scan_float.h ../int32.h ../int64.h ../float32.h \
	../float64.h 
	./compile t_scan_float.c

t_scan2.o:\
	compile t_scan2.c\
	../scan.h 
	./compile t_scan2.c

t_seek.o:\
	compile t_seek.c\
	../seek.h ../int64.h 
	./compile t_seek.c

t_sstring.o:\
	compile t_sstring.c\
	../sstring.h 
	./compile t_sstring.c

t_get_opt.o:\
	compile t_get_opt.c\
	../get_opt.h 
	./compile t_get_opt.c

t_stalloc.o:\
	compile t_stalloc.c\
	../alloc.h ../stalloc.h 
	./compile t_stalloc.c

t_dir_array.o:\
	compile t_dir_array.c\
	../dir_array.h 
	./compile t_dir_array.c

t_sgetline.o:\
	compile t_sgetline.c\
	../buffer.h ../read.h ../sgetline.h 
	./compile t_sgetline.c

t_float.o:\
	compile t_float.c\
	../float32.h ../float64.h 
	./compile t_float.c

#------------------------------------------------------------------
clean: main_clean proj_clean local_clean
main_clean:
	cat targets | xargs rm -f
	rm -f compile link makelib targets makeso\
	      
regen:
	cpj-genmk -s -t > Makefile.tmp
	mv Makefile.tmp Makefile
#------------------------------------------------------------------

