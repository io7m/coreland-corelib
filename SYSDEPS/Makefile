default: sysdeps
clean: sysdeps_clean

sysdeps:  sd_byteorder sd_direntry sd_sd-math sd_sysinfo sd_sd-fd sd_sd-fcntl sd_sd-signal sd_sd-longlong sd_sd-inline
sysdeps_clean:  sd_byteorder_clean sd_direntry_clean sd_sd-math_clean sd_sysinfo_clean sd_sd-fd_clean sd_sd-fcntl_clean sd_sd-signal_clean sd_sd-longlong_clean sd_sd-inline_clean

sd_byteorder:
	@(cd modules/byteorder && ./run)
sd_byteorder_clean:
	@(cd modules/byteorder && ./clean)

sd_direntry:
	@(cd modules/direntry && ./run)
sd_direntry_clean:
	@(cd modules/direntry && ./clean)

sd_sd-math:
	@(cd modules/sd-math && ./run)
sd_sd-math_clean:
	@(cd modules/sd-math && ./clean)

sd_sysinfo:
	@(cd modules/sysinfo && ./run)
sd_sysinfo_clean:
	@(cd modules/sysinfo && ./clean)

sd_sd-fd:
	@(cd modules/sd-fd && ./run)
sd_sd-fd_clean:
	@(cd modules/sd-fd && ./clean)

sd_sd-fcntl:
	@(cd modules/sd-fcntl && ./run)
sd_sd-fcntl_clean:
	@(cd modules/sd-fcntl && ./clean)

sd_sd-signal:
	@(cd modules/sd-signal && ./run)
sd_sd-signal_clean:
	@(cd modules/sd-signal && ./clean)

sd_sd-longlong:
	@(cd modules/sd-longlong && ./run)
sd_sd-longlong_clean:
	@(cd modules/sd-longlong && ./clean)

sd_sd-inline:
	@(cd modules/sd-inline && ./run)
sd_sd-inline_clean:
	@(cd modules/sd-inline && ./clean)

regen:
	./gen-makefile > Makefile.tmp && mv Makefile.tmp Makefile
