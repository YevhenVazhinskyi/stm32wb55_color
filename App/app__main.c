/**
 * @file: app__main.c
 * @description: Main application management and task coordination
 * @dependencies: app__main.h, led__controller.h, ble__service.h
 * @created: 2024-12-19
 */

#include "app__main.h"
#include "sensor__manager.h"
#include "power__manager.h"
#include "error__manager.h"
#include "logger__service.h"
#include <string.h>

// Application state
static struct {
    app_state_t current_state;
    app_config_t config;
    uint32_t error_count;
    uint32_t uptime_seconds;
} app_context = {0};

// Task handles
static osThreadId_t app_main_task_handle = NULL;
static osThreadId_t app_ble_task_handle = NULL;
static osThreadId_t app_led_task_handle = NULL;

// Task attributes
static const osThreadAttr_t app_main_task_attributes = {
    .name = "AppMainTask",
    .priority = (osPriority_t) osPriorityNormal,
    .stack_size = 256 * 4
};

static const osThreadAttr_t app_ble_task_attributes = {
    .name = "AppBleTask", 
    .priority = (osPriority_t) osPriorityHigh,
    .stack_size = 512 * 4
};

static const osThreadAttr_t app_led_task_attributes = {
    .name = "AppLedTask",
    .priority = (osPriority_t) osPriorityNormal,
    .stack_size = 256 * 4
};

void app_main_init(void) {
    // Initialize application context
    memset(&app_context, 0, sizeof(app_context));
    app_context.current_state = APP_STATE_INIT;
    
    // Set default configuration
    app_context.config.main_task_period_ms = 100;
    app_context.config.ble_process_period_ms = 10;
    app_context.config.led_process_period_ms = 50;
    
    // Initialize application services
    app_init_services();
    
    app_context.current_state = APP_STATE_IDLE;
}

void app_init_services(void) {
    // Initialize all application services
    led_controller_init();
    ble_service_init();
    sensor_manager_init();
    power_manager_init();
    error_manager_init();
    logger_service_init();
    
    // Log initialization
    logger_service_log("Application services initialized");
}

void app_main_start_tasks(void) {
    // Create application tasks
    app_main_task_handle = osThreadNew(app_main_task, NULL, &app_main_task_attributes);
    app_ble_task_handle = osThreadNew(app_ble_task, NULL, &app_ble_task_attributes);
    app_led_task_handle = osThreadNew(app_led_task, NULL, &app_led_task_attributes);
    
    if (app_main_task_handle == NULL || app_ble_task_handle == NULL || app_led_task_handle == NULL) {
        error_manager_log(ERR_TASK_CREATION_FAILED, "Failed to create application tasks");
        app_context.current_state = APP_STATE_ERROR;
    }
}

app_state_t app_main_get_state(void) {
    return app_context.current_state;
}

void app_main_set_state(app_state_t new_state) {
    if (app_context.current_state != new_state) {
        app_context.current_state = new_state;
        logger_service_log("Application state changed");
    }
}

// Main application task - coordinates overall system behavior
void app_main_task(void *argument) {
    (void)argument;
    uint32_t tick_count = 0;
    
    for (;;) {
        // Update uptime every 10 seconds (100ms * 100 = 10s)
        if (++tick_count >= 100) {
            tick_count = 0;
            app_context.uptime_seconds += 10;
        }
        
        // Process application state machine
        switch (app_context.current_state) {
            case APP_STATE_INIT:
                app_context.current_state = APP_STATE_IDLE;
                break;
                
            case APP_STATE_IDLE:
                // Check if BLE should start advertising
                if (ble_service_get_state() == BLE_STATE_DISCONNECTED) {
                    app_context.current_state = APP_STATE_BLE_ADVERTISING;
                }
                break;
                
            case APP_STATE_BLE_ADVERTISING:
                // Check if BLE connected
                if (ble_service_get_state() == BLE_STATE_CONNECTED) {
                    app_context.current_state = APP_STATE_BLE_CONNECTED;
                }
                break;
                
            case APP_STATE_BLE_CONNECTED:
                // Check if LED pattern is active
                if (led_controller_get_current_pattern() != LED_PATTERN_NONE) {
                    app_context.current_state = APP_STATE_LED_PATTERN_ACTIVE;
                }
                // Check if BLE disconnected
                else if (ble_service_get_state() == BLE_STATE_DISCONNECTED) {
                    app_context.current_state = APP_STATE_IDLE;
                }
                break;
                
            case APP_STATE_LED_PATTERN_ACTIVE:
                // Check if pattern stopped
                if (led_controller_get_current_pattern() == LED_PATTERN_NONE) {
                    app_context.current_state = APP_STATE_BLE_CONNECTED;
                }
                // Check if BLE disconnected
                else if (ble_service_get_state() == BLE_STATE_DISCONNECTED) {
                    led_controller_stop_pattern();
                    app_context.current_state = APP_STATE_IDLE;
                }
                break;
                
            case APP_STATE_ERROR:
                // Try to recover from error
                app_context.error_count++;
                if (app_context.error_count > 10) {
                    // Reset system if too many errors
                    NVIC_SystemReset();
                }
                app_context.current_state = APP_STATE_IDLE;
                break;
                
            default:
                app_context.current_state = APP_STATE_ERROR;
                break;
        }
        
        // Process system monitoring
        power_manager_process();
        error_manager_process();
        
        osDelay(app_context.config.main_task_period_ms);
    }
}

// BLE processing task - handles BLE communication
void app_ble_task(void *argument) {
    (void)argument;
    
    for (;;) {
        // Process BLE service
        ble_service_process();
        
        osDelay(app_context.config.ble_process_period_ms);
    }
}

// LED processing task - handles LED control and patterns
void app_led_task(void *argument) {
    (void)argument;
    
    for (;;) {
        // Process LED controller
        led_controller_process();
        
        // Process sensor data for LED feedback
        sensor_manager_process();
        
        osDelay(app_context.config.led_process_period_ms);
    }
}