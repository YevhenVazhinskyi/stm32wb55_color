/**
 * @file: ble__service.h
 * @description: BLE service for LED control communication
 * @dependencies: stm32wbxx_hal.h, led__driver.h
 * @created: 2024-12-19
 */

#ifndef BLE_SERVICE_H
#define BLE_SERVICE_H

#include "stm32wbxx_hal.h"
#include "led__driver.h"

// STM32WB55 BLE stack includes (conditional compilation)
#ifdef STM32_WPAN_ENABLED
#include "app_common.h"
#include "ble.h"
#include "tl.h"
#include "shci.h"
#include "shci_tl.h"
#include "stm32_wpan_common.h"
#include "ble_gap_aci.h"
#include "ble_gatt_aci.h"
#include "ble_hal_aci.h"
#include "ble_hci_le.h"
#include "ble_l2cap_aci.h"
#include "hci_tl.h"
#include "osal.h"
#else
// Temporary stub definitions for compilation without STM32_WPAN middleware
typedef uint8_t tBleStatus;
typedef uint16_t Service_UUID_t;
typedef uint16_t Char_UUID_t;

#define BLE_STATUS_SUCCESS              0x00
#define UUID_TYPE_128                   0x02
#define PRIMARY_SERVICE                 0x01
#define CHAR_PROP_READ                  0x02
#define CHAR_PROP_WRITE                 0x08
#define CHAR_PROP_NOTIFY                0x10
#define ATTR_PERMISSION_NONE            0x00
#define GATT_NOTIFY_ATTRIBUTE_WRITE     0x01
#define GATT_DONT_NOTIFY_EVENTS         0x00
#define ADV_IND                         0x00
#define PUBLIC_ADDR                     0x00
#define NO_WHITE_LIST_USE               0x00
#define GAP_PERIPHERAL_ROLE             0x01

// Placeholder types
typedef struct {
    uint8_t p_cmdbuffer;
    void* StatusNotCallBack;
} SHCI_TL_HciInitConf_t;

typedef struct {
    uint8_t p_cmdbuffer;
    void* StatusNotCallBack;
} SHCI_TL_Init_Conf_t;

typedef struct {
    uint8_t header[3];
    uint8_t param[32];
} SHCI_C2_Ble_Init_Cmd_Packet_t;

typedef enum {
    HCI_TL_CmdBusy,
    HCI_TL_CmdAvailable
} HCI_TL_CmdStatus_t;

typedef enum {
    SHCI_TL_CmdBusy,
    SHCI_TL_CmdAvailable
} SHCI_TL_CmdStatus_t;

// Stub function declarations
tBleStatus aci_gatt_add_service(uint8_t uuid_type, Service_UUID_t* uuid, uint8_t service_type, uint8_t max_attr_records, uint16_t* service_handle);
tBleStatus aci_gatt_add_char(uint16_t service_handle, uint8_t uuid_type, Char_UUID_t* uuid, uint8_t char_value_len, uint8_t char_properties, uint8_t attr_permissions, uint8_t gatt_evt_mask, uint8_t enc_key_size, uint8_t is_variable, uint16_t* char_handle);
tBleStatus aci_gap_set_discoverable(uint8_t advertising_type, uint16_t advertising_interval_min, uint16_t advertising_interval_max, uint8_t own_address_type, uint8_t advertising_filter_policy, uint8_t local_name_len, const char* local_name, uint8_t service_uuid_len, uint8_t* service_uuid_list, uint16_t slave_conn_interval_min, uint16_t slave_conn_interval_max);
tBleStatus aci_gap_set_non_discoverable(void);
tBleStatus aci_gatt_update_char_value(uint16_t service_handle, uint16_t char_handle, uint8_t val_offset, uint8_t char_value_len, uint8_t* char_value);
tBleStatus aci_gatt_init(void);
tBleStatus aci_gap_init(uint8_t role, uint8_t privacy_enabled, uint8_t max_attribute_records, uint16_t* service_handle, uint16_t* dev_name_char_handle, uint16_t* appearance_char_handle);
#endif // STM32_WPAN_ENABLED

// BLE Service UUIDs (as strings for reference)
#define LED_SERVICE_UUID        "12345678-1234-1234-1234-123456789ABC"
#define LED_STATE_CHAR_UUID     "87654321-4321-4321-4321-CBA987654321"
#define LED_INDIVIDUAL_CHAR_UUID "11111111-2222-3333-4444-555555555555"
#define SYSTEM_STATUS_CHAR_UUID "AAAAAAAA-BBBB-CCCC-DDDD-EEEEEEEEEEEE"

// BLE connection states
typedef enum {
    BLE_STATE_DISCONNECTED = 0,
    BLE_STATE_ADVERTISING,
    BLE_STATE_CONNECTED,
    BLE_STATE_ERROR
} ble_state_t;

// BLE service structure
typedef struct {
    ble_state_t state;
    uint8_t device_connected;
    uint16_t led_state_char_handle;
    uint16_t led_individual_char_handle;
    uint16_t system_status_char_handle;
} ble_service_t;

// Function prototypes
void ble_service_init(void);
void ble_service_process(void);
ble_state_t ble_service_get_state(void);
tBleStatus ble_service_start_advertising(void);
void ble_service_stop_advertising(void);
void ble_service_notify_led_state(uint8_t state_mask);
void ble_service_notify_system_status(uint32_t status);

// BLE event callbacks
void ble_service_on_connect(void);
void ble_service_on_disconnect(void);
void ble_service_on_led_state_write(uint8_t *data, uint16_t length);
void ble_service_on_led_individual_write(uint8_t *data, uint16_t length);

#endif // BLE_SERVICE_H