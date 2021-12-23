/********************************************************************************************************
 * @file     att.h 
 *
 * @brief    for TLSR chips
 *
 * @author	 BLE Group
 * @date     Sep. 18, 2015
 *
 * @par      Copyright (c) Telink Semiconductor (Shanghai) Co., Ltd.
 *           All rights reserved.
 *           
 *			 The information contained herein is confidential and proprietary property of Telink 
 * 		     Semiconductor (Shanghai) Co., Ltd. and is available under the terms 
 *			 of Commercial License Agreement between Telink Semiconductor (Shanghai) 
 *			 Co., Ltd. and the licensee in separate contract or the terms described here-in. 
 *           This heading MUST NOT be removed from this file.
 *
 * 			 Licensees are granted free, non-transferable use of the information in this 
 *			 file under Mutual Non-Disclosure Agreement. NO WARRENTY of ANY KIND is provided. 
 *           
 *******************************************************************************************************/

#pragma once

#include "tl_common.h"


/** @defgroup ATT_PERMISSIONS_BITMAPS GAP ATT Attribute Access Permissions Bit Fields
 * @{
 * (See the Core_v5.0(Vol 3/Part C/10.3.1/Table 10.2) for more information)
 */
#define ATT_PERMISSIONS_READ                 0x01 //!< Attribute is Readable
#define ATT_PERMISSIONS_WRITE                0x02 //!< Attribute is Writable
#define ATT_PERMISSIONS_AUTHEN_READ          0x04 //!< Read requires Authentication
#define ATT_PERMISSIONS_AUTHEN_WRITE         0x08 //!< Write requires Authentication
#define ATT_PERMISSIONS_AUTHOR_READ          0x10 //!< Read requires Authorization
#define ATT_PERMISSIONS_AUTHOR_WRITE         0x20 //!< Write requires Authorization
#define ATT_PERMISSIONS_ENCRYPT_READ         0x40 //!< Read requires Encryption
#define ATT_PERMISSIONS_ENCRYPT_WRITE        0x80 //!< Write requires Encryption

#define ATT_PERMISSIONS_RDWR	             0x03  // ATT_PERMISSIONS_READ | ATT_PERMISSIONS_WRITE

/** @} End GAP_ATT_PERMISSIONS_BITMAPS */



/** @addtogroup GATT_Characteristic_Property GATT characteristic properties
 * @{
 */
#define CHAR_PROP_BROADCAST              0x01 //!< permit broadcasts of the Characteristic Value
#define CHAR_PROP_READ                   0x02 //!< permit reads of the Characteristic Value
#define CHAR_PROP_WRITE_WITHOUT_RSP      0x04 //!< Permit writes of the Characteristic Value without response
#define CHAR_PROP_WRITE                  0x08 //!< Permit writes of the Characteristic Value with response
#define CHAR_PROP_NOTIFY                 0x10 //!< Permit notifications of a Characteristic Value without acknowledgement
#define CHAR_PROP_INDICATE               0x20 //!< Permit indications of a Characteristic Value with acknowledgement
#define CHAR_PROP_AUTHEN                 0x40 //!< permit signed writes to the Characteristic Value
#define CHAR_PROP_EXTENDED               0x80 //!< additional characteristic properties are defined
/** @} end of group GATT_Characteristic_Property */









typedef int (*att_handleValueConfirm_callback_t)(void);
typedef int (*att_readwrite_callback_t)(void* p);
typedef void (*attRxMtuSizeExchangeCommpleteCb)(u16 connHandle, u16 remoteMtuSize, u16 effectMtuSize);

typedef struct attribute
{
  u16 attNum;
  u8  perm;
  u8  uuidLen;
  u32 attrLen;    //4 bytes aligned
  u8* uuid;
  u8* pAttrValue;
  att_readwrite_callback_t w;
  att_readwrite_callback_t r;
} attribute_t;






typedef struct{
	u16 init_MTU;
	u16 effective_MTU;

	u8 *pPendingPkt;

	u8 Data_pending_time;    //10ms unit
	u8 mtu_exchange_pending;
}att_para_t;
extern att_para_t bltAtt;

extern u8 blt_indicate_handle;

/******************************* User Interface  ************************************/
//GATT server table
void bls_att_setAttributeTable(u8 *p);

//ATT notification
ble_sts_t blc_gatt_pushHandleValueNotify(u16 attHandle, u8 *p, int len);

//ATT indicator/confirm
ble_sts_t bls_att_pushIndicateData(u16 attHandle, u8 *p, int len);

void bls_att_registerHandleValueConfirmCb(att_handleValueConfirm_callback_t cb);

//MTU size
ble_sts_t blc_att_setRxMtuSize(u16 mtu_size);
ble_sts_t blc_att_requestMtuSizeExchange(u16 connHandle, u16 mtu_size);
void blc_att_registerMtuSizeExchangeCb(attRxMtuSizeExchangeCommpleteCb cb);
void blt_att_resetMtuSizeToDefault(void);
/**
 * @brief   This function is used to get effective MTU size.
 * @param	connHandle - connect handle
 * @return  effective MTU value.
 */
u16  blc_att_getEffectiveMtuSize(void);

// 0x04: ATT_OP_FIND_INFO_REQ
void att_req_find_info(u8 *dat, u16 start_attHandle, u16 end_attHandle);
// 0x06: ATT_OP_FIND_BY_TYPE_VALUE_REQ
void att_req_find_by_type (u8 *dat, u16 start_attHandle, u16 end_attHandle, u8 *uuid, u8* attr_value, int len);
// 0x08: ATT_OP_READ_BY_TYPE_REQ
void att_req_read_by_type (u8 *dat, u16 start_attHandle, u16 end_attHandle, u8 *uuid, int uuid_len);
// 0x0a: ATT_OP_READ_REQ
void att_req_read (u8 *dat, u16 attHandle);
// 0x0c: ATT_OP_READ_BLOB_REQ
void att_req_read_blob (u8 *dat, u16 attHandle, u16 offset);
// 0x10: ATT_OP_READ_BY_GROUP_TYPE_REQ
void att_req_read_by_group_type (u8 *dat, u16 start_attHandle, u16 end_attHandle, u8 *uuid, int uuid_len);
// 0x12: ATT_OP_WRITE_REQ
void att_req_write (u8 *dat, u16 attHandle, u8 *buf, int len);
// 0x52: ATT_OP_WRITE_CMD
void att_req_write_cmd (u8 *dat, u16 attHandle, u8 *buf, int len);

ble_sts_t bls_att_setDeviceName(u8* pName,u8 len);  //only module/mesh/hci use


int l2cap_att_client_handler (u16 conn, u8 *p);
