/**
 * PLATOTerm64 - A PLATO Terminal for the Commodore 64
 * Based on Steve Peltz's PAD
 * 
 * Author: Thomas Cherryhomes <thom.cherryhomes at gmail dot com>
 *
 * system.c - System specific functions
 */

#include <cbm.h>
#include <c64.h>

/**
 * Wait one frame of time
 */
void system_wait_frame(void)
{
  waitvsync();
}
