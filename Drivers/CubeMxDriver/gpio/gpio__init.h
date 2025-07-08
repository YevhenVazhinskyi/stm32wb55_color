/**
 * @file: gpio__init.h
 * @description: GPIO initialization and configuration header
 * @dependencies: stm32wbxx_hal.h
 * @created: 2024-12-19
 */

#ifndef __GPIO_INIT_H
#define __GPIO_INIT_H
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "stm32wbxx_hal.h"
//#include "stm32wbxx_hal.h"

void MX_GPIO_Init(void);

// Function prototypes
void gpio_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __GPIO_INIT_H */