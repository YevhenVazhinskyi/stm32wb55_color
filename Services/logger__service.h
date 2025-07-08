/**
 * @file: logger__service.h
 * @description: Logging service for system-wide logging functionality
 * @dependencies: stm32wbxx_hal.h
 * @created: 2024-12-19
 */

#ifndef LOGGER_SERVICE_H
#define LOGGER_SERVICE_H

#include "stm32wbxx_hal.h"

// Log levels
typedef enum {
    LOG_LEVEL_DEBUG = 0,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_CRITICAL
} log_level_t;

// Function prototypes
void logger_service_init(void);
void logger_service_log(const char* message);
void logger_service_log_with_level(log_level_t level, const char* message);
void logger_service_log_formatted(log_level_t level, const char* format, ...);
void logger_service_set_level(log_level_t min_level);
log_level_t logger_service_get_level(void);

#endif // LOGGER_SERVICE_H