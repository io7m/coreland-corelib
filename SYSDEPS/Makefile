default: sysdeps
clean: sysdeps_clean

sysdeps:  sd_direntry sd_int16 sd_fd sd_signal sd_systype sd_x86cpuid sd_byteorder sd_int32 sd_int64 sd_uint16 sd_uint32 sd_uint64 sd_float32 sd_float64
sysdeps_clean:  sd_direntry_clean sd_int16_clean sd_fd_clean sd_signal_clean sd_systype_clean sd_x86cpuid_clean sd_byteorder_clean sd_int32_clean sd_int64_clean sd_uint16_clean sd_uint32_clean sd_uint64_clean sd_float32_clean sd_float64_clean

sd_direntry:
	@(cd direntry && ./run)
sd_direntry_clean:
	@(cd direntry && ./clean)

sd_int16:
	@(cd int16 && ./run)
sd_int16_clean:
	@(cd int16 && ./clean)

sd_fd:
	@(cd fd && ./run)
sd_fd_clean:
	@(cd fd && ./clean)

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

sd_byteorder:
	@(cd byteorder && ./run)
sd_byteorder_clean:
	@(cd byteorder && ./clean)

sd_int32:
	@(cd int32 && ./run)
sd_int32_clean:
	@(cd int32 && ./clean)

sd_int64:
	@(cd int64 && ./run)
sd_int64_clean:
	@(cd int64 && ./clean)

sd_uint16:
	@(cd uint16 && ./run)
sd_uint16_clean:
	@(cd uint16 && ./clean)

sd_uint32:
	@(cd uint32 && ./run)
sd_uint32_clean:
	@(cd uint32 && ./clean)

sd_uint64:
	@(cd uint64 && ./run)
sd_uint64_clean:
	@(cd uint64 && ./clean)

sd_float32:
	@(cd float32 && ./run)
sd_float32_clean:
	@(cd float32 && ./clean)

sd_float64:
	@(cd float64 && ./run)
sd_float64_clean:
	@(cd float64 && ./clean)

regen:
	./gen-makefile > Makefile.tmp
	mv Makefile.tmp Makefile
