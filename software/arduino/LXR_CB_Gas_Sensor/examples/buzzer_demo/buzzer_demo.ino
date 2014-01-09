/** 
 * @author Alexander Entinger MSc, LXRobotics
 * @brief this file demonstrates how to use the LXR_CB_Gas_Sensor library to turn on and off the alarm buzzer of the gas sensor childboard
 * @file buzzer_demo.ino
 * @license Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0) ( http://creativecommons.org/licenses/by-nc-sa/3.0/ )
 */

#include "LXR_CB_Gas_Sensor.h"

void setup() {               
  // initialize the gas sensor childboard 
  LXR_CB_Gas_Sensor::begin();
}

void loop() {
  // turn buzzer on
  LXR_CB_Gas_Sensor::turn_on_alarm();
  delay(1000);
  // turn buzzer off
  LXR_CB_Gas_Sensor::turn_off_alarm();
  delay(1000);
}
