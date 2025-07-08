/**
 * @file: power__manager.h
 * @description: Power management service for system power optimization
 * @dependencies: stm32wbxx_hal.h
 * @created: 2024-12-19
 */

#ifndef POWER_MANAGER_H
#define POWER_MANAGER_H

#include "stm32wbxx_hal.h"

// Power modes
typedef enum {
    POWER_MODE_ACTIVE = 0,
    POWER_MODE_SLEEP,
    POWER_MODE_STOP,
    POWER_MODE_STANDBY
} power_mode_t;

// Power status
typedef struct {
    power_mode_t current_mode;
    uint32_t battery_level;
    uint32_t current_consumption_ma;
    uint32_t uptime_seconds;
} power_status_t;

// Function prototypes
void power_manager_init(void);
void power_manager_process(void);
void power_manager_set_mode(power_mode_t mode);
power_mode_t power_manager_get_mode(void);
power_status_t power_manager_get_status(void);
uint32_t power_manager_get_battery_level(void);

#endif // POWER_MANAGER_H