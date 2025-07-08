/**
 * @file: logger__service.c
 * @description: Logging service implementation
 * @dependencies: logger__service.h
 * @created: 2024-12-19
 */

#include "logger__service.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define LOG_BUFFER_SIZE 256

// Logger state
static struct {
    log_level_t min_level;
    uint8_t initialized;
} logger = {0};

void logger_service_init(void) {
    logger.min_level = LOG_LEVEL_INFO;
    logger.initialized = 1;
}

void logger_service_log(const char* message) {
    logger_service_log_with_level(LOG_LEVEL_INFO, message);
}

void logger_service_log_with_level(log_level_t level, const char* message) {
    if (!logger.initialized || level < logger.min_level) {
        return;
    }
    
    // For now, just a placeholder - in real implementation would output to UART/RTT
    // Could implement circular buffer for logging
    (void)message; // Suppress unused parameter warning
}

void logger_service_log_formatted(log_level_t level, const char* format, ...) {
    if (!logger.initialized || level < logger.min_level) {
        return;
    }
    
    char buffer[LOG_BUFFER_SIZE];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    
    logger_service_log_with_level(level, buffer);
}

void logger_service_set_level(log_level_t min_level) {
    logger.min_level = min_level;
}

log_level_t logger_service_get_level(void) {
    return logger.min_level;
}
