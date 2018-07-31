/**
 * PLATOTerm64 - A PLATO Terminal for the Commodore 64
 * Based on Steve Peltz's PAD
 * 
 * Author: Thomas Cherryhomes <thom.cherryhomes at gmail dot com>
 *
 * prefs.c - Preferences menu functions - Apple2 specific
 */

#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "../prefs.h"
#include "../config.h"

extern ConfigInfo config;
extern uint8_t ch;
extern uint8_t prefs_need_updating;
extern uint8_t touch_prefs_updated;
extern uint8_t io_prefs_updated;

/**
 * Show PLATOTERM READY - Press '<key>' for setup.
 */
void prefs_show_greeting(void)
{
  prefs_display("platoterm ready - <ctrl>-z for setup");
}

/**
 * prefs_touch(void)
 * Preferences for selecting touch driver
 */
void prefs_touch(void)
{
  prefs_display("m)ouse b)ack: ");

  ch=prefs_get_key_matching("mbMB");

  switch(ch)
    {
    case 'm':
      prefs_select("mouse");
      strcpy(config.driver_mou,CONFIG_MOUSE_DRIVER_STDMOU);
      touch_prefs_updated=true;
      prefs_need_updating=true;
      break;
    case 'b':
      prefs_select("back");
      break;
    }
}

/**
 * prefs_driver(void)
 * Preferences menu to select serial driver
 */
void prefs_driver(void)
{
  prefs_display("driver - s)sc b)ack: ");
  
  ch=prefs_get_key_matching("sbSB");

  switch(ch)
    {
    case 's':
      prefs_select("ssc");
      strcpy(config.driver_ser,CONFIG_SERIAL_DRIVER_SSC);
      io_prefs_updated=true;
      prefs_need_updating=true;
      break;
    case 'b':
      prefs_select("back");
      break;
    }
}

