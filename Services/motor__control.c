#include "motor__control.h"
#include "drv8833__driver.h"
#include "gpio__init.h"
#include "tim_init.h"

// Текущий шаг в последовательности
static uint8_t current_step = 0;
// Коэффициент заполнения ШИМ для управления скоростью (0-3199 для 0-100% заполнения)
static uint32_t duty_cycle = 1600;

// Последовательность полного шага для DRV8833 (направление + ШИМ)
static const uint8_t step_sequence[4][2] = {
    {0, 1}, // Шаг 0: Фаза A вперёд, Фаза B выкл
    {1, 1}, // Шаг 1: Фаза A вперёд, Фаза B вперёд
    {1, 0}, // Шаг 2: Фаза A выкл, Фаза B вперёд
    {0, 0}  // Шаг 3: Фаза A выкл, Фаза B выкл
};

void Stepper_Service_Init(void) {
    MX_GPIO_Init(); // Инициализация пинов GPIO
    tim_init(); // Инициализация таймера TIM1
    DRV8833_Init(); // Инициализация драйвера DRV8833
}

void Stepper_Service_Step(StepperDirection direction) {
    uint8_t phase_a_dir, phase_b_dir;

    // Определение направления на основе последовательности и входных данных
    if (direction == STEPPER_DIR_CW) {
        current_step = (current_step + 1) % 4;
    } else {
        current_step = (current_step - 1 + 4) % 4;
    }

    // Сопоставление последовательности с управлением DRV8833
    phase_a_dir = step_sequence[current_step][0];
    phase_b_dir = step_sequence[current_step][1];

    // Установка управления фазами DRV8833
    DRV8833_SetPhase(phase_a_dir, duty_cycle, phase_b_dir, duty_cycle);

    // Небольшая задержка для завершения шага
    vTaskDelay(pdMS_TO_TICKS(10));
}

void Stepper_Service_SetSpeed(uint32_t duty) {
    if (duty > 3199) duty = 3199; // Ограничение до максимального периода TIM1
    duty_cycle = duty;
}

uint32_t Stepper_Service_GetSpeed(void) {
    return duty_cycle;
}
