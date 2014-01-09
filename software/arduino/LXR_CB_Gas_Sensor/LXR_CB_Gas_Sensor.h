/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this module implements the library for controlling the LXRobotics Gassensor Childboard
 * @file LXR_CB_Gas_Sensor.h
 * @license Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0) ( http://creativecommons.org/licenses/by-nc-sa/3.0/ )
 */

#ifndef LXR_CB_GAS_SENSOR_H_
#define LXR_CB_GAS_SENSOR_H_

#include "Arduino.h"

class LXR_CB_Gas_Sensor {
public:
  /**
   * @brief this function initializes the childboard
   */
  static void begin();
  /**
   * @brief functions for turning on and off the red led
   */
  static void turn_on_led();
  static void turn_off_led();
  /**
   * @brief functions for turning on and off the alarm buzzer
   */
  static void turn_on_alarm();
  static void turn_off_alarm();
  /**
   * @brief functions for turning on and off the power supply for the gas sensor
   */
  static void turn_on_sensor();
  static void turn_off_sensor();
  /**
   * @brief returns the voltages measured after the voltage divider - this value is proportional to the amount of gas in the air for finetuning use the potentiometer
   */
  static int read_gas_sensor();
};

#endif

