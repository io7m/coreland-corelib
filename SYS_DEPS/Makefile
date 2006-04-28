default: sysdeps
clean: sysdeps_clean

sysdeps:  sd_systype sd_integers sd_direntry sd_floats sd_endian
sysdeps_clean:  sd_systype_clean sd_integers_clean sd_direntry_clean sd_floats_clean sd_endian_clean

sd_systype:
	( cd systype && make )

sd_systype_clean:
	( cd systype && make clean)

sd_integers:
	( cd integers && make )

sd_integers_clean:
	( cd integers && make clean)

sd_direntry:
	( cd direntry && make )

sd_direntry_clean:
	( cd direntry && make clean)

sd_floats:
	( cd floats && make )

sd_floats_clean:
	( cd floats && make clean)

sd_endian:
	( cd endian && make )

sd_endian_clean:
	( cd endian && make clean)

regen:
	sh genmakefile > Makefile.tmp
	mv Makefile.tmp Makefile
