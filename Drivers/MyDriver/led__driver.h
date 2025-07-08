/**
 * @file: led__driver.h
 * @description: LED driver for controlling 4 LEDs on STM32WB55
 * @dependencies: stm32wbxx_hal.h
 * @created: 2024-12-19
 */

#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include "stm32wbxx_hal.h"

// LED definitions
#define LED_COUNT               4
#define LED_1                   GPIO_PIN_5  // PA5
#define LED_2                   GPIO_PIN_6  // PA6  
#define LED_3                   GPIO_PIN_7  // PA7
#define LED_4                   GPIO_PIN_4  // PA4

#define LED_PORT                GPIOA

// LED states
#define LED_OFF                 0
#define LED_ON                  1
#define LED_TOGGLE              2
#define LED_BLINK               3

// LED IDs
#define LED_ID_1                1
#define LED_ID_2                2
#define LED_ID_3                3
#define LED_ID_4                4

// Function prototypes
void led_init(void);
void led_set_state(uint8_t led_id, uint8_t state);
void led_set_all(uint8_t state_mask);
void led_toggle(uint8_t led_id);
void led_blink_start(uint8_t led_id, uint32_t period_ms);
void led_blink_stop(uint8_t led_id);
uint8_t led_get_state(uint8_t led_id);
uint8_t led_get_all_states(void);

#endif // LED_DRIVER_H 