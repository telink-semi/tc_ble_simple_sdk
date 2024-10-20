/********************************************************************************************************
 * @file    battery_check.h
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
#ifndef BATTERY_CHECK_H_
#define BATTERY_CHECK_H_


/**
 * @brief	Application battery check enable control. Default disable, use can enable it in app_conifg.h.
 	 	 	User must check battery voltage on mass production application to prevent abnormal writing or erasing Flash at a low voltage !!!
 */
#ifndef APP_BATT_CHECK_ENABLE
#define APP_BATT_CHECK_ENABLE								0
#endif

#if (APP_BATT_CHECK_ENABLE)

extern u8 adc_hw_initialized;

/**
 * @brief		set lowBattery detect enable
 * @param[in]	en - lowBattDet_enable value
 * @return      none
 */
void battery_set_detect_enable (int en);

/**
 * @brief		get the value of lowBattDet_enable
 * @param[in]	none
 * @return      the value of lowBattDet_enable
 */
int  battery_get_detect_enable (void);

/**
 * @brief		This is battery check function
 * @param[in]	alarm_vol_mv - input battery calibration
 * @return      0: batt_vol_mv < alarm_vol_mv 1: batt_vol_mv > alarm_vol_mv
 */
int app_battery_power_check(unsigned short alarm_vol_mv);

#endif

#endif /* BATTERY_CHECK_H_ */
