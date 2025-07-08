#include "blink__logic.h"
#include "stm32wbxx_hal.h"

// LED Pin definitions (using GPIOE Pin 4 from gpio_init.c)
#define LED_PORT GPIOB
#define LED_PIN  GPIO_PIN_4

void Blink_Logic_Init(void) {
    // Create the blink task
    xTaskCreate(Blink_Task, "BlinkTask", 128, NULL, 2, NULL);
}

void Blink_Task(void *pvParameters) {
    (void)pvParameters; // Unused parameter

    while (1) {
        // Toggle the LED
        HAL_GPIO_TogglePin(LED_PORT, LED_PIN);

        // Delay for 500ms (1 second total cycle: 500ms on, 500ms off)
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}