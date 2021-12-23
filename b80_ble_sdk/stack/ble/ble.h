/********************************************************************************************************
 * @file     ble.h 
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
/*
 * ble.h
 *
 *  Created on: 2018-5-25
 *      Author: Administrator
 */

#ifndef BLE_H_
#define BLE_H_


#include "ble_common.h"
#include "ble_format.h"

#include "controller/ble_controller.h"
#include "host/ble_host.h"

#include "hci/hci.h"
#include "hci/hci_const.h"
#include "hci/hci_cmd.h"
#include "hci/hci_event.h"

#include "service/ota/ota.h"
#include "service/device_information.h"
#include "service/hids.h"
#include "service/uuid.h"


#include "algorithm/aes_ccm/aes_ccm.h"
#include "algorithm/ecc/ecc_ll.h"
#include "algorithm/ecc/hw_ecc.h"
#include "algorithm/ecc/sw_ecc.h"


#endif /* BLE_H_ */
