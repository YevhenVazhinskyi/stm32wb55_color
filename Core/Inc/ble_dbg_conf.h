/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    ble_dbg_conf.h
  * @author  STM32WB55 BLE LED Control Project
  * @brief   Debug configuration file for STM32WPAN Middleware.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef BLE_DBG_CONF_H
#define BLE_DBG_CONF_H

/**
 * Enable or Disable traces from BLE
 */
#define BLE_DBG_APP_EN                           0
#define BLE_DBG_DIS_EN                           0
#define BLE_DBG_HRS_EN                           0
#define BLE_DBG_SVCCTL_EN                        0
#define BLE_DBG_BLS_EN                           0
#define BLE_DBG_HTS_EN                           0
#define BLE_DBG_P2P_STM_EN                       0
#define BLE_DBG_TEMPLATE_STM_EN                  0
#define BLE_DBG_LBS_STM_EN                       0
#define BLE_DBG_MOTENV_STM_EN                    0
#define BLE_DBG_SW_ENV_STM_EN                    0
#define BLE_DBG_DT_EN                            0
#define BLE_DBG_DTS_EN                           0
#define BLE_DBG_CTS_EN                           0
#define BLE_DBG_HIDS_EN                          0
#define BLE_DBG_LLS_EN                           0
#define BLE_DBG_TPS_EN                           0
#define BLE_DBG_BAS_EN                           0

/**
 * Macro definition
 */
#define BLE_DBG_APP_MSG             PRINT_LOG_BUFF
#define BLE_DBG_DIS_MSG             PRINT_LOG_BUFF
#define BLE_DBG_HRS_MSG             PRINT_LOG_BUFF
#define BLE_DBG_SVCCTL_MSG          PRINT_LOG_BUFF
#define BLE_DBG_BLS_MSG             PRINT_LOG_BUFF
#define BLE_DBG_HTS_MSG             PRINT_LOG_BUFF
#define BLE_DBG_P2P_STM_MSG         PRINT_LOG_BUFF
#define BLE_DBG_TEMPLATE_STM_MSG    PRINT_LOG_BUFF
#define BLE_DBG_LBS_STM_MSG         PRINT_LOG_BUFF
#define BLE_DBG_MOTENV_STM_MSG      PRINT_LOG_BUFF
#define BLE_DBG_SW_ENV_STM_MSG      PRINT_LOG_BUFF
#define BLE_DBG_DT_MSG              PRINT_LOG_BUFF
#define BLE_DBG_DTS_MSG             PRINT_LOG_BUFF
#define BLE_DBG_CTS_MSG             PRINT_LOG_BUFF
#define BLE_DBG_HIDS_MSG            PRINT_LOG_BUFF
#define BLE_DBG_LLS_MSG             PRINT_LOG_BUFF
#define BLE_DBG_TPS_MSG             PRINT_LOG_BUFF
#define BLE_DBG_BAS_MSG             PRINT_LOG_BUFF

/**
 * Define a simple debug function that can be customized later
 */
#define PRINT_LOG_BUFF(...)

#endif /*BLE_DBG_CONF_H */ 