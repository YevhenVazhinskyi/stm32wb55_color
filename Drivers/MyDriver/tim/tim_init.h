#ifndef __TIM_INIT_H
#define __TIM_INIT_H
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
//#include "stm32wbxx_hal.h"

extern TIM_HandleTypeDef htim1;

void MX_TIM1_Init(void);
void MX_TIM2_Init(void);




#ifdef __cplusplus
}
#endif

#endif /* __TIM_INIT_H */