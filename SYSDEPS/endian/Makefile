sd_out="../../sysdeps.out"
header="../../endian.h"

sysdep: endian
clean: endian_clean

endian: endian.c
	cc -o endian endian.c
	./endian 1>../../endian.h 2>>${sd_out}

endian_clean:
	rm -f endian
	rm -f ${header}
