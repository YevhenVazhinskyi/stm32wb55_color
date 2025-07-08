#include "drv8833__driver.h"
//#include "tim_init.h"
#include "gpio__init.h"
extern TIM_HandleTypeDef htim1;

void DRV8833_Init(void) {
    // Пины GPIO и базовая конфигурация TIM1 уже инициализированы в MX_TIM1_Init
    // Убедимся, что каналы PWM запущены
    HAL_TIM_PWM_Start(&htim1, DRV8833_CHANNEL_A_TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, DRV8833_CHANNEL_B_TIM_CHANNEL_2);

    // Установка начального состояния
    HAL_GPIO_WritePin(DRV8833_DIR_PORT_GPIOB, DRV8833_PHASE_A_DIR_PIN_GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DRV8833_DIR_PORT_GPIOB, DRV8833_PHASE_B_DIR_PIN_GPIO_PIN_5, GPIO_PIN_RESET);
    DRV8833_SetPhase(0, 0, 0, 0);
}

void DRV8833_SetPhase(uint8_t phase_a_dir, uint32_t phase_a_pwm, uint8_t phase_b_dir, uint32_t phase_b_pwm) {
    HAL_GPIO_WritePin(DRV8833_DIR_PORT_GPIOB, DRV8833_PHASE_A_DIR_PIN_GPIO_PIN_4, phase_a_dir ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DRV8833_DIR_PORT_GPIOB, DRV8833_PHASE_B_DIR_PIN_GPIO_PIN_5, phase_b_dir ? GPIO_PIN_SET : GPIO_PIN_RESET);
    //__HAL_TIM_SET_COMPARE(&htim1, DRV8833_CHANNEL_A_TIM_CHANNEL_1, phase_a_pwm);
  //  __HAL_TIM_SET_COMPARE(&htim1, DRV8833_CHANNEL_B_TIM_CHANNEL_2, phase_b_pwm);
}
