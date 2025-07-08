/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    ble_user_callbacks.c
  * @author  STM32WB55 BLE LED Control Project
  * @brief   BLE user callback functions for STM32WPAN Middleware.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "app_common.h"
#include "ble.h"
#include "hci_tl.h"
#include "shci_tl.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  This function is called when notification from M0 is received.
  * @param  Notbuffer: HCI event packet
  * @retval None
  */
void hci_notify_asynch_evt(void* pdata)
{
    // Called when HCI events are received from the Bluetooth stack
    // For now, just acknowledge the event
    // In a full implementation, this would process HCI events
    (void)pdata; // Avoid unused parameter warning
}

/**
  * @brief  This function is called when notification on system channel from M0 is received.
  * @param  Notbuffer: SHCI event packet
  * @retval None
  */
void shci_notify_asynch_evt(void* pdata)
{
    // Called when SHCI (System HCI) events are received from the system controller
    // For now, just acknowledge the event
    // In a full implementation, this would handle system events like:
    // - SHCI_SUB_EVT_CODE_READY: BLE Stack is ready
    // - SHCI_SUB_EVT_BLE_NVM_RAM_UPDATE: BLE NVM RAM update
    (void)pdata; // Avoid unused parameter warning
}

/**
  * @brief  Called to process SHCI user events
  * @param  None
  * @retval None
  * @note   This function is now handled by the STM32_WPAN middleware.
  *         User event processing is implemented through SHCI_UserEvtRx callback
  *         in the BLE service layer.
  */
// void shci_user_evt_proc(void) - Removed to avoid conflict with STM32_WPAN middleware