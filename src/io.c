#include <msp430.h>

#include <libwispbase/wisp-base.h>

#include <stdlib.h>
#include <stdbool.h>

#include "target_comm.h"

#include "stdio.h"

#define STDIO_BUF_SIZE (UART_MSG_HEADER_SIZE + IO_PAYLOAD_SIZE)

static uint8_t msg_buf[STDIO_BUF_SIZE];
static uint8_t *msg_payload = &msg_buf[UART_MSG_HEADER_SIZE];

static unsigned stdio_payload_len = 0;

void edb_output_app_data(const uint8_t *ptr, unsigned len)
{
    unsigned msg_len, payload_len = 0;
    unsigned data_len = len;

    while (data_len-- && payload_len < IO_PAYLOAD_SIZE - 1) {
        msg_payload[payload_len] = *ptr++;
        payload_len++;
    }

    msg_len = 0;
    msg_buf[msg_len++] = UART_IDENTIFIER_WISP;
    msg_buf[msg_len++] = WISP_RSP_APP_OUTPUT;
    msg_buf[msg_len++] = payload_len;
    msg_buf[msg_len++] = 0; // padding

    msg_len += payload_len;

    UART_send(msg_buf, msg_len);
}
