/**
 * @file: sensor__manager.h
 * @description: Sensor management service for system monitoring
 * @dependencies: stm32wbxx_hal.h
 * @created: 2024-12-19
 */

#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include "stm32wbxx_hal.h"

// Sensor types
typedef enum {
    SENSOR_TYPE_TEMPERATURE = 0,
    SENSOR_TYPE_HUMIDITY,
    SENSOR_TYPE_PRESSURE,
    SENSOR_TYPE_LIGHT,
    SENSOR_TYPE_ACCELEROMETER,
    SENSOR_TYPE_COUNT
} sensor_type_t;

// Sensor data structure
typedef struct {
    sensor_type_t type;
    float value;
    uint32_t timestamp;
    uint8_t valid;
} sensor_data_t;

// Function prototypes
void sensor_manager_init(void);
void sensor_manager_process(void);
sensor_data_t sensor_manager_get_data(sensor_type_t type);
uint8_t sensor_manager_is_available(sensor_type_t type);
void sensor_manager_calibrate(sensor_type_t type);

#endif // SENSOR_MANAGER_H