/**
 * PLATOTerm64 - A PLATO Terminal for the Commodore 64
 * Based on Steve Peltz's PAD
 * 
 * Author: Thomas Cherryhomes <thom.cherryhomes at gmail dot com>
 *
 * io.h - Input/output functions (serial/ethernet)
 */

#ifndef IO_H
#define IO_H

#define XON  0x11
#define XOFF 0x13

/**
 * io_init() - Set-up the I/O
 */
void io_init(void);

/**
 * io_open() - Open the device
 */
void io_open(void);

/**
 * io_send_byte(b) - Send specified byte out
 */
void io_send_byte(uint8_t b);

/**
 * io_main() - The IO main loop
 */
void io_main(void);

/**
 * io_recv_serial() - Receive and interpret serial data.
 */
void io_recv_serial(void);

/**
 * io_recv_serial_flow_off() - Tell modem to stop receiving.
 */
void io_recv_serial_flow_off(void);

/**
 * io_recv_serial_flow_on() - Tell modem to stop receiving.
 */
void io_recv_serial_flow_on(void);


/**
 * io_done() - Called to close I/O
 */
void io_done(void);

/**
 * Return the serial buffer size
 */
uint8_t io_serial_buffer_size(void);

#endif /* IO_H */
