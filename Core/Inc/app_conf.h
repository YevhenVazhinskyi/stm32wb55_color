/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_conf.h
  * @author  STM32WB55 BLE LED Control Project
  * @brief   Application configuration file for STM32WPAN Middleware.
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
#ifndef APP_CONF_H
#define APP_CONF_H

#include "stm32wbxx_hal.h"

/******************************************************************************
 * Application Config
 ******************************************************************************/

/**
 * Define Tx Power
 */
#define CFG_TX_POWER                      (0x18) /* -0.15dBm */

/**
 * Define Advertising parameters
 */
#define CFG_ADV_BD_ADDRESS                (0x7257acd87a6c)

/**
 * Define BD_ADDR type: GAP_PUBLIC_ADDR (0x00) or GAP_STATIC_RANDOM_ADDR (0x01)
 */
#define CFG_IDENTITY_ADDRESS              (0x00) /* GAP_PUBLIC_ADDR */

/**
 * Define privacy: PRIVACY_DISABLED or PRIVACY_ENABLED
 */
#define CFG_PRIVACY                       (0x00) /* PRIVACY_DISABLED */

/**
 * Define BLE Address Type
 */
#define CFG_BLE_ADDRESS_TYPE              (0x00) /* GAP_PUBLIC_ADDR */

#define CFG_FAST_CONN_ADV_INTERVAL_MIN    (0x80)      /**< 80ms */
#define CFG_FAST_CONN_ADV_INTERVAL_MAX    (0xa0)      /**< 100ms */
#define CFG_LP_CONN_ADV_INTERVAL_MIN      (0x640)     /**< 1s */
#define CFG_LP_CONN_ADV_INTERVAL_MAX      (0xfa0)     /**< 2.5s */

/**
 * Define IO Authentication
 */
#define CFG_BONDING_MODE                 (1)
#define CFG_FIXED_PIN                    (111111)
#define CFG_USED_FIXED_PIN               (0)
#define CFG_ENCRYPTION_KEY_SIZE_MAX      (16)
#define CFG_ENCRYPTION_KEY_SIZE_MIN      (8)

/**
 * Define IO capabilities
 */
#define CFG_IO_CAPABILITY_DISPLAY_ONLY        (0x00)
#define CFG_IO_CAPABILITY_DISPLAY_YES_NO      (0x01)
#define CFG_IO_CAPABILITY_KEYBOARD_ONLY       (0x02)
#define CFG_IO_CAPABILITY_NO_INPUT_NO_OUTPUT  (0x03)
#define CFG_IO_CAPABILITY_KEYBOARD_DISPLAY    (0x04)

#define CFG_IO_CAPABILITY                     CFG_IO_CAPABILITY_NO_INPUT_NO_OUTPUT

/**
 * Define MITM modes
 */
#define CFG_MITM_PROTECTION_NOT_REQUIRED      (0x00)
#define CFG_MITM_PROTECTION_REQUIRED          (0x01)

#define CFG_MITM_PROTECTION                   CFG_MITM_PROTECTION_NOT_REQUIRED

/**
 * Define Secure Connections Support
 */
#define CFG_SECURE_NOT_SUPPORTED              (0x00)
#define CFG_SECURE_OPTIONAL                   (0x01)
#define CFG_SECURE_MANDATORY                  (0x02)

#define CFG_SC_SUPPORT                        CFG_SECURE_NOT_SUPPORTED

/**
 * Define Keypress Notification Support
 */
#define CFG_KEYPRESS_NOT_SUPPORTED            (0x00)
#define CFG_KEYPRESS_SUPPORTED                (0x01)

#define CFG_KEYPRESS_NOTIFICATION_SUPPORT     CFG_KEYPRESS_NOT_SUPPORTED

/**
 * Device name configuration for Generic Access Service
 */
#define CFG_GAP_DEVICE_NAME             "STM32WB_LED"
#define CFG_GAP_DEVICE_NAME_LENGTH      (11)

/**
 * Define PHY
 */
#define ALL_PHYS_PREFERENCE                             0x00
#define RX_2M_PREFERRED                                 0x02
#define TX_2M_PREFERRED                                 0x02
#define TX_1M                                           0x01
#define TX_2M                                           0x02
#define RX_1M                                           0x01
#define RX_2M                                           0x02

/**
*   Identity root key used to derive IRK and DHK(Legacy)
*/
#define CFG_BLE_IR     {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0}

/**
* Encryption root key used to derive LTK(Legacy) and CSRK
*/
#define CFG_BLE_ER     {0xFE, 0xDC, 0xBA, 0x09, 0x87, 0x65, 0x43, 0x21, 0xFE, 0xDC, 0xBA, 0x09, 0x87, 0x65, 0x43, 0x21}

/**
 * SMPS supply
 * SMPS not used when Set to 0
 * SMPS used when Set to 1
 */
#define CFG_USE_SMPS    0

/******************************************************************************
 * BLE Stack
 ******************************************************************************/
/**
 * Maximum number of simultaneous connections that the device will support.
 * Valid values are from 1 to 8
 */
#define CFG_BLE_NUM_LINK            1

/**
 * Maximum number of Services that can be stored in the GATT database.
 * Note that the GAP and GATT services are automatically added so this parameter should be 2 plus the number of user services
 */
#define CFG_BLE_NUM_GATT_SERVICES   8

/**
 * Maximum number of Attributes
 * (i.e. the number of characteristic + the number of characteristic values + the number of descriptors, excluding the services)
 * that can be stored in the GATT database.
 * Note that certain characteristics and relative descriptors are added automatically during device initialization
 * so this parameters should be 9 plus the number of user Attributes
 */
#define CFG_BLE_NUM_GATT_ATTRIBUTES 68

/**
 * Maximum supported ATT_MTU size
 */
#define CFG_BLE_MAX_ATT_MTU             (156)

/**
 * Size of the storage area for Attribute values
 */
#define CFG_BLE_ATT_VALUE_ARRAY_SIZE    (1344)

/**
 * Maximum number of simultaneous Radio activities (Radio layer). Used only if RADIO_ACTIVITY_EVENT is used.
 * Valid values are from 1 to 8
 */
#define CFG_BLE_NUM_RADIO_TASKS         (CFG_BLE_NUM_LINK*2)

/**
 * Maximum number of simultaneous GATT Client Procedures
 * Valid values are from 1 to 8
 */
#define CFG_BLE_NUM_GATT_CLIENT_PROCS   (CFG_BLE_NUM_LINK*2)

/**
 * Enable Data length extension
 */
#define CFG_BLE_DATA_LENGTH_EXTENSION   1

/**
 * Prepare Write List size in terms of number of packet with ATT_MTU=23 bytes
 */
#define CFG_BLE_PREPARE_WRITE_LIST_SIZE (0x3A)

/**
 * Number of allocated memory blocks
 */
#define CFG_BLE_MBLOCK_COUNT            (0x79)

/**
 * Sleep clock accuracy
 */
#define CFG_BLE_SLAVE_SCA               500

/**
 * Sleep clock accuracy in Coordinator role
 */
#define CFG_BLE_MASTER_SCA              0

/**
 * Low Speed Clock Source used by the Bluetooth Stack
 */
#define CFG_BLE_LSE_SOURCE              1

/**
 * Start up time of the high speed (16 or 32 MHz) crystal oscillator in units of 625/256 us (~2.44 us)
 */
#define CFG_BLE_HSE_STARTUP_TIME        0x148

/**
 * Maximum duration of the connection event when the device is in Slave mode in units of 625/256 us (~2.44 us)
 */
#define CFG_BLE_MAX_CONN_EVENT_LENGTH   0xFFFFFFFF

/**
 * Viterbi Mode
 */
#define CFG_BLE_VITERBI_MODE            1

/**
 * BLE Options flags to be configured with SHCI_C2_BLE_Init
 */
#define CFG_BLE_OPTIONS                 0x0

/**
 * Maximum number of connection-oriented channels in initiator mode
 */
#define CFG_BLE_MAX_COC_INITIATOR_NBR   32

/**
 * Minimum transmit power in dBm supported by the Controller
 */
#define CFG_BLE_MIN_TX_POWER            0

/**
 * Maximum transmit power in dBm supported by the Controller
 */
#define CFG_BLE_MAX_TX_POWER            0

/**
 * BLE Rx model configuration flags to be configured with SHCI_C2_BLE_Init
 */
#define CFG_BLE_RX_MODEL_CONFIG         1

/**
 * Maximum advertising set number
 */
#define CFG_BLE_MAX_ADV_SET_NBR         1

/**
 * Maximum advertising data length (in bytes)
 */
#define CFG_BLE_MAX_ADV_DATA_LEN        31

/**
 * RF TX Path Compensation Value (16-bit signed integer). Units: 0.1 dB
 */
#define CFG_BLE_TX_PATH_COMPENS         0

/**
 * RF RX Path Compensation Value (16-bit signed integer). Units: 0.1 dB
 */
#define CFG_BLE_RX_PATH_COMPENS         0

/**
 * BLE core version (16-bit signed integer).
 */
#define CFG_BLE_CORE_VERSION            0

/**
 * Options flags extension to be configured with SHCI_C2_BLE_Init
 */
#define CFG_BLE_OPTIONS_EXT             0

/* Memory requirements */
#define DIVC(x,y)               (((x)+(y)-1)/(y))

/**
 * FLASH
 */
#define CFG_SNVMA_START_SECTOR_ID     (FLASH_PAGE_NB - CFG_SNVMA_NBR_OF_SECTORS)
#define CFG_SNVMA_NBR_OF_SECTORS      (2)

/**
 * SRAM1
 */
#define CFG_SRAM1_TOTAL_SIZE            (64*1024)
#define CFG_SRAM1_APP_SIZE              (60*1024)

/**
 * SRAM2
 */
#define CFG_SRAM2_TOTAL_SIZE            (32*1024)

#endif /*APP_CONF_H */ 