#ifndef __RF_INIT_H
#define __RF_INIT_H
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
//#include "stm32wbxx_hal.h"

extern IPCC_HandleTypeDef hipcc;

void rf_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __RF_INIT_H */