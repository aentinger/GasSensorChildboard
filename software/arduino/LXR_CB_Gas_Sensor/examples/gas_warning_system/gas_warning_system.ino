/** 
 * @author Alexander Entinger MSc, LXRobotics
 * @brief this file demonstrates how to use the LXR_CB_Gas_Sensor library to warn from too much gas in the air by buzzer and led - Attention: This is not a calibrated nor a certified smoke/gas/whatever detector. Therefor it can never replace a "real" smoke/gas/.. warning system.
 * @file gas_warning_system.ino
 * @license Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0) ( http://creativecommons.org/licenses/by-nc-sa/3.0/ )
 */

#include "LXR_CB_Gas_Sensor.h"

void setup() {               
  // initialize the gas sensor childboard 
  LXR_CB_Gas_Sensor::begin();
  // turn on the gas sensor
  LXR_CB_Gas_Sensor::turn_on_sensor();
}

static int const threshold = 300;

void loop() {
  if(LXR_CB_Gas_Sensor::read_gas_sensor() > threshold) {
    LXR_CB_Gas_Sensor::turn_on_led();
    LXR_CB_Gas_Sensor::turn_on_alarm();
  } else {
    LXR_CB_Gas_Sensor::turn_off_led();
    LXR_CB_Gas_Sensor::turn_off_alarm();
  }
}
