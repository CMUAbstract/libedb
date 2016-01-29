#ifndef PRINTF_H
#define PRINTF_H

int printf(const char *format, ...);

void UART_init(); // defined by wisp-base
void UART_teardown(); // defined by libedb

#define EIF_PRINTF(...) do { \
        request_non_interactive_debug_mode(); \
        printf(__VA_ARGS__); \
        resume_application(); \
    } while (0);

#define BARE_PRINTF_ENABLE() UART_init()
#define BARE_PRINTF_DISABLE() UART_teardown()

#define BARE_PRINTF(...) printf(__VA_ARGS__)

#endif
