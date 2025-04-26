#ifndef __TICK_CALLBACK_H
#define __TICK_CALLBACK_H
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
//#include "stm32wbxx_hal.h"


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);



#ifdef __cplusplus
}
#endif

#endif /* TICK_CALLBACK_H */