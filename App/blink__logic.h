#ifndef BLINK__LOGIC_H
#define BLINK__LOGIC_H

#include "FreeRTOS.h"
#include "task.h"

void Blink_Logic_Init(void);
void Blink_Task(void *pvParameters);

#endif /* BLINK__LOGIC_H */