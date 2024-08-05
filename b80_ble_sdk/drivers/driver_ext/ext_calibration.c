/********************************************************************************************************
 * @file    ext_calibration.c
 *
 * @brief   This is the source file for BLE SDK
 *
 * @author  BLE GROUP
 * @date    12,2021
 *
 * @par     Copyright (c) 2018, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
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
#include "ext_calibration.h"
#include "drivers.h"
#include "vendor/common/ble_flash.h"

/**
 * @brief		This function is used to Tighten the judgment of illegal values for gpio calibration and vbat calibration in the otp.
 *              The ADC vref gain calibration should range from 1100mV to 1300mV, the ADC vref offset calibration should range from -40mV to 100mV.
 * @param[in]   gain - the value of gpio_calib_vref_gain or vbat_calib_vref_gain
 *              offset - the value of gpio_calib_vref_offset or vbat_calib_vref_offset
 *              calib_func - Function pointer to gpio_calibration or vbat_calibration.
 * @return		false:the calibration function is invalid; true:the calibration function is valid.
 */
bool adc_update_vref_calib_value_ft_cp(unsigned char gain, signed char offset, void (*calib_func)(unsigned short, signed char))
{
	/**
	 * The stored offset value is not of "signed" type, and the ATE writes the offset value with the following rules:
	 * Bit[7] = 1 for negative value, Bit[7] = 0 for positive value, and the absolute value of Bit[0:6] indicates the absolute value of the offset.
	 * Therefore, after taking out the offset value, it needs to be converted to "signed" type.
	 */
	offset = (offset & BIT(7)) ? ((-1) * (offset & 0x7f)) : offset;
	if((gain >= 100) && (offset >= -20) && (offset <= 120))
	{
		(*calib_func)(gain+1000, offset-20);
		return 1;
	}
	else
	{
		return 0;
	}
}

/**
 * @brief      This function is used to calib ADC 1.2V vref.
 */
int user_calib_adc_vref(void)
{
	u8 adc_vref_ft_calib_value[4] = {0};
	u8 adc_vref_cp_calib_value[4] = {0};
	otp_set_active_mode();
	otp_read(0x3fcc, 1, (u32*)adc_vref_ft_calib_value);
	otp_read(0x3fd0, 1, (u32*)adc_vref_cp_calib_value);
	otp_set_deep_standby_mode();
	if(!adc_update_vref_calib_value_ft_cp(adc_vref_ft_calib_value[0],(signed char)adc_vref_ft_calib_value[1],adc_set_gpio_calib_vref))//gpio_ft
	{
		adc_update_vref_calib_value_ft_cp(adc_vref_cp_calib_value[0],(signed char)adc_vref_cp_calib_value[1],adc_set_gpio_calib_vref);//gpio_cp
	}
	if(!adc_update_vref_calib_value_ft_cp(adc_vref_ft_calib_value[2],(signed char)adc_vref_ft_calib_value[3],adc_set_vbat_calib_vref))//vbat_ft
	{
		adc_update_vref_calib_value_ft_cp(adc_vref_cp_calib_value[2],(signed char)adc_vref_cp_calib_value[3],adc_set_vbat_calib_vref);//vbat_cp
	}
	return 0;
}



