LIB = libedb

OBJECTS = \
	edb.o \
	io.o \

# Override because the app/maker makefile sets it hard with -e
override SRC_ROOT := ../../src

ifeq ($(TOOLCHAIN),ticl)
CFLAGS += \
	--include_path="$(SRC_ROOT)" \
	--include_path="$(SRC_ROOT)/include/libedb" \
else
CFLAGS += \
	-I $(SRC_ROOT) \
	-I $(SRC_ROOT)/include/libedb \
endif

DEPS += \
	libwispbase \
	libmsp \

include ../Makefile.config # one up from toolchain subdirs
