#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

void Error_Handler(void);
void assert_failed(uint8_t *file, uint32_t line);

#ifdef __cplusplus
}
#endif

#endif // ERROR_HANDLER_H
