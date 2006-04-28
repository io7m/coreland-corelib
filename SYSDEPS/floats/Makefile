sd_out="../../sysdeps.out"
float32_header="../../_float32.h"
float64_header="../../_float64.h"

sysdep: floats
clean: floats_clean

floats:
	cc -o float32_make float32_make.c
	cc -o float64_make float64_make.c
	./float32_make 1>${float32_header} 2>>${sd_out}
	./float64_make 1>${float64_header} 2>>${sd_out}

floats_clean:
	rm -f ${float32_header}
	rm -f ${float64_header}
	rm -f float32_make
	rm -f float64_make
