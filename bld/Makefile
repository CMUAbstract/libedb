LIB = libedb

OBJECTS = \
	edb.o \
	io.o \

DEPS += \
	libwispbase \
	libmsp \

# Override because the app/maker makefile sets it hard with -e
override SRC_ROOT := ../../src

override CFLAGS += \
	-I $(SRC_ROOT) \
	-I $(SRC_ROOT)/include/$(LIB) \
