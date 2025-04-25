#ifndef __SYSTEM_CLOCK_CONFIG_H
#define __SYSTEM_CLOCK_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
//#include "stm32wbxx_hal.h"


void SystemClock_Config(void);
void PeriphCommonClock_Config(void);



#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_CLOCK_CONFIG_H */
