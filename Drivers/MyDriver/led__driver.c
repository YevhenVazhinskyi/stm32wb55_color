/**
 * @file: led__driver.c
 * @description: LED driver implementation for controlling 4 LEDs
 * @dependencies: led__driver.h, stm32wbxx_hal.h
 * @created: 2024-12-19
 */

#include "led__driver.h"
#include "cmsis_os.h"

// LED GPIO pins array
static const uint16_t led_pins[LED_COUNT] = {
    LED_1, LED_2, LED_3, LED_4
};

// LED states array
static uint8_t led_states[LED_COUNT] = {0};

// Blink timers
static osTimerId_t blink_timers[LED_COUNT] = {NULL};

// Blink timer callback
static void led_blink_callback(void *argument) {
    uint8_t led_id = (uint8_t)(uintptr_t)argument;
    if (led_id > 0 && led_id <= LED_COUNT) {
        led_toggle(led_id);
    }
}

void led_init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    
    // Enable GPIOA clock
    __HAL_RCC_GPIOA_CLK_ENABLE();
    
    // Configure LED pins as output
    GPIO_InitStruct.Pin = LED_1 | LED_2 | LED_3 | LED_4;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);
    
    // Initialize all LEDs to OFF
    for (int i = 0; i < LED_COUNT; i++) {
        led_states[i] = LED_OFF;
        HAL_GPIO_WritePin(LED_PORT, led_pins[i], GPIO_PIN_RESET);
    }
    
    // Create blink timers
    for (int i = 0; i < LED_COUNT; i++) {
        blink_timers[i] = osTimerNew(led_blink_callback, osTimerPeriodic, 
                                   (void*)(uintptr_t)(i + 1), NULL);
    }
}

void led_set_state(uint8_t led_id, uint8_t state) {
    if (led_id < 1 || led_id > LED_COUNT) {
        return;
    }
    
    uint8_t index = led_id - 1;
    uint16_t pin = led_pins[index];
    
    switch (state) {
        case LED_OFF:
            led_states[index] = LED_OFF;
            HAL_GPIO_WritePin(LED_PORT, pin, GPIO_PIN_RESET);
            led_blink_stop(led_id);
            break;
            
        case LED_ON:
            led_states[index] = LED_ON;
            HAL_GPIO_WritePin(LED_PORT, pin, GPIO_PIN_SET);
            led_blink_stop(led_id);
            break;
            
        case LED_TOGGLE:
            led_toggle(led_id);
            break;
            
        case LED_BLINK:
            led_states[index] = LED_BLINK;
            led_blink_start(led_id, 500); // Default 500ms blink
            break;
            
        default:
            break;
    }
}

void led_set_all(uint8_t state_mask) {
    for (int i = 0; i < LED_COUNT; i++) {
        uint8_t state = (state_mask >> i) & 0x01;
        led_set_state(i + 1, state ? LED_ON : LED_OFF);
    }
}

void led_toggle(uint8_t led_id) {
    if (led_id < 1 || led_id > LED_COUNT) {
        return;
    }
    
    uint8_t index = led_id - 1;
    uint16_t pin = led_pins[index];
    
    GPIO_PinState current_state = HAL_GPIO_ReadPin(LED_PORT, pin);
    GPIO_PinState new_state = (current_state == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET;
    
    HAL_GPIO_WritePin(LED_PORT, pin, new_state);
    led_states[index] = (new_state == GPIO_PIN_SET) ? LED_ON : LED_OFF;
}

void led_blink_start(uint8_t led_id, uint32_t period_ms) {
    if (led_id < 1 || led_id > LED_COUNT) {
        return;
    }
    
    uint8_t index = led_id - 1;
    
    // Stop existing blink
    led_blink_stop(led_id);
    
    // Start new blink timer
    osTimerStart(blink_timers[index], period_ms);
}

void led_blink_stop(uint8_t led_id) {
    if (led_id < 1 || led_id > LED_COUNT) {
        return;
    }
    
    uint8_t index = led_id - 1;
    osTimerStop(blink_timers[index]);
}

uint8_t led_get_state(uint8_t led_id) {
    if (led_id < 1 || led_id > LED_COUNT) {
        return LED_OFF;
    }
    
    uint8_t index = led_id - 1;
    return led_states[index];
}

uint8_t led_get_all_states(void) {
    uint8_t state_mask = 0;
    
    for (int i = 0; i < LED_COUNT; i++) {
        if (led_states[i] == LED_ON) {
            state_mask |= (1 << i);
        }
    }
    
    return state_mask;
} 