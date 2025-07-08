/**
 * @file: error__manager.c
 * @description: Error management service implementation
 * @dependencies: error__manager.h
 * @created: 2024-12-19
 */

#include "error__manager.h"
#include <string.h>

#define MAX_ERROR_ENTRIES 10

// Error manager state
static struct {
    error_entry_t entries[MAX_ERROR_ENTRIES];
    uint8_t count;
    uint8_t head;
    uint8_t initialized;
} error_manager = {0};

// Error code strings
static const char* error_strings[] = {
    "No Error",
    "BLE Init Failed",
    "LED Driver Failed", 
    "Sensor Read Failed",
    "Memory Allocation Failed",
    "Invalid Parameter",
    "Task Creation Failed",
    "Peripheral Init Failed",
    "Communication Timeout",
    "System Overload",
    "Unknown Error"
};

void error_manager_init(void) {
    memset(&error_manager, 0, sizeof(error_manager));
    error_manager.initialized = 1;
}

void error_manager_process(void) {
    if (!error_manager.initialized) {
        return;
    }
    
    // Process error entries if needed
    // For now, just a placeholder
}

void error_manager_log(error_code_t code, const char* message) {
    error_manager_log_with_severity(code, ERR_SEVERITY_ERROR, message);
}

void error_manager_log_with_severity(error_code_t code, error_severity_t severity, const char* message) {
    if (!error_manager.initialized) {
        return;
    }
    
    // Add error to circular buffer
    error_entry_t* entry = &error_manager.entries[error_manager.head];
    entry->code = code;
    entry->severity = severity;
    entry->timestamp = HAL_GetTick();
    entry->message = message;
    
    error_manager.head = (error_manager.head + 1) % MAX_ERROR_ENTRIES;
    
    if (error_manager.count < MAX_ERROR_ENTRIES) {
        error_manager.count++;
    }
}

error_code_t error_manager_get_last_error(void) {
    if (!error_manager.initialized || error_manager.count == 0) {
        return ERR_NONE;
    }
    
    uint8_t last_index = (error_manager.head - 1 + MAX_ERROR_ENTRIES) % MAX_ERROR_ENTRIES;
    return error_manager.entries[last_index].code;
}

uint32_t error_manager_get_error_count(void) {
    return error_manager.count;
}

void error_manager_clear_errors(void) {
    if (!error_manager.initialized) {
        return;
    }
    
    error_manager.count = 0;
    error_manager.head = 0;
    memset(error_manager.entries, 0, sizeof(error_manager.entries));
}

const char* error_manager_get_error_string(error_code_t code) {
    if (code >= sizeof(error_strings) / sizeof(error_strings[0])) {
        return error_strings[ERR_UNKNOWN];
    }
    return error_strings[code];
}