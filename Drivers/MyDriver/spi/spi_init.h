#ifndef __SPI_INIT_H
#define __SPI_INIT_H
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
//#include "stm32wbxx_hal.h"


extern SPI_HandleTypeDef hspi1;
void MX_SPI1_Init(void);



#ifdef __cplusplus
}
#endif

#endif /* __SPI_INIT_H */