/**
 * @file: led__controller.c
 * @description: LED controller service implementation
 * @dependencies: led__controller.h, led__driver.h, ble__service.h
 * @created: 2024-12-19
 */

#include "led__controller.h"
#include "cmsis_os.h"
#include <string.h>
#include <stdlib.h>

// LED controller instance
static struct {
    led_ctrl_state_t state;
    led_pattern_t current_pattern;
    uint32_t pattern_period;
    uint32_t pattern_counter;
    uint8_t pattern_step;
} led_controller = {0};

// Pattern timer
static osTimerId_t pattern_timer = NULL;

// Pattern timer callback
static void led_pattern_callback(void *argument) {
    led_controller.pattern_counter++;
    
    switch (led_controller.current_pattern) {
        case LED_PATTERN_SEQUENTIAL:
            // Turn on one LED at a time in sequence
            led_set_all(1 << (led_controller.pattern_step % 4));
            led_controller.pattern_step++;
            break;
            
        case LED_PATTERN_ALTERNATING:
            // Alternate between even and odd LEDs
            if (led_controller.pattern_step % 2 == 0) {
                led_set_all(0x0A); // LEDs 2 and 4
            } else {
                led_set_all(0x05); // LEDs 1 and 3
            }
            led_controller.pattern_step++;
            break;
            
        case LED_PATTERN_WAVE:
            // Wave pattern: 1->2->3->4->3->2->1
            if (led_controller.pattern_step < 4) {
                led_set_all(1 << led_controller.pattern_step);
            } else {
                led_set_all(1 << (6 - led_controller.pattern_step));
            }
            led_controller.pattern_step++;
            if (led_controller.pattern_step >= 6) {
                led_controller.pattern_step = 0;
            }
            break;
            
        case LED_PATTERN_RANDOM:
            // Random pattern
            led_set_all(rand() % 16);
            break;
            
        default:
            break;
    }
    
    // Notify BLE service of state change
    uint8_t state_mask = led_get_all_states();
    ble_service_notify_led_state(state_mask);
}

void led_controller_init(void) {
    // Initialize LED driver
    led_init();
    
    // Initialize controller structure
    memset(&led_controller, 0, sizeof(led_controller));
    led_controller.state = LED_CTRL_STATE_IDLE;
    led_controller.current_pattern = LED_PATTERN_NONE;
    
    // Create pattern timer
    pattern_timer = osTimerNew(led_pattern_callback, osTimerPeriodic, NULL, NULL);
    
    // Turn off all LEDs initially
    led_set_all(0x00);
}

void led_controller_process(void) {
    // Process LED controller events
    // This function can be called periodically for additional processing
    
    // Check for pattern completion
    if (led_controller.current_pattern != LED_PATTERN_NONE) {
        led_controller.state = LED_CTRL_STATE_PATTERN;
    } else {
        led_controller.state = LED_CTRL_STATE_IDLE;
    }
}

led_ctrl_state_t led_controller_get_state(void) {
    return led_controller.state;
}

void led_controller_set_led(uint8_t led_id, uint8_t state) {
    // Stop any running pattern
    led_controller_stop_pattern();
    
    // Set LED state
    led_set_state(led_id, state);
    
    // Notify BLE service
    uint8_t state_mask = led_get_all_states();
    ble_service_notify_led_state(state_mask);
}

void led_controller_set_all(uint8_t state_mask) {
    // Stop any running pattern
    led_controller_stop_pattern();
    
    // Set all LED states
    led_set_all(state_mask);
    
    // Notify BLE service
    ble_service_notify_led_state(state_mask);
}

void led_controller_toggle_led(uint8_t led_id) {
    // Stop any running pattern
    led_controller_stop_pattern();
    
    // Toggle LED
    led_toggle(led_id);
    
    // Notify BLE service
    uint8_t state_mask = led_get_all_states();
    ble_service_notify_led_state(state_mask);
}

void led_controller_blink_led(uint8_t led_id, uint32_t period_ms) {
    // Stop any running pattern
    led_controller_stop_pattern();
    
    // Start blinking
    led_blink_start(led_id, period_ms);
    led_controller.state = LED_CTRL_STATE_BLINKING;
}

void led_controller_start_pattern(led_pattern_t pattern, uint32_t period_ms) {
    // Stop current pattern if running
    led_controller_stop_pattern();
    
    // Set new pattern
    led_controller.current_pattern = pattern;
    led_controller.pattern_period = period_ms;
    led_controller.pattern_counter = 0;
    led_controller.pattern_step = 0;
    
    // Start pattern timer
    if (pattern_timer != NULL) {
        osTimerStart(pattern_timer, period_ms);
    }
    
    led_controller.state = LED_CTRL_STATE_PATTERN;
}

void led_controller_stop_pattern(void) {
    // Stop pattern timer
    if (pattern_timer != NULL) {
        osTimerStop(pattern_timer);
    }
    
    // Reset pattern
    led_controller.current_pattern = LED_PATTERN_NONE;
    led_controller.pattern_counter = 0;
    led_controller.pattern_step = 0;
    
    led_controller.state = LED_CTRL_STATE_IDLE;
}

led_pattern_t led_controller_get_current_pattern(void) {
    return led_controller.current_pattern;
}

uint8_t led_controller_get_led_state(uint8_t led_id) {
    return led_get_state(led_id);
}

uint8_t led_controller_get_all_states(void) {
    return led_get_all_states();
} 