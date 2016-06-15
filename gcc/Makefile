include ../../../Makefile.env

DEVICE  = msp430fr5969
PREFIX = $(TOOLCHAIN_ROOT)/bin/msp430-elf-
CC      = $(PREFIX)gcc
GDB     = $(PREFIX)gdb

SRC_DIR := ../src

CFLAGS = \
	-mmcu=$(DEVICE) \
	-O1 \
	-g \
	-std=c99 \
	-pedantic \
	-Wall \
	-I $(TOOLCHAIN_ROOT)/include \
	-I $(WISP_BASE_ROOT) \
	-I $(SRC_DIR) \
	-I $(SRC_DIR)/include/libedb \

VPATH = $(SRC_DIR)

BINARY = libedb.a

OBJECTS = \
	edb.o \
	io.o \

all: $(BINARY)

-include $(OBJECTS:.o=.d)

%.o: %.c
	mkdir -p "./$(shell dirname $@)"
	$(CC) -c -MD $(CFLAGS) $< -o $@

$(BINARY): $(OBJECTS)
	$(AR) rcs $@ $^ 

clean:
	rm -f $(OBJECTS) $(OBJECTS:.o=.d) $(BINARY)
