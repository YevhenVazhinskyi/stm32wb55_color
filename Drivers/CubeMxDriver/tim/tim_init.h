#ifndef __TIM_INIT_H
#define __TIM_INIT_H
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
//#include "stm32wbxx_hal.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
void tim_init(void);




#ifdef __cplusplus
}
#endif

#endif /* __TIM_INIT_H */