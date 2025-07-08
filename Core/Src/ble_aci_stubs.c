/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    ble_aci_stubs.c
  * @author  STM32WB55 BLE LED Control Project
  * @brief   Stub functions for BLE ACI commands that run on CPU2.
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
#include "ble.h"
#include "ble_gatt_aci.h"
#include "ble_gap_aci.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
 * @brief Stub for aci_gatt_init
 * @note In real implementation, this would be handled by HCI commands to CPU2
 */
tBleStatus aci_gatt_init(void)
{
    // TODO: Send HCI command to CPU2 to initialize GATT
    return BLE_STATUS_SUCCESS;
}

/**
 * @brief Stub for aci_gap_init
 * @note In real implementation, this would be handled by HCI commands to CPU2
 */
tBleStatus aci_gap_init(uint8_t role, uint8_t privacy_enabled, uint8_t device_name_char_len, 
                        uint16_t* service_handle, uint16_t* dev_name_char_handle, 
                        uint16_t* appearance_char_handle)
{
    // TODO: Send HCI command to CPU2 to initialize GAP
    (void)role;
    (void)privacy_enabled;
    (void)device_name_char_len;
    if (service_handle) *service_handle = 0x0001;
    if (dev_name_char_handle) *dev_name_char_handle = 0x0002;
    if (appearance_char_handle) *appearance_char_handle = 0x0003;
    return BLE_STATUS_SUCCESS;
}

/**
 * @brief Stub for aci_gatt_add_service
 * @note In real implementation, this would be handled by HCI commands to CPU2
 */
tBleStatus aci_gatt_add_service(uint8_t service_uuid_type, const Service_UUID_t* service_uuid, 
                                uint8_t service_type, uint8_t max_attr_records, uint16_t* service_handle)
{
    // TODO: Send HCI command to CPU2 to add GATT service
    (void)service_uuid_type;
    (void)service_uuid;
    (void)service_type;
    (void)max_attr_records;
    if (service_handle) *service_handle = 0x0010; // Dummy handle
    return BLE_STATUS_SUCCESS;
}

/**
 * @brief Stub for aci_gatt_add_char
 * @note In real implementation, this would be handled by HCI commands to CPU2
 */
tBleStatus aci_gatt_add_char(uint16_t service_handle, uint8_t char_uuid_type, const Char_UUID_t* char_uuid,
                             uint16_t char_value_len, uint8_t char_properties, uint8_t sec_permissions,
                             uint8_t gatt_evt_mask, uint8_t encry_key_size, uint8_t is_variable,
                             uint16_t* char_handle)
{
    // TODO: Send HCI command to CPU2 to add GATT characteristic
    (void)service_handle;
    (void)char_uuid_type;
    (void)char_uuid;
    (void)char_value_len;
    (void)char_properties;
    (void)sec_permissions;
    (void)gatt_evt_mask;
    (void)encry_key_size;
    (void)is_variable;
    if (char_handle) *char_handle = 0x0020; // Dummy handle
    return BLE_STATUS_SUCCESS;
}

/**
 * @brief Stub for aci_gatt_update_char_value
 * @note In real implementation, this would be handled by HCI commands to CPU2
 */
tBleStatus aci_gatt_update_char_value(uint16_t service_handle, uint16_t char_handle,
                                      uint8_t val_offset, uint8_t char_val_len, const uint8_t* char_value)
{
    // TODO: Send HCI command to CPU2 to update characteristic value
    (void)service_handle;
    (void)char_handle;
    (void)val_offset;
    (void)char_val_len;
    (void)char_value;
    return BLE_STATUS_SUCCESS;
}

/**
 * @brief Stub for aci_gap_set_discoverable
 * @note In real implementation, this would be handled by HCI commands to CPU2
 */
tBleStatus aci_gap_set_discoverable(uint8_t advertising_type, uint16_t advertising_interval_min,
                                    uint16_t advertising_interval_max, uint8_t own_address_type,
                                    uint8_t advertising_filter_policy, uint8_t local_name_len,
                                    const uint8_t* local_name, uint8_t service_uuid_len, const uint8_t* service_uuid_list,
                                    uint16_t slave_conn_interval_min, uint16_t slave_conn_interval_max)
{
    // TODO: Send HCI command to CPU2 to start advertising
    (void)advertising_type;
    (void)advertising_interval_min;
    (void)advertising_interval_max;
    (void)own_address_type;
    (void)advertising_filter_policy;
    (void)local_name_len;
    (void)local_name;
    (void)service_uuid_len;
    (void)service_uuid_list;
    (void)slave_conn_interval_min;
    (void)slave_conn_interval_max;
    return BLE_STATUS_SUCCESS;
}

/**
 * @brief Stub for aci_gap_set_non_discoverable
 * @note In real implementation, this would be handled by HCI commands to CPU2
 */
tBleStatus aci_gap_set_non_discoverable(void)
{
    // TODO: Send HCI command to CPU2 to stop advertising
    return BLE_STATUS_SUCCESS;
} 