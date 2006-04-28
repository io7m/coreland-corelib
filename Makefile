# $Id: Makefile,v 1.29 2006/04/22 14:15:56 mzero Exp $
# auto generated - do not edit

SHELL=/bin/sh
default: all
all:\
  local_pre\
  sysdeps\
  compile link makelib makeso local \
  targets objects dlibs slibs execs local_post 

dlibs:\
	

slibs:\
	alloc.a bin.a array.a buffer.a error.a closeonexec.a dstring.a \
	str.a fmt.a fd.a hashtable.a uint64.a uint32.a uint16.a \
	int64.a int32.a int16.a nonblock.a open.a scan.a float32.a \
	float64.a scan_float.a seek.a sstring.a get_opt.a sgetline.a \
	stalloc.a syserr.a dir_array.a 

execs:\
	

alloc.a:\
	makelib\
	alloc.o 
	./makelib alloc\
	alloc.o 

bin.a:\
	makelib\
	bin_chr.o bin_copy.o bin_copyr.o bin_count.o bin_diff.o \
	bin_rchr.o bin_set.o bin_tolower.o bin_toupper.o bin_zero.o 
	./makelib bin\
	bin_chr.o bin_copy.o bin_copyr.o bin_count.o bin_diff.o \
	bin_rchr.o bin_set.o bin_tolower.o bin_toupper.o bin_zero.o 

array.a:\
	makelib\
	array.o array_bytes.o array_cat.o array_copy.o array_index.o \
	array_size.o array_trunc.o 
	./makelib array\
	array.o array_bytes.o array_cat.o array_copy.o array_index.o \
	array_size.o array_trunc.o 

buffer.a:\
	makelib\
	buffer0.o buffer1.o buffer2.o buffer_get.o buffer_init.o \
	buffer_put.o 
	./makelib buffer\
	buffer0.o buffer1.o buffer2.o buffer_get.o buffer_init.o \
	buffer_put.o 

error.a:\
	makelib\
	error.o error_str.o 
	./makelib error\
	error.o error_str.o 

closeonexec.a:\
	makelib\
	closeonexec.o 
	./makelib closeonexec\
	closeonexec.o 

dstring.a:\
	makelib\
	dstring_cpyb.o dstring_cpys.o dstring_copy.o dstring_cat.o \
	dstring_catb.o dstring_cats.o dstring_cat0.o dstring_0.o \
	dstring_chop.o dstring_init.o dstring_trunc.o 
	./makelib dstring\
	dstring_cpyb.o dstring_cpys.o dstring_copy.o dstring_cat.o \
	dstring_catb.o dstring_cats.o dstring_cat0.o dstring_0.o \
	dstring_chop.o dstring_init.o dstring_trunc.o 

str.a:\
	makelib\
	str_chr.o str_copy.o str_diff.o str_dup.o str_ends.o \
	str_len.o str_ncopy.o str_rchr.o str_starts.o str_tolower.o \
	str_toupper.o 
	./makelib str\
	str_chr.o str_copy.o str_diff.o str_dup.o str_ends.o \
	str_len.o str_ncopy.o str_rchr.o str_starts.o str_tolower.o \
	str_toupper.o 

fmt.a:\
	makelib\
	fmt_byte.o fmt_byteo.o fmt_bytex.o fmt_u32.o fmt_u32o.o \
	fmt_u32x.o fmt_u64.o fmt_u64o.o fmt_u64x.o 
	./makelib fmt\
	fmt_byte.o fmt_byteo.o fmt_bytex.o fmt_u32.o fmt_u32o.o \
	fmt_u32x.o fmt_u64.o fmt_u64o.o fmt_u64x.o 

fd.a:\
	makelib\
	fd_dup.o fd_move.o fd_reset.o 
	./makelib fd\
	fd_dup.o fd_move.o fd_reset.o 

hashtable.a:\
	makelib\
	ht_addb.o ht_adds.o ht_addu32.o ht_bytes.o ht_deleteb.o \
	ht_deletes.o ht_destroy.o ht_getb.o ht_gets.o ht_getu32.o \
	ht_hash.o ht_init.o ht_replaceb.o ht_replaces.o 
	./makelib hashtable\
	ht_addb.o ht_adds.o ht_addu32.o ht_bytes.o ht_deleteb.o \
	ht_deletes.o ht_destroy.o ht_getb.o ht_gets.o ht_getu32.o \
	ht_hash.o ht_init.o ht_replaceb.o ht_replaces.o 

uint64.a:\
	makelib\
	uint64_pack.o uint64_unpack.o 
	./makelib uint64\
	uint64_pack.o uint64_unpack.o 

uint32.a:\
	makelib\
	uint32_pack.o uint32_unpack.o 
	./makelib uint32\
	uint32_pack.o uint32_unpack.o 

uint16.a:\
	makelib\
	uint16_pack.o uint16_unpack.o 
	./makelib uint16\
	uint16_pack.o uint16_unpack.o 

int64.a:\
	makelib\
	int64_pack.o int64_unpack.o 
	./makelib int64\
	int64_pack.o int64_unpack.o 

int32.a:\
	makelib\
	int32_pack.o int32_unpack.o 
	./makelib int32\
	int32_pack.o int32_unpack.o 

int16.a:\
	makelib\
	int16_pack.o int16_unpack.o 
	./makelib int16\
	int16_pack.o int16_unpack.o 

nonblock.a:\
	makelib\
	nonblock.o 
	./makelib nonblock\
	nonblock.o 

open.a:\
	makelib\
	open_append.o open_creat.o open_excl.o open_ro.o open_rw.o \
	open_trunc.o open_wo.o 
	./makelib open\
	open_append.o open_creat.o open_excl.o open_ro.o open_rw.o \
	open_trunc.o open_wo.o 

scan.a:\
	makelib\
	scan_chars.o scan_newline.o scan_space.o scan_u32.o \
	scan_u32o.o scan_u32x.o scan_u64.o scan_u64o.o scan_u64x.o \
	scan_float.o scan_double.o 
	./makelib scan\
	scan_chars.o scan_newline.o scan_space.o scan_u32.o \
	scan_u32o.o scan_u32x.o scan_u64.o scan_u64o.o scan_u64x.o \
	scan_float.o scan_double.o 

float32.a:\
	makelib\
	float32_pack.o float32_upack.o 
	./makelib float32\
	float32_pack.o float32_upack.o 

float64.a:\
	makelib\
	float64_pack.o float64_upack.o 
	./makelib float64\
	float64_pack.o float64_upack.o 

scan_float.a:\
	makelib\
	scan_f32.o scan_f64.o 
	./makelib scan_float\
	scan_f32.o scan_f64.o 

seek.a:\
	makelib\
	seek_cur.o seek_end.o seek_pos.o seek_start.o 
	./makelib seek\
	seek_cur.o seek_end.o seek_pos.o seek_start.o 

sstring.a:\
	makelib\
	sstring_0.o sstring_cat.o sstring_catb.o sstring_cats.o \
	sstring_copy.o sstring_cpyb.o sstring_cpys.o sstring_init.o \
	sstring_trunc.o sstring_chop.o 
	./makelib sstring\
	sstring_0.o sstring_cat.o sstring_catb.o sstring_cats.o \
	sstring_copy.o sstring_cpyb.o sstring_cpys.o sstring_init.o \
	sstring_trunc.o sstring_chop.o 

get_opt.a:\
	makelib\
	get_opt.o 
	./makelib get_opt\
	get_opt.o 

sgetline.a:\
	makelib\
	sgetline.o sgetline_chop.o sgetline_get.o 
	./makelib sgetline\
	sgetline.o sgetline_chop.o sgetline_get.o 

stalloc.a:\
	makelib\
	stalloc.o 
	./makelib stalloc\
	stalloc.o 

syserr.a:\
	makelib\
	syserr_die.o syserr_init.o 
	./makelib syserr\
	syserr_die.o syserr_init.o 

dir_array.a:\
	makelib\
	dir_array.o 
	./makelib dir_array\
	dir_array.o 

objects:\
	alloc.o array_data.o bin_toupper.o bin_tolower.o bin_set.o \
	bin_rchr.o bin_diff.o bin_count.o bin_copyr.o bin_copy.o \
	bin_chr.o bin_zero.o array_bytes.o array_index.o array_cat.o \
	array_size.o array.o buffer_init.o buffer_get.o buffer2.o \
	buffer1.o buffer0.o buffer_put.o error_str.o error.o \
	closeonexec.o dstring_init.o dstring_cpys.o dstring_cpyb.o \
	dstring_copy.o dstring_cats.o dstring_catb.o dstring_cat.o \
	dstring_0.o dstring_trunc.o array_trunc.o dstring_chop.o \
	fmt_u64x.o fmt_u64o.o fmt_u64.o fmt_u32x.o fmt_u32o.o \
	fmt_u32.o fmt_byte.o fmt_bytex.o str_len.o str_rchr.o \
	str_ends.o str_dup.o str_diff.o str_chr.o fmt_byteo.o \
	fd_reset.o fd_move.o fd_dup.o str_starts.o str_copy.o \
	str_ncopy.o str_toupper.o str_tolower.o array_copy.o ht_addb.o \
	ht_replaceb.o ht_init.o ht_hash.o ht_getu32.o ht_gets.o \
	ht_getb.o ht_destroy.o ht_deletes.o ht_deleteb.o ht_bytes.o \
	ht_addu32.o ht_adds.o ht_replaces.o uint64_pack.o \
	uint32_pack.o uint16_pack.o uint64_unpack.o uint32_unpack.o \
	uint16_unpack.o int64_unpack.o int64_pack.o int32_unpack.o \
	int32_pack.o int16_unpack.o int16_pack.o nonblock.o \
	open_trunc.o open_rw.o open_ro.o open_excl.o open_creat.o \
	open_append.o open_wo.o scan_u64o.o scan_u64.o scan_u32x.o \
	scan_u32o.o scan_u32.o scan_space.o scan_newline.o \
	scan_chars.o scan_u64x.o float32_upack.o float32_pack.o \
	float64_pack.o float64_upack.o scan_float.o scan_double.o \
	seek_start.o seek_pos.o seek_end.o seek_cur.o sstring_init.o \
	sstring_cpys.o sstring_cpyb.o sstring_copy.o sstring_chop.o \
	sstring_cats.o sstring_catb.o sstring_cat.o sstring_0.o \
	sstring_trunc.o get_opt.o sgetline.o sgetline_get.o \
	sgetline_chop.o stalloc.o dstring_cat0.o syserr_die.o \
	syserr_init.o scan_f32.o scan_f64.o dir_array.o 

#------------------------------------------------------------------
proj_clean:
	rm -f 

#------------------------------------------------------------------
local_pre:
local:
local_post:
local_clean: tests_clean

tests_clean:
	(cd UNIT_TESTS; make clean)

tests:
	(cd UNIT_TESTS; make)

#------------------------------------------------------------------
alloc.o:\
	compile alloc.c\
	alloc.h 
	./compile alloc.c

array_data.o:\
	compile array_data.c\
	array.h 
	./compile array_data.c

bin_toupper.o:\
	compile bin_toupper.c\
	bin.h 
	./compile bin_toupper.c

bin_tolower.o:\
	compile bin_tolower.c\
	bin.h 
	./compile bin_tolower.c

bin_set.o:\
	compile bin_set.c\
	bin.h 
	./compile bin_set.c

bin_rchr.o:\
	compile bin_rchr.c\
	bin.h 
	./compile bin_rchr.c

bin_diff.o:\
	compile bin_diff.c\
	bin.h 
	./compile bin_diff.c

bin_count.o:\
	compile bin_count.c\
	bin.h 
	./compile bin_count.c

bin_copyr.o:\
	compile bin_copyr.c\
	bin.h 
	./compile bin_copyr.c

bin_copy.o:\
	compile bin_copy.c\
	bin.h 
	./compile bin_copy.c

bin_chr.o:\
	compile bin_chr.c\
	bin.h 
	./compile bin_chr.c

bin_zero.o:\
	compile bin_zero.c\
	bin.h 
	./compile bin_zero.c

array_bytes.o:\
	compile array_bytes.c\
	alloc.h array.h bin.h uint32.h uint64.h 
	./compile array_bytes.c

array_index.o:\
	compile array_index.c\
	alloc.h array.h bin.h uint32.h uint64.h 
	./compile array_index.c

array_cat.o:\
	compile array_cat.c\
	alloc.h array.h bin.h uint32.h uint64.h 
	./compile array_cat.c

array_size.o:\
	compile array_size.c\
	alloc.h array.h bin.h uint32.h uint64.h 
	./compile array_size.c

array.o:\
	compile array.c\
	alloc.h array.h bin.h uint32.h uint64.h 
	./compile array.c

buffer_init.o:\
	compile buffer_init.c\
	buffer.h uint32.h 
	./compile buffer_init.c

buffer_get.o:\
	compile buffer_get.c\
	bin.h buffer.h error.h uint32.h 
	./compile buffer_get.c

buffer2.o:\
	compile buffer2.c\
	buffer.h write.h 
	./compile buffer2.c

buffer1.o:\
	compile buffer1.c\
	buffer.h write.h 
	./compile buffer1.c

buffer0.o:\
	compile buffer0.c\
	buffer.h read.h 
	./compile buffer0.c

buffer_put.o:\
	compile buffer_put.c\
	bin.h buffer.h error.h str.h uint32.h 
	./compile buffer_put.c

error_str.o:\
	compile error_str.c\
	error.h 
	./compile error_str.c

error.o:\
	compile error.c\
	error.h 
	./compile error.c

closeonexec.o:\
	compile closeonexec.c\
	closeonexec.h 
	./compile closeonexec.c

dstring_init.o:\
	compile dstring_init.c\
	alloc.h dstring.h 
	./compile dstring_init.c

dstring_cpys.o:\
	compile dstring_cpys.c\
	dstring.h str.h 
	./compile dstring_cpys.c

dstring_cpyb.o:\
	compile dstring_cpyb.c\
	alloc.h bin.h dstring.h 
	./compile dstring_cpyb.c

dstring_copy.o:\
	compile dstring_copy.c\
	dstring.h 
	./compile dstring_copy.c

dstring_cats.o:\
	compile dstring_cats.c\
	alloc.h bin.h dstring.h str.h 
	./compile dstring_cats.c

dstring_catb.o:\
	compile dstring_catb.c\
	alloc.h bin.h dstring.h 
	./compile dstring_catb.c

dstring_cat.o:\
	compile dstring_cat.c\
	dstring.h 
	./compile dstring_cat.c

dstring_0.o:\
	compile dstring_0.c\
	dstring.h 
	./compile dstring_0.c

dstring_trunc.o:\
	compile dstring_trunc.c\
	dstring.h 
	./compile dstring_trunc.c

array_trunc.o:\
	compile array_trunc.c\
	alloc.h array.h bin.h uint32.h uint64.h 
	./compile array_trunc.c

dstring_chop.o:\
	compile dstring_chop.c\
	dstring.h 
	./compile dstring_chop.c

fmt_u64x.o:\
	compile fmt_u64x.c\
	fmt.h uint64.h 
	./compile fmt_u64x.c

fmt_u64o.o:\
	compile fmt_u64o.c\
	fmt.h uint64.h 
	./compile fmt_u64o.c

fmt_u64.o:\
	compile fmt_u64.c\
	fmt.h uint64.h 
	./compile fmt_u64.c

fmt_u32x.o:\
	compile fmt_u32x.c\
	fmt.h 
	./compile fmt_u32x.c

fmt_u32o.o:\
	compile fmt_u32o.c\
	fmt.h 
	./compile fmt_u32o.c

fmt_u32.o:\
	compile fmt_u32.c\
	fmt.h 
	./compile fmt_u32.c

fmt_byte.o:\
	compile fmt_byte.c\
	fmt.h 
	./compile fmt_byte.c

fmt_bytex.o:\
	compile fmt_bytex.c\
	fmt.h 
	./compile fmt_bytex.c

str_len.o:\
	compile str_len.c\
	str.h 
	./compile str_len.c

str_rchr.o:\
	compile str_rchr.c\
	str.h 
	./compile str_rchr.c

str_ends.o:\
	compile str_ends.c\
	str.h 
	./compile str_ends.c

str_dup.o:\
	compile str_dup.c\
	alloc.h bin.h str.h 
	./compile str_dup.c

str_diff.o:\
	compile str_diff.c\
	str.h 
	./compile str_diff.c

str_chr.o:\
	compile str_chr.c\
	str.h 
	./compile str_chr.c

fmt_byteo.o:\
	compile fmt_byteo.c\
	fmt.h 
	./compile fmt_byteo.c

fd_reset.o:\
	compile fd_reset.c\
	fd.h 
	./compile fd_reset.c

fd_move.o:\
	compile fd_move.c\
	close.h fd.h 
	./compile fd_move.c

fd_dup.o:\
	compile fd_dup.c\
	close.h fd.h 
	./compile fd_dup.c

str_starts.o:\
	compile str_starts.c\
	str.h 
	./compile str_starts.c

str_copy.o:\
	compile str_copy.c\
	str.h 
	./compile str_copy.c

str_ncopy.o:\
	compile str_ncopy.c\
	str.h 
	./compile str_ncopy.c

str_toupper.o:\
	compile str_toupper.c\
	str.h 
	./compile str_toupper.c

str_tolower.o:\
	compile str_tolower.c\
	str.h 
	./compile str_tolower.c

array_copy.o:\
	compile array_copy.c\
	alloc.h array.h bin.h uint32.h uint64.h 
	./compile array_copy.c

ht_addb.o:\
	compile ht_addb.c\
	alloc.h bin.h hashtable.h 
	./compile ht_addb.c

ht_replaceb.o:\
	compile ht_replaceb.c\
	alloc.h bin.h hashtable.h uint32.h 
	./compile ht_replaceb.c

ht_init.o:\
	compile ht_init.c\
	hashtable.h 
	./compile ht_init.c

ht_hash.o:\
	compile ht_hash.c\
	hashtable.h 
	./compile ht_hash.c

ht_getu32.o:\
	compile ht_getu32.c\
	alloc.h bin.h hashtable.h uint32.h 
	./compile ht_getu32.c

ht_gets.o:\
	compile ht_gets.c\
	hashtable.h str.h 
	./compile ht_gets.c

ht_getb.o:\
	compile ht_getb.c\
	bin.h hashtable.h 
	./compile ht_getb.c

ht_destroy.o:\
	compile ht_destroy.c\
	alloc.h hashtable.h 
	./compile ht_destroy.c

ht_deletes.o:\
	compile ht_deletes.c\
	hashtable.h str.h 
	./compile ht_deletes.c

ht_deleteb.o:\
	compile ht_deleteb.c\
	alloc.h bin.h hashtable.h 
	./compile ht_deleteb.c

ht_bytes.o:\
	compile ht_bytes.c\
	hashtable.h uint64.h 
	./compile ht_bytes.c

ht_addu32.o:\
	compile ht_addu32.c\
	hashtable.h uint32.h 
	./compile ht_addu32.c

ht_adds.o:\
	compile ht_adds.c\
	hashtable.h str.h 
	./compile ht_adds.c

ht_replaces.o:\
	compile ht_replaces.c\
	hashtable.h str.h 
	./compile ht_replaces.c

uint64_pack.o:\
	compile uint64_pack.c\
	uint64.h 
	./compile uint64_pack.c

uint32_pack.o:\
	compile uint32_pack.c\
	uint32.h 
	./compile uint32_pack.c

uint16_pack.o:\
	compile uint16_pack.c\
	uint16.h 
	./compile uint16_pack.c

uint64_unpack.o:\
	compile uint64_unpack.c\
	uint64.h 
	./compile uint64_unpack.c

uint32_unpack.o:\
	compile uint32_unpack.c\
	uint32.h 
	./compile uint32_unpack.c

uint16_unpack.o:\
	compile uint16_unpack.c\
	uint16.h 
	./compile uint16_unpack.c

int64_unpack.o:\
	compile int64_unpack.c\
	int64.h 
	./compile int64_unpack.c

int64_pack.o:\
	compile int64_pack.c\
	int64.h 
	./compile int64_pack.c

int32_unpack.o:\
	compile int32_unpack.c\
	int32.h 
	./compile int32_unpack.c

int32_pack.o:\
	compile int32_pack.c\
	int32.h 
	./compile int32_pack.c

int16_unpack.o:\
	compile int16_unpack.c\
	int16.h 
	./compile int16_unpack.c

int16_pack.o:\
	compile int16_pack.c\
	int16.h 
	./compile int16_pack.c

nonblock.o:\
	compile nonblock.c\
	nonblock.h 
	./compile nonblock.c

open_trunc.o:\
	compile open_trunc.c\
	open.h 
	./compile open_trunc.c

open_rw.o:\
	compile open_rw.c\
	open.h 
	./compile open_rw.c

open_ro.o:\
	compile open_ro.c\
	open.h 
	./compile open_ro.c

open_excl.o:\
	compile open_excl.c\
	open.h 
	./compile open_excl.c

open_creat.o:\
	compile open_creat.c\
	open.h 
	./compile open_creat.c

open_append.o:\
	compile open_append.c\
	open.h 
	./compile open_append.c

open_wo.o:\
	compile open_wo.c\
	open.h 
	./compile open_wo.c

scan_u64o.o:\
	compile scan_u64o.c\
	scan.h uint64.h 
	./compile scan_u64o.c

scan_u64.o:\
	compile scan_u64.c\
	scan.h uint64.h 
	./compile scan_u64.c

scan_u32x.o:\
	compile scan_u32x.c\
	scan.h uint32.h 
	./compile scan_u32x.c

scan_u32o.o:\
	compile scan_u32o.c\
	scan.h uint32.h uint64.h 
	./compile scan_u32o.c

scan_u32.o:\
	compile scan_u32.c\
	scan.h uint32.h uint64.h 
	./compile scan_u32.c

scan_space.o:\
	compile scan_space.c\
	scan.h 
	./compile scan_space.c

scan_newline.o:\
	compile scan_newline.c\
	scan.h 
	./compile scan_newline.c

scan_chars.o:\
	compile scan_chars.c\
	scan.h 
	./compile scan_chars.c

scan_u64x.o:\
	compile scan_u64x.c\
	scan.h uint64.h 
	./compile scan_u64x.c

float32_upack.o:\
	compile float32_upack.c\
	endian.h float32.h 
	./compile float32_upack.c

float32_pack.o:\
	compile float32_pack.c\
	endian.h float32.h 
	./compile float32_pack.c

float64_pack.o:\
	compile float64_pack.c\
	endian.h float64.h 
	./compile float64_pack.c

float64_upack.o:\
	compile float64_upack.c\
	endian.h float64.h 
	./compile float64_upack.c

scan_float.o:\
	compile scan_float.c\
	scan.h 
	./compile scan_float.c

scan_double.o:\
	compile scan_double.c\
	scan.h 
	./compile scan_double.c

seek_start.o:\
	compile seek_start.c\
	int64.h seek.h 
	./compile seek_start.c

seek_pos.o:\
	compile seek_pos.c\
	int64.h seek.h 
	./compile seek_pos.c

seek_end.o:\
	compile seek_end.c\
	int64.h seek.h 
	./compile seek_end.c

seek_cur.o:\
	compile seek_cur.c\
	int64.h seek.h 
	./compile seek_cur.c

sstring_init.o:\
	compile sstring_init.c\
	sstring.h 
	./compile sstring_init.c

sstring_cpys.o:\
	compile sstring_cpys.c\
	sstring.h 
	./compile sstring_cpys.c

sstring_cpyb.o:\
	compile sstring_cpyb.c\
	sstring.h 
	./compile sstring_cpyb.c

sstring_copy.o:\
	compile sstring_copy.c\
	sstring.h 
	./compile sstring_copy.c

sstring_chop.o:\
	compile sstring_chop.c\
	sstring.h 
	./compile sstring_chop.c

sstring_cats.o:\
	compile sstring_cats.c\
	sstring.h 
	./compile sstring_cats.c

sstring_catb.o:\
	compile sstring_catb.c\
	sstring.h 
	./compile sstring_catb.c

sstring_cat.o:\
	compile sstring_cat.c\
	sstring.h 
	./compile sstring_cat.c

sstring_0.o:\
	compile sstring_0.c\
	sstring.h 
	./compile sstring_0.c

sstring_trunc.o:\
	compile sstring_trunc.c\
	sstring.h 
	./compile sstring_trunc.c

get_opt.o:\
	compile get_opt.c\
	buffer.h get_opt.h 
	./compile get_opt.c

sgetline.o:\
	compile sgetline.c\
	sgetline.h 
	./compile sgetline.c

sgetline_get.o:\
	compile sgetline_get.c\
	bin.h buffer.h sgetline.h sstring.h 
	./compile sgetline_get.c

sgetline_chop.o:\
	compile sgetline_chop.c\
	sgetline.h 
	./compile sgetline_chop.c

stalloc.o:\
	compile stalloc.c\
	stalloc.h 
	./compile stalloc.c

dstring_cat0.o:\
	compile dstring_cat0.c\
	dstring.h 
	./compile dstring_cat0.c

syserr_die.o:\
	compile syserr_die.c\
	buffer.h exit.h syserr.h 
	./compile syserr_die.c

syserr_init.o:\
	compile syserr_init.c\
	error.h syserr.h 
	./compile syserr_init.c

scan_f32.o:\
	compile scan_f32.c\
	scan_float.h float32.h 
	./compile scan_f32.c

scan_f64.o:\
	compile scan_f64.c\
	scan_float.h float64.h 
	./compile scan_f64.c

dir_array.o:\
	compile dir_array.c\
	alloc.h bin.h dir_array.h direntry.h str.h 
	./compile dir_array.c

#------------------------------------------------------------------
compile: config-cc shebang make-compile
	(cat shebang; ./make-compile) > compile; chmod u+x compile;
link: config-ld shebang make-link
	(cat shebang; ./make-link) > link; chmod u+x link;
makelib: shebang make-makelib
	(cat shebang; ./make-makelib) > makelib; chmod u+x makelib;
makeso: shebang make-makeso
	(cat shebang; ./make-makeso) > makeso; chmod u+x makeso
targets:
	./make-targets > targets
#------------------------------------------------------------------
clean: sysdeps_clean main_clean proj_clean local_clean
main_clean:
	cat targets | xargs rm -f
	rm -f compile link makelib targets makeso\
	      
regen:
	cpj-genmk > Makefile.tmp
	mv Makefile.tmp Makefile
#------------------------------------------------------------------
sysdeps: sysdeps.out
sysdeps_clean: sysdep_clean
sysdep_dir=SYSDEPS
sysdep_out=sysdeps.out
sysdeps.out:
	${sysdep_dir}/sysdep_header >>${sysdep_out}
	( cd ${sysdep_dir} && make )
sysdep_clean:
	( cd ${sysdep_dir} && make clean )
	rm -f ${sysdep_out}

