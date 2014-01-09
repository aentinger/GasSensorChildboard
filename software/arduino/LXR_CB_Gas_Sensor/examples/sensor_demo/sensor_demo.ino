/** 
 * @author Alexander Entinger MSc, LXRobotics
 * @brief this file demonstrates how to use the LXR_CB_Gas_Sensor library to turn on and off the gas sensor of the of the gas sensor childboard and read its value
 * @file sensor_demo.ino
 * @license Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0) ( http://creativecommons.org/licenses/by-nc-sa/3.0/ )
 */

#include "LXR_CB_Gas_Sensor.h"

void setup() {               
  // initialize the gas sensor childboard 
  LXR_CB_Gas_Sensor::begin();
  // turn on the gas sensor
  LXR_CB_Gas_Sensor::turn_on_sensor();
  // sensor can be turned off with the following command
  // LXR_CB_Gas_Sensor::turn_off_sensor();
  Serial.begin(115200);
}

void loop() {
  Serial.print("Value at the voltage divider: ");
  Serial.println(LXR_CB_Gas_Sensor::read_gas_sensor());
  delay(1000);
}
