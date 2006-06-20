default: sysdeps
clean: sysdeps_clean

sysdeps:  sd_direntry sd_endian sd_floats sd_integers sd_signal sd_systype sd_x86cpuid
sysdeps_clean:  sd_direntry_clean sd_endian_clean sd_floats_clean sd_integers_clean sd_signal_clean sd_systype_clean sd_x86cpuid_clean

sd_direntry:
	@(cd direntry && ./run)
sd_direntry_clean:
	@(cd direntry && ./clean)

sd_endian:
	@(cd endian && ./run)
sd_endian_clean:
	@(cd endian && ./clean)

sd_floats:
	@(cd floats && ./run)
sd_floats_clean:
	@(cd floats && ./clean)

sd_integers:
	@(cd integers && ./run)
sd_integers_clean:
	@(cd integers && ./clean)

sd_signal:
	@(cd signal && ./run)
sd_signal_clean:
	@(cd signal && ./clean)

sd_systype:
	@(cd systype && ./run)
sd_systype_clean:
	@(cd systype && ./clean)

sd_x86cpuid:
	@(cd x86cpuid && ./run)
sd_x86cpuid_clean:
	@(cd x86cpuid && ./clean)

regen:
	./gen-makefile > Makefile.tmp
	mv Makefile.tmp Makefile
