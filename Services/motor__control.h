#ifndef __MOTOR__CONTROL_H
#define __MOTOR__CONTROL_H
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "stdint.h"
#include "FreeRTOS.h"
#include "task.h"
// Stepper motor directions
typedef enum {
    STEPPER_DIR_CW  = 0,  // Clockwise
    STEPPER_DIR_CCW = 1   // Counter-clockwise
} StepperDirection;

// Function prototypes
void Stepper_Service_Init(void);
void Stepper_Service_Step(StepperDirection direction);
void Stepper_Service_SetSpeed(uint32_t duty_cycle);
uint32_t Stepper_Service_GetSpeed(void);



#ifdef __cplusplus
}
#endif

#endif /* __MOTOR_CONTROL_H */