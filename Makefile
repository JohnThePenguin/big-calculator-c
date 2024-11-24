ifeq ($(OS),Windows_NT)
    MAKEFILE = makefiles\Makefile.windows
else
    MAKEFILE = makefiles/Makefile.linux
endif

include $(MAKEFILE)
