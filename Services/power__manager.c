/**
 * @file: power__manager.c
 * @description: Power management service implementation
 * @dependencies: power__manager.h
 * @created: 2024-12-19
 */

#include "power__manager.h"

// Power manager state
static struct {
    power_mode_t current_mode;
    uint32_t battery_level;
    uint32_t current_consumption_ma;
    uint32_t uptime_seconds;
    uint8_t initialized;
} power_manager = {0};

void power_manager_init(void) {
    power_manager.current_mode = POWER_MODE_ACTIVE;
    power_manager.battery_level = 100; // Assume full battery
    power_manager.current_consumption_ma = 15; // Typical active consumption
    power_manager.uptime_seconds = 0;
    power_manager.initialized = 1;
}

void power_manager_process(void) {
    if (!power_manager.initialized) {
        return;
    }
    
    // Update uptime
    static uint32_t last_tick = 0;
    uint32_t current_tick = HAL_GetTick();
    
    if (current_tick - last_tick >= 1000) {
        power_manager.uptime_seconds++;
        last_tick = current_tick;
        
        // Simulate battery drain (very simplified)
        if (power_manager.battery_level > 0) {
            power_manager.battery_level--;
        }
    }
}

void power_manager_set_mode(power_mode_t mode) {
    if (!power_manager.initialized) {
        return;
    }
    
    power_manager.current_mode = mode;
    
    // Update consumption based on mode
    switch (mode) {
        case POWER_MODE_ACTIVE:
            power_manager.current_consumption_ma = 15;
            break;
        case POWER_MODE_SLEEP:
            power_manager.current_consumption_ma = 5;
            break;
        case POWER_MODE_STOP:
            power_manager.current_consumption_ma = 1;
            break;
        case POWER_MODE_STANDBY:
            power_manager.current_consumption_ma = 0;
            break;
    }
}

power_mode_t power_manager_get_mode(void) {
    return power_manager.current_mode;
}

power_status_t power_manager_get_status(void) {
    power_status_t status = {0};
    
    if (power_manager.initialized) {
        status.current_mode = power_manager.current_mode;
        status.battery_level = power_manager.battery_level;
        status.current_consumption_ma = power_manager.current_consumption_ma;
        status.uptime_seconds = power_manager.uptime_seconds;
    }
    
    return status;
}

uint32_t power_manager_get_battery_level(void) {
    return power_manager.battery_level;
}