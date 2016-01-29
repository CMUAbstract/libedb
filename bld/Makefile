LIB = libedb

OBJECTS = \
	edb.o \
	io.o \

# Override because the app/maker makefile sets it hard with -e
override SRC_ROOT := ../../src

CFLAGS += \
	-I $(SRC_ROOT) \
	-I $(SRC_ROOT)/include/libedb \

DEPS += libwispbase
