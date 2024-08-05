/********************************************************************************************************
 * @file    user_config.h
 *
 * @brief   This is the header file for BLE SDK
 *
 * @author  BLE GROUP
 * @date    12,2021
 *
 * @par     Copyright (c) 2021, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *
 *          Licensed under the Apache License, Version 2.0 (the "License");
 *          you may not use this file except in compliance with the License.
 *          You may obtain a copy of the License at
 *
 *              http://www.apache.org/licenses/LICENSE-2.0
 *
 *          Unless required by applicable law or agreed to in writing, software
 *          distributed under the License is distributed on an "AS IS" BASIS,
 *          WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *          See the License for the specific language governing permissions and
 *          limitations under the License.
 *
 *******************************************************************************************************/
#pragma once


#if(__PROJECT_B80_BLE_SAMPLE__)
	#include "vendor/ble_sample/app_config.h"
#elif(__PROJECT_B80_BLE_FEATURE__)
	#include "vendor/feature_test/app_config.h"
#elif(__PROJECT_B80_MODULE__)
	#include "vendor/ble_module/app_config.h"
#elif(__PROJECT_B80_MASTER__)
	#include "vendor/ble_master/app_config.h"
#else
	#include "../common/default_config.h"
#endif

