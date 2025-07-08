/**
 * @file: led__controller.h
 * @description: LED controller service for managing LED operations
 * @dependencies: led__driver.h, ble__service.h
 * @created: 2024-12-19
 */

#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include "led__driver.h"
#include "ble__service.h"

// LED controller states
typedef enum {
    LED_CTRL_STATE_IDLE = 0,
    LED_CTRL_STATE_BLINKING,
    LED_CTRL_STATE_PATTERN,
    LED_CTRL_STATE_ERROR
} led_ctrl_state_t;

// LED patterns
typedef enum {
    LED_PATTERN_NONE = 0,
    LED_PATTERN_SEQUENTIAL,
    LED_PATTERN_ALTERNATING,
    LED_PATTERN_WAVE,
    LED_PATTERN_RANDOM
} led_pattern_t;

// Function prototypes
void led_controller_init(void);
void led_controller_process(void);
led_ctrl_state_t led_controller_get_state(void);

// LED control functions
void led_controller_set_led(uint8_t led_id, uint8_t state);
void led_controller_set_all(uint8_t state_mask);
void led_controller_toggle_led(uint8_t led_id);
void led_controller_blink_led(uint8_t led_id, uint32_t period_ms);

// Pattern functions
void led_controller_start_pattern(led_pattern_t pattern, uint32_t period_ms);
void led_controller_stop_pattern(void);
led_pattern_t led_controller_get_current_pattern(void);

// Status functions
uint8_t led_controller_get_led_state(uint8_t led_id);
uint8_t led_controller_get_all_states(void);

#endif // LED_CONTROLLER_H 