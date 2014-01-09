/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this module implements the library for controlling the LXRobotics Gassensor Childboard
 * @file LXR_CB_Gas_Sensor.cpp
 * @license Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0) ( http://creativecommons.org/licenses/by-nc-sa/3.0/ )
 */

#include "LXR_CB_Gas_Sensor.h"

#define BUZZER_PERIOD_US           (434)
#define BUZZER_PERIOD_HALF_US      (BUZZER_PERIOD_US/2)
#define TIMER2_TIMERSTEP_US        (2)
#define TIMER2_RELOAD_VALUE        (255 - BUZZER_PERIOD_HALF_US/TIMER2_TIMERSTEP_US)

static int const red_led_pin = 9; // D9
static int const alarm_buzzer_pin = 8; // D8
static volatile boolean m_buzzer_activated = false;
static int const sensor_power_pin = 7; // D7
static int const sensor_adc_pin = 5; // A5

/**
 * @brief this function initializes the childboard
 */
void LXR_CB_Gas_Sensor::begin() {
  // set led pin to output and high (led deactivated)
  pinMode(red_led_pin, OUTPUT);
  digitalWrite(red_led_pin, HIGH);
  // set buzzer pin to output and low (buzzer deactivated)
  pinMode(alarm_buzzer_pin, OUTPUT);
  digitalWrite(alarm_buzzer_pin, LOW);
  // init timer 2 for buzzer
  TCNT2 = TIMER2_RELOAD_VALUE;  // preload timer 2 with reload value
  TIMSK2 = (1<<TOIE2); // enable timer 2 overflow interrupt
  TCCR2B = (1<<CS21) | (1<<CS20); // activate timer 2, timer 2 prescaler = 32, 1 Timerstep = 2 us
  // set sensor power pin to output and high (power supply for sensor deactivated)
  pinMode(sensor_power_pin, OUTPUT);
  digitalWrite(sensor_power_pin, HIGH);
}

/**
 * @brief functions for turning on and off the red led
 */
void LXR_CB_Gas_Sensor::turn_on_led() {
  digitalWrite(red_led_pin, LOW);
}
void LXR_CB_Gas_Sensor::turn_off_led() {
  digitalWrite(red_led_pin, HIGH);
}

/**
 * @brief functions for turning on and off the alarm buzzer
 */
void LXR_CB_Gas_Sensor::turn_on_alarm() {
  m_buzzer_activated = true;
}
void LXR_CB_Gas_Sensor::turn_off_alarm() {
  m_buzzer_activated = false;
}

/**
 * @brief interrupt service routine for the buzzer
 */
static boolean is_buzzer_on = false;
ISR(TIMER2_OVF_vect) {
  TCNT2 = TIMER2_RELOAD_VALUE;
  if(m_buzzer_activated) {
    if(is_buzzer_on) digitalWrite(alarm_buzzer_pin, HIGH);
    else digitalWrite(alarm_buzzer_pin, LOW);
    is_buzzer_on = !is_buzzer_on;
  } else {
   digitalWrite(alarm_buzzer_pin, LOW);
  }
}

/**
 * @brief functions for turning on and off the power supply for the gas sensor
 */
void LXR_CB_Gas_Sensor::turn_on_sensor() {
  digitalWrite(sensor_power_pin, LOW);
}
void LXR_CB_Gas_Sensor::turn_off_sensor() {
 digitalWrite(sensor_power_pin, HIGH);
}

/**
 * @brief returns the voltages measured after the voltage divider - this value is proportional to the amount of gas in the air for finetuning use the potentiometer
 */
int LXR_CB_Gas_Sensor::read_gas_sensor() {
  return analogRead(sensor_adc_pin);
}
