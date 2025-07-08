/**
 * @file: app__main.h
 * @description: Main application management and task coordination
 * @dependencies: cmsis_os.h, led__controller.h, ble__service.h
 * @created: 2024-12-19
 */

#ifndef APP_MAIN_H
#define APP_MAIN_H

#include "cmsis_os.h"
#include "led__controller.h"
#include "ble__service.h"

// Application states
typedef enum {
    APP_STATE_INIT = 0,
    APP_STATE_IDLE,
    APP_STATE_BLE_ADVERTISING,
    APP_STATE_BLE_CONNECTED,
    APP_STATE_LED_PATTERN_ACTIVE,
    APP_STATE_ERROR
} app_state_t;

// Application configuration
typedef struct {
    uint32_t main_task_period_ms;
    uint32_t ble_process_period_ms;
    uint32_t led_process_period_ms;
} app_config_t;

// Function prototypes
void app_main_init(void);
void app_main_start_tasks(void);
app_state_t app_main_get_state(void);
void app_main_set_state(app_state_t new_state);

// Task functions
void app_main_task(void *argument);
void app_ble_task(void *argument);
void app_led_task(void *argument);

// Application services initialization
void app_init_services(void);

#endif // APP_MAIN_H