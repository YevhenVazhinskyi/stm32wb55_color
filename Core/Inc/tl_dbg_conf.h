/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    tl_dbg_conf.h
  * @author  STM32WB55 BLE LED Control Project
  * @brief   Transport Layer Debug configuration file for STM32WPAN Middleware.
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
#ifndef __TL_DBG_CONF_H
#define __TL_DBG_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "app_conf.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/

/**
 * Enable/Disable traces
 * The raw data output is the hci binary packet format as specified by the BT specification
 * The packet format of the trace can be enabled/disabled with TL_DBG_MSG_FORMAT
 */
#define TL_DBG_MSG_EN                   (0)

/**
 * Packet format specification
 * - 0 : raw binary packet format as specified by the BT specification
 * - 1 : packet format defined by the user
 * It requires to implement TL_DbgTrace()
 */
#define TL_DBG_MSG_FORMAT               (0)

/**
 * Output path
 * - 0 : traces output on the uart debug
 * - 1 : traces output via debug pins
 * - 2 : traces output on st-link probe 
 * It requires TL_DbgTrace()
 */
#define TL_DBG_MSG_OUTPUT_PATH          (0)

/**
 * Enable/Disable timestamp 
 * - 0 : No timestamp in the trace
 * - 1 : Timestamp is added in the trace
 */
#define TL_DBG_MSG_TIMESTAMP            (0)

/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* External variables --------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

// Transport Layer Debug Macros
#if (TL_DBG_MSG_EN == 1)
#define TL_MM_DBG_MSG(format, ...) do { printf(format, ##__VA_ARGS__); printf("\r\n"); } while(0)
#define TL_HCI_CMD_DBG_MSG(format, ...) do { printf(format, ##__VA_ARGS__); printf("\r\n"); } while(0)
#define TL_HCI_CMD_DBG_BUF(buffer, size, prefix) do { printf("%s", prefix); } while(0)
#define TL_HCI_CMD_DBG_RAW(buffer, size) do { } while(0)
#define TL_HCI_EVT_DBG_MSG(format, ...) do { printf(format, ##__VA_ARGS__); printf("\r\n"); } while(0)
#define TL_HCI_EVT_DBG_BUF(buffer, size, prefix) do { printf("%s", prefix); } while(0)
#define TL_HCI_EVT_DBG_RAW(buffer, size) do { } while(0)
#define TL_SHCI_CMD_DBG_MSG(format, ...) do { printf(format, ##__VA_ARGS__); printf("\r\n"); } while(0)
#define TL_SHCI_CMD_DBG_BUF(buffer, size, prefix) do { printf("%s", prefix); } while(0)
#define TL_SHCI_CMD_DBG_RAW(buffer, size) do { } while(0)
#define TL_SHCI_EVT_DBG_MSG(format, ...) do { printf(format, ##__VA_ARGS__); printf("\r\n"); } while(0)
#define TL_SHCI_EVT_DBG_BUF(buffer, size, prefix) do { printf("%s", prefix); } while(0)
#define TL_SHCI_EVT_DBG_RAW(buffer, size) do { } while(0)
#else
#define TL_MM_DBG_MSG(format, ...)
#define TL_HCI_CMD_DBG_MSG(format, ...)
#define TL_HCI_CMD_DBG_BUF(buffer, size, prefix)
#define TL_HCI_CMD_DBG_RAW(buffer, size)
#define TL_HCI_EVT_DBG_MSG(format, ...)
#define TL_HCI_EVT_DBG_BUF(buffer, size, prefix)
#define TL_HCI_EVT_DBG_RAW(buffer, size)
#define TL_SHCI_CMD_DBG_MSG(format, ...)
#define TL_SHCI_CMD_DBG_BUF(buffer, size, prefix)
#define TL_SHCI_CMD_DBG_RAW(buffer, size)
#define TL_SHCI_EVT_DBG_MSG(format, ...)
#define TL_SHCI_EVT_DBG_BUF(buffer, size, prefix)
#define TL_SHCI_EVT_DBG_RAW(buffer, size)
#endif

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /*__TL_DBG_CONF_H */ 