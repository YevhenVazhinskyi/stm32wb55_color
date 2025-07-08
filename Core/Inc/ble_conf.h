/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    ble_conf.h
  * @author  STM32WB55 BLE LED Control Project
  * @brief   BLE configuration file for STM32WPAN Middleware.
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
#ifndef BLE_CONF_H
#define BLE_CONF_H

/**
 * BLE version shall be v5.0 or higher
 */
#define BLE_V42    (42)
#define BLE_V50    (50)
#define BLE_VERSION   BLE_V50

/**
 * When OPTIMIZE_GATT_PROCEDURE is defined, GATT procedures are optimized for best performance.
 */
#define OPTIMIZE_GATT_PROCEDURE         1

#include "ble_bufsize.h"
#include "app_conf.h"

/**
 * BLE Context
 */
#define BLE_CONTEXT_SWITCH_TO_SINGLE_CONNECTION   1

/**
 * GAP Service - Appearance
 */
#define BLE_CFG_UNKNOWN_APPEARANCE                (0)
#define BLE_CFG_GAP_APPEARANCE                    (BLE_CFG_UNKNOWN_APPEARANCE)

/**
 * GATT Services and Characteristics
 */
#define BLE_CFG_MAX_NBR_GATT_EVT_HANDLERS         (30)

/**
 * GATT Client Configuration
 */
#define BLE_CFG_CLI_MAX_NBR_CB                    (10)

/**
 * GATT Client - Service to be discovered
 * None
 */

/**
 * Security Manager
 */
#define KEYPRESS_NOTIFICATION_SUPPORT             (0)

/**
 * White List
 */
#define BLE_CFG_WHITE_LIST_MAX_SIZE               (0)

/**
 * Number of Device Identity stored in Flash
 */
#define BLE_CFG_RESOLVING_LIST_MAX_SIZE           (0)

/**
 * BLE_CFG_BONDING_MODE - (0) Bonding is not allowed, (1) Bonding is allowed
 */
#define BLE_CFG_BONDING_MODE                      (1)

/**
 * BLE_CFG_MITM_PROTECTION - (0) Not Required, (1) Required
 */
#define BLE_CFG_MITM_PROTECTION                   (0)

/**
 * BLE_CFG_SC_SUPPORT - (0) None, (1) Optional, (2) Mandatory
 */
#define BLE_CFG_SC_SUPPORT                        (0)

/**
 * BLE_CFG_KEYPRESS_NOTIFICATION_SUPPORT - (0) Disabled, (1) Enabled
 */
#define BLE_CFG_KEYPRESS_NOTIFICATION_SUPPORT     (0)

/**
 * Advertising configuration
 */
#define BLE_CFG_ADV_DATA_LENGTH_MAX               (31)

#define BLE_CFG_SCAN_RSP_DATA_LENGTH_MAX          (31)

/**
 * L2CAP
 */
#define BLE_CFG_COC_NBR_MAX                       (32)

#define BLE_CFG_COC_MPS_MAX                       (247)

#define BLE_CFG_COC_INITIATOR_NBR_MAX             (32)

/**
 * Dynamic Memory Allocation
 */
#define BLE_CFG_TOTAL_BUFFER_SIZE                 (0)

/**
 * GATT structure
 * Maximum number of Services that can be stored in the GATT database.
 * Note that the GAP and GATT services are automatically added so this parameter should be 2 plus the number of user services
 */
#define BLE_CFG_SVC_MAX_NBR_CB                    (8)

#define BLE_CFG_CHAR_MAX_NBR_CB                   (0)

/**
 * Notification
 */
#define BLE_CFG_NOTIFY_POOL_SIZE                  (0x1F4)

/**
 * PREP WRITE LIST
 */
#define BLE_CFG_PREP_WRITE_X_ATT_MTU              (0x3A)

#define BLE_CFG_PREP_WRITE_LIST_SIZE              (BLE_CFG_PREP_WRITE_X_ATT_MTU * CFG_BLE_MAX_ATT_MTU)

/**
 * Attribute Value length
 */
#define BLE_CFG_ATTR_VALUE_LENGTH_MAX             (30)

#define BLE_CFG_ATTR_VALUE_ARRAY_SIZE             (1344)

#endif /*BLE_CONF_H */ 