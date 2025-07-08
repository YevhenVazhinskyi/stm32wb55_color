#ifndef __I2C_INIT_H
#define __I2C_INIT_H
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
//#include "stm32wbxx_hal.h"
//#include "stm32wbxx_hal.h"


extern I2C_HandleTypeDef hi2c1; 
void i2c_init(void);



#ifdef __cplusplus
}
#endif

#endif /* __I2C_INIT_H */