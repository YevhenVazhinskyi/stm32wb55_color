#include "app__main.h"

#include "FreeRTOS.h"
#include "task.h"         // <--- вот это обязательно для vTaskDelay

void BlinkTask(void *pvParameters)
{
  (void) pvParameters;  // unused

  while (1)
  {
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);
    vTaskDelay(pdMS_TO_TICKS(50)); // задержка 500 мс
  }
}

