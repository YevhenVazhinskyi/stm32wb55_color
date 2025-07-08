/**
 * @file: error__manager.h
 * @description: Error management service for system-wide error handling
 * @dependencies: stm32wbxx_hal.h
 * @created: 2024-12-19
 */

#ifndef ERROR_MANAGER_H
#define ERROR_MANAGER_H

#include "stm32wbxx_hal.h"

// Error codes
typedef enum {
    ERR_NONE = 0,
    ERR_BLE_INIT_FAILED,
    ERR_LED_DRIVER_FAILED,
    ERR_SENSOR_READ_FAILED,
    ERR_MEMORY_ALLOCATION,
    ERR_INVALID_PARAMETER,
    ERR_TASK_CREATION_FAILED,
    ERR_PERIPHERAL_INIT_FAILED,
    ERR_COMMUNICATION_TIMEOUT,
    ERR_SYSTEM_OVERLOAD,
    ERR_UNKNOWN
} error_code_t;

// Error severity levels
typedef enum {
    ERR_SEVERITY_INFO = 0,
    ERR_SEVERITY_WARNING,
    ERR_SEVERITY_ERROR,
    ERR_SEVERITY_CRITICAL
} error_severity_t;

// Error entry structure
typedef struct {
    error_code_t code;
    error_severity_t severity;
    uint32_t timestamp;
    const char* message;
} error_entry_t;

// Function prototypes
void error_manager_init(void);
void error_manager_process(void);
void error_manager_log(error_code_t code, const char* message);
void error_manager_log_with_severity(error_code_t code, error_severity_t severity, const char* message);
error_code_t error_manager_get_last_error(void);
uint32_t error_manager_get_error_count(void);
void error_manager_clear_errors(void);
const char* error_manager_get_error_string(error_code_t code);

#endif // ERROR_MANAGER_H