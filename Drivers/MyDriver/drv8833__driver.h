#ifndef DRV8833_DRIVER_H
#define DRV8833_DRIVER_H

#include "main.h"
#include "stm32wbxx_hal.h"

// Определения GPIO и таймера для DRV8833
#define DRV8833_PHASE_A_DIR_PIN_GPIO_PIN_4  GPIO_PIN_4  // Пин 4 GPIOB (Выход)
#define DRV8833_PHASE_A_PWM_PIN_GPIO_PIN_0  GPIO_PIN_0  // Пин 0 GPIOA (TIM1 PWM)
#define DRV8833_PHASE_B_DIR_PIN_GPIO_PIN_5  GPIO_PIN_5  // Пин 5 GPIOB (Выход)
#define DRV8833_PHASE_B_PWM_PIN_GPIO_PIN_1  GPIO_PIN_1  // Пин 1 GPIOA (TIM1 PWM)
#define DRV8833_DIR_PORT_GPIOB         GPIOB
#define DRV8833_PWM_PORT_GPIOA         GPIOA
#define DRV8833_TIMER_TIM1           TIM1
#define DRV8833_CHANNEL_A_TIM_CHANNEL_1        TIM_CHANNEL_1
#define DRV8833_CHANNEL_B_TIM_CHANNEL_2        TIM_CHANNEL_2

// Прототипы функций
void DRV8833_Init(void);
void DRV8833_SetPhase(uint8_t phase_a_dir, uint32_t phase_a_pwm, uint8_t phase_b_dir, uint32_t phase_b_pwm);

#endif /* DRV8833_DRIVER_H */