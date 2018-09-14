/**
 * PLATOTerm64 - A PLATO Terminal for the Commodore 64
 * Based on Steve Peltz's PAD
 * 
 * Author: Thomas Cherryhomes <thom.cherryhomes at gmail dot com>
 *
 * config.c - Configuration routines
 */

#include <atari.h>
#include <serial.h>
#include <stdbool.h>
#include <string.h>
#include <peekpoke.h>
#include "../config.h"

#define CONFIG_DEFAULT_SERIAL_DRIVER CONFIG_SERIAL_DRIVER_ATRRDEV
#define CONFIG_DEFAULT_MOUSE_DRIVER CONFIG_MOUSE_DRIVER_ATRJOY

extern ConfigInfo config;
extern char configFile[13];
static unsigned char dunit;

/**
 * config_set_defaults()
 * Set default values for config file
 */
void config_set_defaults(void)
{
  config.io_mode = IO_MODE_SERIAL;
  config.baud = SER_BAUD_1200;
  config.use_dhcp = false;
  config.ip_address=0;
  config.netmask=0;
  config.gateway=0;
  config.dns=0;
  strcpy(config.driver_ser,CONFIG_DEFAULT_SERIAL_DRIVER);
  strcpy(config.driver_mou,"NONE");
  config.color_foreground=TGI_COLOR_WHITE;
  config.color_background=TGI_COLOR_BLACK;
  config.color_border=TGI_COLOR_BLACK;
  config_save();
}

void config_atari_fix_driver_filenames(void)
{
  /* dunit=PEEK(769); // Get drive number from dunit. */
  /* configFile[1]=dunit; */
  /* config.driver_ser[1]=dunit; */
  
  /* if (strcmp(config.driver_mou,"NONE")!=0) */
  /*   config.driver_mou[1]=dunit; */
  
}

void config_init_hook(void)
{
  config_atari_fix_driver_filenames();
}
