
#include "main.h"
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"
#include "i2c_init.h"
#include "spi_init.h"
#include "rf_init.h"
#include "gpio__init.h"
#include "system_clock_config.h"
#include "error_handler.h"
#include "tick_callback.h"
#include "tim_init.h"
#include "usart_init.h"
#include "my_tasks.h"
#include "app__main.h"












int main(void)
{

  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Configure the peripherals common clocks */
  PeriphCommonClock_Config();

  /* IPCC initialisation */
  MX_IPCC_Init();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_SPI1_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  MX_RF_Init();
 



  if (xTaskCreate(BlinkTask, "Blink", 128, NULL, 1, NULL) != pdPASS)
  {
    Error_Handler();
  }


  /* Init scheduler */
  vTaskStartScheduler();
 
  
  while (1)
  {
    
  }
  
}
















