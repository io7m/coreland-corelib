# auto generated - do not edit
# cpj-genmk-0.70

SHELL=/bin/sh
default: all
all: phase_sysdeps phase_tools phase_compile phase_library \
	phase_link 

tests: phase_test 

clean: phase_sysdeps_clean phase_tools_clean phase_compile_clean \
	phase_library_clean phase_link_clean phase_test_clean 


#--SYSDEPS--------------------------------------------------------------------

phase_sysdeps: sysdeps
phase_sysdeps_clean: sysdeps_clean

#--TOOLS----------------------------------------------------------------------

phase_tools:  mkftools
phase_tools_clean:  mkftools_clean

#--COMPILE--------------------------------------------------------------------

alloc.o:\
	compile alloc.c alloc.h 
	./compile alloc alloc.c 
array.o:\
	compile array.c alloc.h array.h bin.h uint32.h uint64.h 
	./compile array array.c 
array_bytes.o:\
	compile array_bytes.c alloc.h array.h bin.h uint32.h uint64.h 
	./compile array_bytes array_bytes.c 
array_cat.o:\
	compile array_cat.c alloc.h array.h bin.h uint32.h uint64.h 
	./compile array_cat array_cat.c 
array_chop.o:\
	compile array_chop.c alloc.h array.h bin.h uint32.h uint64.h 
	./compile array_chop array_chop.c 
array_copy.o:\
	compile array_copy.c alloc.h array.h bin.h uint32.h uint64.h 
	./compile array_copy array_copy.c 
array_data.o:\
	compile array_data.c array.h 
	./compile array_data array_data.c 
array_index.o:\
	compile array_index.c alloc.h array.h bin.h uint32.h uint64.h 
	./compile array_index array_index.c 
array_size.o:\
	compile array_size.c alloc.h array.h bin.h uint32.h uint64.h 
	./compile array_size array_size.c 
base_name.o:\
	compile base_name.c bin.h base_name.h str.h 
	./compile base_name base_name.c 
bin_chr.o:\
	compile bin_chr.c bin.h 
	./compile bin_chr bin_chr.c 
bin_copy.o:\
	compile bin_copy.c bin.h 
	./compile bin_copy bin_copy.c 
bin_copyr.o:\
	compile bin_copyr.c bin.h 
	./compile bin_copyr bin_copyr.c 
bin_count.o:\
	compile bin_count.c bin.h 
	./compile bin_count bin_count.c 
bin_diff.o:\
	compile bin_diff.c bin.h 
	./compile bin_diff bin_diff.c 
bin_rchr.o:\
	compile bin_rchr.c bin.h 
	./compile bin_rchr bin_rchr.c 
bin_set.o:\
	compile bin_set.c bin.h 
	./compile bin_set bin_set.c 
bin_tolower.o:\
	compile bin_tolower.c bin.h 
	./compile bin_tolower bin_tolower.c 
bin_toupper.o:\
	compile bin_toupper.c bin.h 
	./compile bin_toupper bin_toupper.c 
bin_zero.o:\
	compile bin_zero.c bin.h 
	./compile bin_zero bin_zero.c 
buffer0.o:\
	compile buffer0.c buffer.h read.h 
	./compile buffer0 buffer0.c 
buffer1.o:\
	compile buffer1.c buffer.h write.h 
	./compile buffer1 buffer1.c 
buffer2.o:\
	compile buffer2.c buffer.h write.h 
	./compile buffer2 buffer2.c 
buffer_copy.o:\
	compile buffer_copy.c buffer.h 
	./compile buffer_copy buffer_copy.c 
buffer_get.o:\
	compile buffer_get.c bin.h buffer.h error.h 
	./compile buffer_get buffer_get.c 
buffer_init.o:\
	compile buffer_init.c buffer.h 
	./compile buffer_init buffer_init.c 
buffer_put.o:\
	compile buffer_put.c bin.h buffer.h error.h str.h 
	./compile buffer_put buffer_put.c 
closeonexec.o:\
	compile closeonexec.c closeonexec.h 
	./compile closeonexec closeonexec.c 
dir_array.o:\
	compile dir_array.c alloc.h bin.h dir_array.h direntry.h str.h 
	./compile dir_array dir_array.c 
dir_hash.o:\
	compile dir_hash.c alloc.h bin.h dir_array.h dir_hash.h str.h 
	./compile dir_hash dir_hash.c 
dir_name.o:\
	compile dir_name.c bin.h dir_name.h str.h 
	./compile dir_name dir_name.c 
dstring_0.o:\
	compile dstring_0.c dstring.h 
	./compile dstring_0 dstring_0.c 
dstring_cat.o:\
	compile dstring_cat.c dstring.h 
	./compile dstring_cat dstring_cat.c 
dstring_cat0.o:\
	compile dstring_cat0.c dstring.h 
	./compile dstring_cat0 dstring_cat0.c 
dstring_catb.o:\
	compile dstring_catb.c alloc.h bin.h dstring.h 
	./compile dstring_catb dstring_catb.c 
dstring_cats.o:\
	compile dstring_cats.c alloc.h bin.h dstring.h str.h 
	./compile dstring_cats dstring_cats.c 
dstring_chop.o:\
	compile dstring_chop.c dstring.h 
	./compile dstring_chop dstring_chop.c 
dstring_copy.o:\
	compile dstring_copy.c dstring.h 
	./compile dstring_copy dstring_copy.c 
dstring_cpyb.o:\
	compile dstring_cpyb.c alloc.h bin.h dstring.h 
	./compile dstring_cpyb dstring_cpyb.c 
dstring_cpys.o:\
	compile dstring_cpys.c dstring.h str.h 
	./compile dstring_cpys dstring_cpys.c 
dstring_init.o:\
	compile dstring_init.c alloc.h dstring.h 
	./compile dstring_init dstring_init.c 
dstring_trunc.o:\
	compile dstring_trunc.c dstring.h 
	./compile dstring_trunc dstring_trunc.c 
error.o:\
	compile error.c error.h 
	./compile error error.c 
error_str.o:\
	compile error_str.c error.h 
	./compile error_str error_str.c 
fd_dup.o:\
	compile fd_dup.c close.h fd.h 
	./compile fd_dup fd_dup.c 
fd_move.o:\
	compile fd_move.c close.h fd.h 
	./compile fd_move fd_move.c 
fd_reset.o:\
	compile fd_reset.c fd.h 
	./compile fd_reset fd_reset.c 
float32_pack.o:\
	compile float32_pack.c endian.h float32.h 
	./compile float32_pack float32_pack.c 
float32_upack.o:\
	compile float32_upack.c endian.h float32.h 
	./compile float32_upack float32_upack.c 
float64_pack.o:\
	compile float64_pack.c endian.h float64.h 
	./compile float64_pack float64_pack.c 
float64_upack.o:\
	compile float64_upack.c endian.h float64.h 
	./compile float64_upack float64_upack.c 
fmt_byte.o:\
	compile fmt_byte.c fmt.h 
	./compile fmt_byte fmt_byte.c 
fmt_byteo.o:\
	compile fmt_byteo.c fmt.h 
	./compile fmt_byteo fmt_byteo.c 
fmt_bytex.o:\
	compile fmt_bytex.c fmt.h 
	./compile fmt_bytex fmt_bytex.c 
fmt_u32.o:\
	compile fmt_u32.c fmt.h 
	./compile fmt_u32 fmt_u32.c 
fmt_u32o.o:\
	compile fmt_u32o.c fmt.h 
	./compile fmt_u32o fmt_u32o.c 
fmt_u32x.o:\
	compile fmt_u32x.c fmt.h 
	./compile fmt_u32x fmt_u32x.c 
fmt_u64.o:\
	compile fmt_u64.c fmt.h uint64.h 
	./compile fmt_u64 fmt_u64.c 
fmt_u64o.o:\
	compile fmt_u64o.c fmt.h uint64.h 
	./compile fmt_u64o fmt_u64o.c 
fmt_u64x.o:\
	compile fmt_u64x.c fmt.h uint64.h 
	./compile fmt_u64x fmt_u64x.c 
get_opt.o:\
	compile get_opt.c buffer.h get_opt.h 
	./compile get_opt get_opt.c 
ht_addb.o:\
	compile ht_addb.c alloc.h bin.h hashtable.h 
	./compile ht_addb ht_addb.c 
ht_adds.o:\
	compile ht_adds.c hashtable.h str.h 
	./compile ht_adds ht_adds.c 
ht_addu32.o:\
	compile ht_addu32.c hashtable.h uint32.h 
	./compile ht_addu32 ht_addu32.c 
ht_bytes.o:\
	compile ht_bytes.c hashtable.h uint64.h 
	./compile ht_bytes ht_bytes.c 
ht_deleteb.o:\
	compile ht_deleteb.c alloc.h bin.h hashtable.h 
	./compile ht_deleteb ht_deleteb.c 
ht_deletes.o:\
	compile ht_deletes.c hashtable.h str.h 
	./compile ht_deletes ht_deletes.c 
ht_destroy.o:\
	compile ht_destroy.c alloc.h hashtable.h 
	./compile ht_destroy ht_destroy.c 
ht_getb.o:\
	compile ht_getb.c bin.h hashtable.h 
	./compile ht_getb ht_getb.c 
ht_gets.o:\
	compile ht_gets.c hashtable.h str.h 
	./compile ht_gets ht_gets.c 
ht_getu32.o:\
	compile ht_getu32.c alloc.h bin.h hashtable.h uint32.h 
	./compile ht_getu32 ht_getu32.c 
ht_hash.o:\
	compile ht_hash.c hashtable.h 
	./compile ht_hash ht_hash.c 
ht_init.o:\
	compile ht_init.c hashtable.h 
	./compile ht_init ht_init.c 
ht_replaceb.o:\
	compile ht_replaceb.c alloc.h bin.h hashtable.h uint32.h 
	./compile ht_replaceb ht_replaceb.c 
ht_replaces.o:\
	compile ht_replaces.c hashtable.h str.h 
	./compile ht_replaces ht_replaces.c 
int16_pack.o:\
	compile int16_pack.c int16.h 
	./compile int16_pack int16_pack.c 
int16_unpack.o:\
	compile int16_unpack.c int16.h 
	./compile int16_unpack int16_unpack.c 
int32_pack.o:\
	compile int32_pack.c int32.h 
	./compile int32_pack int32_pack.c 
int32_unpack.o:\
	compile int32_unpack.c int32.h 
	./compile int32_unpack int32_unpack.c 
int64_pack.o:\
	compile int64_pack.c int64.h 
	./compile int64_pack int64_pack.c 
int64_unpack.o:\
	compile int64_unpack.c int64.h 
	./compile int64_unpack int64_unpack.c 
nonblock.o:\
	compile nonblock.c nonblock.h 
	./compile nonblock nonblock.c 
open_append.o:\
	compile open_append.c open.h 
	./compile open_append open_append.c 
open_creat.o:\
	compile open_creat.c open.h 
	./compile open_creat open_creat.c 
open_excl.o:\
	compile open_excl.c open.h 
	./compile open_excl open_excl.c 
open_ro.o:\
	compile open_ro.c open.h 
	./compile open_ro open_ro.c 
open_rw.o:\
	compile open_rw.c open.h 
	./compile open_rw open_rw.c 
open_trunc.o:\
	compile open_trunc.c open.h 
	./compile open_trunc open_trunc.c 
open_wo.o:\
	compile open_wo.c open.h 
	./compile open_wo open_wo.c 
scan_chars.o:\
	compile scan_chars.c scan.h 
	./compile scan_chars scan_chars.c 
scan_double.o:\
	compile scan_double.c scan.h 
	./compile scan_double scan_double.c 
scan_f32.o:\
	compile scan_f32.c scan_float.h float32.h 
	./compile scan_f32 scan_f32.c 
scan_f64.o:\
	compile scan_f64.c scan_float.h float64.h 
	./compile scan_f64 scan_f64.c 
scan_float.o:\
	compile scan_float.c scan.h 
	./compile scan_float scan_float.c 
scan_newline.o:\
	compile scan_newline.c scan.h 
	./compile scan_newline scan_newline.c 
scan_space.o:\
	compile scan_space.c scan.h 
	./compile scan_space scan_space.c 
scan_u32.o:\
	compile scan_u32.c scan.h uint32.h uint64.h 
	./compile scan_u32 scan_u32.c 
scan_u32o.o:\
	compile scan_u32o.c scan.h uint32.h uint64.h 
	./compile scan_u32o scan_u32o.c 
scan_u32x.o:\
	compile scan_u32x.c scan.h uint32.h 
	./compile scan_u32x scan_u32x.c 
scan_u64.o:\
	compile scan_u64.c scan.h uint64.h 
	./compile scan_u64 scan_u64.c 
scan_u64o.o:\
	compile scan_u64o.c scan.h uint64.h 
	./compile scan_u64o scan_u64o.c 
scan_u64x.o:\
	compile scan_u64x.c scan.h uint64.h 
	./compile scan_u64x scan_u64x.c 
seek_cur.o:\
	compile seek_cur.c int64.h seek.h 
	./compile seek_cur seek_cur.c 
seek_end.o:\
	compile seek_end.c int64.h seek.h 
	./compile seek_end seek_end.c 
seek_pos.o:\
	compile seek_pos.c int64.h seek.h 
	./compile seek_pos seek_pos.c 
seek_start.o:\
	compile seek_start.c int64.h seek.h 
	./compile seek_start seek_start.c 
sgetline.o:\
	compile sgetline.c sgetline.h 
	./compile sgetline sgetline.c 
sgetline_chop.o:\
	compile sgetline_chop.c sgetline.h 
	./compile sgetline_chop sgetline_chop.c 
sgetline_get.o:\
	compile sgetline_get.c bin.h buffer.h sgetline.h sstring.h 
	./compile sgetline_get sgetline_get.c 
sstring_0.o:\
	compile sstring_0.c sstring.h 
	./compile sstring_0 sstring_0.c 
sstring_cat.o:\
	compile sstring_cat.c sstring.h 
	./compile sstring_cat sstring_cat.c 
sstring_catb.o:\
	compile sstring_catb.c sstring.h 
	./compile sstring_catb sstring_catb.c 
sstring_cats.o:\
	compile sstring_cats.c sstring.h 
	./compile sstring_cats sstring_cats.c 
sstring_chop.o:\
	compile sstring_chop.c sstring.h 
	./compile sstring_chop sstring_chop.c 
sstring_copy.o:\
	compile sstring_copy.c sstring.h 
	./compile sstring_copy sstring_copy.c 
sstring_cpyb.o:\
	compile sstring_cpyb.c sstring.h 
	./compile sstring_cpyb sstring_cpyb.c 
sstring_cpys.o:\
	compile sstring_cpys.c sstring.h 
	./compile sstring_cpys sstring_cpys.c 
sstring_init.o:\
	compile sstring_init.c sstring.h 
	./compile sstring_init sstring_init.c 
sstring_trunc.o:\
	compile sstring_trunc.c sstring.h 
	./compile sstring_trunc sstring_trunc.c 
stalloc.o:\
	compile stalloc.c stalloc.h 
	./compile stalloc stalloc.c 
str_chr.o:\
	compile str_chr.c str.h 
	./compile str_chr str_chr.c 
str_copy.o:\
	compile str_copy.c str.h 
	./compile str_copy str_copy.c 
str_diff.o:\
	compile str_diff.c str.h 
	./compile str_diff str_diff.c 
str_dup.o:\
	compile str_dup.c alloc.h bin.h str.h 
	./compile str_dup str_dup.c 
str_ends.o:\
	compile str_ends.c str.h 
	./compile str_ends str_ends.c 
str_len.o:\
	compile str_len.c str.h 
	./compile str_len str_len.c 
str_ncopy.o:\
	compile str_ncopy.c str.h 
	./compile str_ncopy str_ncopy.c 
str_rchr.o:\
	compile str_rchr.c str.h 
	./compile str_rchr str_rchr.c 
str_starts.o:\
	compile str_starts.c str.h 
	./compile str_starts str_starts.c 
str_tolower.o:\
	compile str_tolower.c str.h 
	./compile str_tolower str_tolower.c 
str_toupper.o:\
	compile str_toupper.c str.h 
	./compile str_toupper str_toupper.c 
syserr_die.o:\
	compile syserr_die.c buffer.h exit.h syserr.h 
	./compile syserr_die syserr_die.c 
syserr_init.o:\
	compile syserr_init.c error.h syserr.h 
	./compile syserr_init syserr_init.c 
uint16_pack.o:\
	compile uint16_pack.c uint16.h 
	./compile uint16_pack uint16_pack.c 
uint16_unpack.o:\
	compile uint16_unpack.c uint16.h 
	./compile uint16_unpack uint16_unpack.c 
uint32_pack.o:\
	compile uint32_pack.c uint32.h 
	./compile uint32_pack uint32_pack.c 
uint32_unpack.o:\
	compile uint32_unpack.c uint32.h 
	./compile uint32_unpack uint32_unpack.c 
uint64_pack.o:\
	compile uint64_pack.c uint64.h 
	./compile uint64_pack uint64_pack.c 
uint64_unpack.o:\
	compile uint64_unpack.c uint64.h 
	./compile uint64_unpack uint64_unpack.c 

phase_compile:\
	alloc.o array.o array_bytes.o array_cat.o array_chop.o array_copy.o \
	array_data.o array_index.o array_size.o base_name.o bin_chr.o \
	bin_copy.o bin_copyr.o bin_count.o bin_diff.o bin_rchr.o bin_set.o \
	bin_tolower.o bin_toupper.o bin_zero.o buffer0.o buffer1.o buffer2.o \
	buffer_copy.o buffer_get.o buffer_init.o buffer_put.o closeonexec.o \
	dir_array.o dir_hash.o dir_name.o dstring_0.o dstring_cat.o \
	dstring_cat0.o dstring_catb.o dstring_cats.o dstring_chop.o \
	dstring_copy.o dstring_cpyb.o dstring_cpys.o dstring_init.o \
	dstring_trunc.o error.o error_str.o fd_dup.o fd_move.o fd_reset.o \
	float32_pack.o float32_upack.o float64_pack.o float64_upack.o \
	fmt_byte.o fmt_byteo.o fmt_bytex.o fmt_u32.o fmt_u32o.o fmt_u32x.o \
	fmt_u64.o fmt_u64o.o fmt_u64x.o get_opt.o ht_addb.o ht_adds.o \
	ht_addu32.o ht_bytes.o ht_deleteb.o ht_deletes.o ht_destroy.o \
	ht_getb.o ht_gets.o ht_getu32.o ht_hash.o ht_init.o ht_replaceb.o \
	ht_replaces.o int16_pack.o int16_unpack.o int32_pack.o \
	int32_unpack.o int64_pack.o int64_unpack.o nonblock.o open_append.o \
	open_creat.o open_excl.o open_ro.o open_rw.o open_trunc.o open_wo.o \
	scan_chars.o scan_double.o scan_f32.o scan_f64.o scan_float.o \
	scan_newline.o scan_space.o scan_u32.o scan_u32o.o scan_u32x.o \
	scan_u64.o scan_u64o.o scan_u64x.o seek_cur.o seek_end.o seek_pos.o \
	seek_start.o sgetline.o sgetline_chop.o sgetline_get.o sstring_0.o \
	sstring_cat.o sstring_catb.o sstring_cats.o sstring_chop.o \
	sstring_copy.o sstring_cpyb.o sstring_cpys.o sstring_init.o \
	sstring_trunc.o stalloc.o str_chr.o str_copy.o str_diff.o str_dup.o \
	str_ends.o str_len.o str_ncopy.o str_rchr.o str_starts.o \
	str_tolower.o str_toupper.o syserr_die.o syserr_init.o uint16_pack.o \
	uint16_unpack.o uint32_pack.o uint32_unpack.o uint64_pack.o \
	uint64_unpack.o 
phase_compile_clean:
	rm -f alloc.o array.o array_bytes.o array_cat.o array_chop.o \
	array_copy.o array_data.o array_index.o array_size.o base_name.o \
	bin_chr.o bin_copy.o bin_copyr.o bin_count.o bin_diff.o bin_rchr.o \
	bin_set.o bin_tolower.o bin_toupper.o bin_zero.o buffer0.o buffer1.o \
	buffer2.o buffer_copy.o buffer_get.o buffer_init.o buffer_put.o \
	closeonexec.o dir_array.o dir_hash.o dir_name.o dstring_0.o \
	dstring_cat.o dstring_cat0.o dstring_catb.o dstring_cats.o \
	dstring_chop.o dstring_copy.o dstring_cpyb.o dstring_cpys.o \
	dstring_init.o dstring_trunc.o error.o error_str.o fd_dup.o \
	fd_move.o fd_reset.o float32_pack.o float32_upack.o float64_pack.o \
	float64_upack.o fmt_byte.o fmt_byteo.o fmt_bytex.o fmt_u32.o \
	fmt_u32o.o fmt_u32x.o fmt_u64.o fmt_u64o.o fmt_u64x.o get_opt.o \
	ht_addb.o ht_adds.o ht_addu32.o ht_bytes.o ht_deleteb.o ht_deletes.o \
	ht_destroy.o ht_getb.o ht_gets.o ht_getu32.o ht_hash.o ht_init.o \
	ht_replaceb.o ht_replaces.o int16_pack.o int16_unpack.o int32_pack.o \
	int32_unpack.o int64_pack.o int64_unpack.o nonblock.o open_append.o \
	open_creat.o open_excl.o open_ro.o open_rw.o open_trunc.o open_wo.o \
	scan_chars.o scan_double.o scan_f32.o scan_f64.o scan_float.o \
	scan_newline.o scan_space.o scan_u32.o scan_u32o.o scan_u32x.o \
	scan_u64.o scan_u64o.o scan_u64x.o seek_cur.o seek_end.o seek_pos.o \
	seek_start.o sgetline.o sgetline_chop.o sgetline_get.o sstring_0.o \
	sstring_cat.o sstring_catb.o sstring_cats.o sstring_chop.o \
	sstring_copy.o sstring_cpyb.o sstring_cpys.o sstring_init.o \
	sstring_trunc.o stalloc.o str_chr.o str_copy.o str_diff.o str_dup.o \
	str_ends.o str_len.o str_ncopy.o str_rchr.o str_starts.o \
	str_tolower.o str_toupper.o syserr_die.o syserr_init.o uint16_pack.o \
	uint16_unpack.o uint32_pack.o uint32_unpack.o uint64_pack.o \
	uint64_unpack.o 

#--LIBRARY--------------------------------------------------------------------

alloc.a:\
	makelib alloc.sld alloc.o 
	./makelib alloc alloc.o 
array.a:\
	makelib array.sld array.o array_bytes.o array_cat.o array_copy.o \
	array_index.o array_size.o array_chop.o 
	./makelib array array.o array_bytes.o array_cat.o array_copy.o \
	array_index.o array_size.o array_chop.o 
base_name.a:\
	makelib base_name.sld base_name.o 
	./makelib base_name base_name.o 
bin.a:\
	makelib bin.sld bin_chr.o bin_copy.o bin_copyr.o bin_count.o \
	bin_diff.o bin_rchr.o bin_set.o bin_tolower.o bin_toupper.o \
	bin_zero.o 
	./makelib bin bin_chr.o bin_copy.o bin_copyr.o bin_count.o \
	bin_diff.o bin_rchr.o bin_set.o bin_tolower.o bin_toupper.o \
	bin_zero.o 
buffer.a:\
	makelib buffer.sld buffer0.o buffer1.o buffer2.o buffer_get.o \
	buffer_init.o buffer_put.o buffer_copy.o 
	./makelib buffer buffer0.o buffer1.o buffer2.o buffer_get.o \
	buffer_init.o buffer_put.o buffer_copy.o 
closeonexec.a:\
	makelib closeonexec.sld closeonexec.o 
	./makelib closeonexec closeonexec.o 
dir_array.a:\
	makelib dir_array.sld dir_array.o 
	./makelib dir_array dir_array.o 
dir_hash.a:\
	makelib dir_hash.sld dir_hash.o 
	./makelib dir_hash dir_hash.o 
dir_name.a:\
	makelib dir_name.sld dir_name.o 
	./makelib dir_name dir_name.o 
dstring.a:\
	makelib dstring.sld dstring_cpyb.o dstring_cpys.o dstring_copy.o \
	dstring_cat.o dstring_catb.o dstring_cats.o dstring_cat0.o \
	dstring_0.o dstring_chop.o dstring_init.o dstring_trunc.o 
	./makelib dstring dstring_cpyb.o dstring_cpys.o dstring_copy.o \
	dstring_cat.o dstring_catb.o dstring_cats.o dstring_cat0.o \
	dstring_0.o dstring_chop.o dstring_init.o dstring_trunc.o 
error.a:\
	makelib error.sld error.o error_str.o 
	./makelib error error.o error_str.o 
fd.a:\
	makelib fd.sld fd_dup.o fd_move.o fd_reset.o 
	./makelib fd fd_dup.o fd_move.o fd_reset.o 
float32.a:\
	makelib float32.sld float32_pack.o float32_upack.o 
	./makelib float32 float32_pack.o float32_upack.o 
float64.a:\
	makelib float64.sld float64_pack.o float64_upack.o 
	./makelib float64 float64_pack.o float64_upack.o 
fmt.a:\
	makelib fmt.sld fmt_byte.o fmt_byteo.o fmt_bytex.o fmt_u32.o \
	fmt_u32o.o fmt_u32x.o fmt_u64.o fmt_u64o.o fmt_u64x.o 
	./makelib fmt fmt_byte.o fmt_byteo.o fmt_bytex.o fmt_u32.o \
	fmt_u32o.o fmt_u32x.o fmt_u64.o fmt_u64o.o fmt_u64x.o 
get_opt.a:\
	makelib get_opt.sld get_opt.o 
	./makelib get_opt get_opt.o 
hashtable.a:\
	makelib hashtable.sld ht_addb.o ht_adds.o ht_addu32.o ht_bytes.o \
	ht_deleteb.o ht_deletes.o ht_destroy.o ht_getb.o ht_gets.o \
	ht_getu32.o ht_hash.o ht_init.o ht_replaceb.o ht_replaces.o 
	./makelib hashtable ht_addb.o ht_adds.o ht_addu32.o ht_bytes.o \
	ht_deleteb.o ht_deletes.o ht_destroy.o ht_getb.o ht_gets.o \
	ht_getu32.o ht_hash.o ht_init.o ht_replaceb.o ht_replaces.o 
int16.a:\
	makelib int16.sld int16_pack.o int16_unpack.o 
	./makelib int16 int16_pack.o int16_unpack.o 
int32.a:\
	makelib int32.sld int32_pack.o int32_unpack.o 
	./makelib int32 int32_pack.o int32_unpack.o 
int64.a:\
	makelib int64.sld int64_pack.o int64_unpack.o 
	./makelib int64 int64_pack.o int64_unpack.o 
nonblock.a:\
	makelib nonblock.sld nonblock.o 
	./makelib nonblock nonblock.o 
open.a:\
	makelib open.sld open_append.o open_creat.o open_excl.o open_ro.o \
	open_rw.o open_trunc.o open_wo.o 
	./makelib open open_append.o open_creat.o open_excl.o open_ro.o \
	open_rw.o open_trunc.o open_wo.o 
scan.a:\
	makelib scan.sld scan_chars.o scan_newline.o scan_space.o \
	scan_u32.o scan_u32o.o scan_u32x.o scan_u64.o scan_u64o.o \
	scan_u64x.o scan_float.o scan_double.o 
	./makelib scan scan_chars.o scan_newline.o scan_space.o scan_u32.o \
	scan_u32o.o scan_u32x.o scan_u64.o scan_u64o.o scan_u64x.o \
	scan_float.o scan_double.o 
scan_float.a:\
	makelib scan_float.sld scan_f32.o scan_f64.o 
	./makelib scan_float scan_f32.o scan_f64.o 
seek.a:\
	makelib seek.sld seek_cur.o seek_end.o seek_pos.o seek_start.o 
	./makelib seek seek_cur.o seek_end.o seek_pos.o seek_start.o 
sgetline.a:\
	makelib sgetline.sld sgetline.o sgetline_chop.o sgetline_get.o 
	./makelib sgetline sgetline.o sgetline_chop.o sgetline_get.o 
sstring.a:\
	makelib sstring.sld sstring_0.o sstring_cat.o sstring_catb.o \
	sstring_cats.o sstring_copy.o sstring_cpyb.o sstring_cpys.o \
	sstring_init.o sstring_trunc.o sstring_chop.o 
	./makelib sstring sstring_0.o sstring_cat.o sstring_catb.o \
	sstring_cats.o sstring_copy.o sstring_cpyb.o sstring_cpys.o \
	sstring_init.o sstring_trunc.o sstring_chop.o 
stalloc.a:\
	makelib stalloc.sld stalloc.o 
	./makelib stalloc stalloc.o 
str.a:\
	makelib str.sld str_chr.o str_copy.o str_diff.o str_dup.o \
	str_ends.o str_len.o str_ncopy.o str_rchr.o str_starts.o \
	str_tolower.o str_toupper.o 
	./makelib str str_chr.o str_copy.o str_diff.o str_dup.o str_ends.o \
	str_len.o str_ncopy.o str_rchr.o str_starts.o str_tolower.o \
	str_toupper.o 
syserr.a:\
	makelib syserr.sld syserr_die.o syserr_init.o 
	./makelib syserr syserr_die.o syserr_init.o 
uint16.a:\
	makelib uint16.sld uint16_pack.o uint16_unpack.o 
	./makelib uint16 uint16_pack.o uint16_unpack.o 
uint32.a:\
	makelib uint32.sld uint32_pack.o uint32_unpack.o 
	./makelib uint32 uint32_pack.o uint32_unpack.o 
uint64.a:\
	makelib uint64.sld uint64_pack.o uint64_unpack.o 
	./makelib uint64 uint64_pack.o uint64_unpack.o 

phase_library:\
	alloc.a array.a base_name.a bin.a buffer.a closeonexec.a \
	dir_array.a dir_hash.a dir_name.a dstring.a error.a fd.a float32.a \
	float64.a fmt.a get_opt.a hashtable.a int16.a int32.a int64.a \
	nonblock.a open.a scan.a scan_float.a seek.a sgetline.a sstring.a \
	stalloc.a str.a syserr.a uint16.a uint32.a uint64.a 
phase_library_clean:
	rm -f alloc.a array.a base_name.a bin.a buffer.a closeonexec.a \
	dir_array.a dir_hash.a dir_name.a dstring.a error.a fd.a float32.a \
	float64.a fmt.a get_opt.a hashtable.a int16.a int32.a int64.a \
	nonblock.a open.a scan.a scan_float.a seek.a sgetline.a sstring.a \
	stalloc.a str.a syserr.a uint16.a uint32.a uint64.a 

#--LINK-----------------------------------------------------------------------


phase_link:
phase_link_clean:

#--TEST-----------------------------------------------------------------------

phase_test_clean:
	(cd UNIT_TESTS; make clean)

phase_test:
	(cd UNIT_TESTS; make && make tests)

#--SYSDEPS-TARGET-------------------------------------------------------------

sysdeps: sysdeps.out
sysdeps_clean: sysdep_clean
sysdeps.out:
	SYSDEPS/sysdep-header sysdeps.out
	(cd SYSDEPS && make )
sysdep_clean:
	(cd SYSDEPS && make clean)
	rm -f sysdeps.out

#--TOOLS----------------------------------------------------------------------

mkftools: compile makelib sosuffix makeso link 
compile: conf-shebang conf-cc make-compile 
	(cat conf-shebang; ./make-compile) > compile; chmod u+x compile;
link: conf-shebang conf-ld make-link conf-ldfflist sysmath-libs 
	(cat conf-shebang; ./make-link) > link; chmod u+x link;
makelib: conf-shebang make-makelib 
	(cat conf-shebang; ./make-makelib) > makelib; chmod u+x makelib;
makeso: conf-shebang sosuffix make-makeso 
	(cat conf-shebang; ./make-makeso) > makeso; chmod u+x makeso;
sosuffix: conf-shebang make-sosuffix 
	(cat conf-shebang; ./make-sosuffix) > sosuffix; chmod u+x sosuffix;
mkftools_clean: 
	 rm -f compile makelib makeso sosuffix link 
regen:
	cpj-genmk > Makefile.tmp
	mv Makefile.tmp Makefile
