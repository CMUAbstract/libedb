#include <msp430.h>
#include <wisp-base.h>

#include <stdlib.h>
#include <stdbool.h>

#include "target_comm.h"

#define STDIO_BUF_SIZE (UART_MSG_HEADER_SIZE + STDIO_PAYLOAD_SIZE)

static uint8_t stdio_buf[STDIO_BUF_SIZE];
static uint8_t *stdio_payload = &stdio_buf[UART_MSG_HEADER_SIZE];
static unsigned stdio_payload_len = 0;

int putchar(int c)
{
    unsigned msg_len = 0;
    
    stdio_payload[stdio_payload_len++] = (uint8_t)c;

    if (stdio_payload_len == STDIO_PAYLOAD_SIZE || c == '\n') { // flush on new line or full

        stdio_buf[msg_len++] = UART_IDENTIFIER_WISP;
        stdio_buf[msg_len++] = WISP_RSP_STDIO;
        stdio_buf[msg_len++] = stdio_payload_len;
        stdio_buf[msg_len++] = 0; // padding

        msg_len += stdio_payload_len;

        UART_send(stdio_buf, msg_len);

        stdio_payload_len = 0;
    }

    return c;
}

static int puts_base(const char *ptr, bool newline)
{
    unsigned msg_len;

    // Since puts always includes a '\n', we always flush
    // Send message chunk by chunk, include the current buffer contents
    while (*ptr != '\0') {
        while (*ptr != '\0' && stdio_payload_len < STDIO_PAYLOAD_SIZE - 1) {
            stdio_payload[stdio_payload_len] = *ptr++;
            stdio_payload_len++;
        }
        if (*ptr == '\0' && newline)
            stdio_payload[stdio_payload_len++] = '\n'; // puts semantics

        msg_len = 0;
        stdio_buf[msg_len++] = UART_IDENTIFIER_WISP;
        stdio_buf[msg_len++] = WISP_RSP_STDIO;
        stdio_buf[msg_len++] = stdio_payload_len;
        stdio_buf[msg_len++] = 0; // padding

        msg_len += stdio_payload_len;

        UART_send(stdio_buf, msg_len);

        stdio_payload_len = 0;
    }

    return 0;
}

int puts_no_newline(const char *ptr)
{
    return puts_base(ptr, false /* newline */);
}

int puts(const char *ptr)
{
    return puts_base(ptr, true /* newline */);
}
