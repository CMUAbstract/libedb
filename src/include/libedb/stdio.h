#ifndef LIBEDB_STDIO_H
#define LIBEDB_STDIO_H

#include <stdbool.h>
#include <stdint.h>

void edb_stdio_byte(uint8_t c);
int edb_stdio_write(const char *ptr, bool newline);

#endif // LIBEDB_STDIO_H
