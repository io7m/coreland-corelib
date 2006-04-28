sd_out="../../sysdeps.out"
uint16_header="../../_uint16.h"
uint32_header="../../_uint32.h"
uint64_header="../../_uint64.h"
int16_header="../../_int16.h"
int32_header="../../_int32.h"
int64_header="../../_int64.h"

sysdep: integers
clean: integers_clean

integers:
	cc -o uint16_make uint16_make.c
	cc -o uint32_make uint32_make.c
	cc -o uint64_make uint64_make.c
	cc -o int16_make int16_make.c
	cc -o int32_make int32_make.c
	cc -o int64_make int64_make.c
	./uint16_make 1>${uint16_header} 2>>${sd_out}
	./uint32_make 1>${uint32_header} 2>>${sd_out}
	./uint64_make 1>${uint64_header} 2>>${sd_out}
	./int16_make 1>${int16_header} 2>>${sd_out}
	./int32_make 1>${int32_header} 2>>${sd_out}
	./int64_make 1>${int64_header} 2>>${sd_out}

integers_clean:
	rm -f ${uint16_header}
	rm -f ${uint32_header}
	rm -f ${uint64_header}
	rm -f ${int16_header}
	rm -f ${int32_header}
	rm -f ${int64_header}	
	rm -f int16_make
	rm -f int32_make
	rm -f int64_make
	rm -f uint16_make
	rm -f uint32_make
	rm -f uint64_make
