/********************************************************************************************************
 * @file    ble_flash.h
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
#ifndef BLE_FLASH_H_
#define BLE_FLASH_H_


#include "drivers.h"
#include "vendor/common/user_config.h"


/**
 * @brief	128 K Flash MAC address and calibration data area
 */
#ifndef		CFG_ADR_MAC_128K_FLASH
#define		CFG_ADR_MAC_128K_FLASH								0x1F000
#endif

#ifndef		CFG_ADR_CALIBRATION_128K_FLASH
#define		CFG_ADR_CALIBRATION_128K_FLASH						0x1E000
#endif

#ifndef 	FLASH_ADR_SMP_PAIRING_128K_FLASH
#define 	FLASH_ADR_SMP_PAIRING_128K_FLASH         			0x1C000
#endif
/**
 * @brief	512 K Flash MAC address and calibration data area
 */
#ifndef		CFG_ADR_MAC_512K_FLASH
#define		CFG_ADR_MAC_512K_FLASH								0x7F000
#endif

#ifndef		CFG_ADR_CALIBRATION_512K_FLASH
#define		CFG_ADR_CALIBRATION_512K_FLASH						0x7E000
#endif

#ifndef 	FLASH_ADR_SMP_PAIRING_512K_FLASH
#define 	FLASH_ADR_SMP_PAIRING_512K_FLASH         			0x7C000
#endif


/********************** Master pairing flash address *******************/
#ifndef 	FLASH_ADR_MASTER_PAIRING_128K
#define 	FLASH_ADR_MASTER_PAIRING_128K         				0x1C000
#endif

#ifndef 	FLASH_ADR_MASTER_PAIRING_512K
#define 	FLASH_ADR_MASTER_PAIRING_512K         				0x7C000
#endif



/**
 * @brief	Flash size option supported by this SDK
 */
#define		FLASH_SIZE_OPTION_128K			   					0x20000
#define		FLASH_SIZE_OPTION_512K			   					0x80000



#ifndef		FLASH_SIZE_OPTION
#define		FLASH_SIZE_OPTION		   							FLASH_SIZE_OPTION_128K
#endif











/** Calibration Information FLash Address Offset of  CFG_ADR_CALIBRATION_xx_FLASH ***/
#define		CALIB_OFFSET_CAP_INFO								0x00
#define		CALIB_OFFSET_TP_INFO								0x40
#define		CALIB_OFFSET_ADC_VREF								0xC0
#define		CALIB_OFFSET_FIRMWARE_SIGNKEY						0x180



extern	unsigned int  blc_flash_mid;
extern	unsigned int  blc_flash_vendor;
extern	unsigned char blc_flash_capacity;

extern  unsigned int  flash_sector_mac_address;
extern  unsigned int  flash_sector_calibration;
extern  unsigned int  flash_sector_smp_storage;
extern  unsigned int  flash_sector_master_pairing;


/**
 * @brief   BLE parameters on flash
 */
typedef struct{
	u8		cap_frqoffset_en;
	u8		cap_frqoffset_value;

}nv_para_t;

_attribute_data_retention_ 	nv_para_t 				blc_nvParam;


/**
 * @brief		load customized parameters (from Flash) when MCU power on or wake_up from deepSleep mode
 * @param[in]	none
 * @return      none
 */
static inline void blc_app_loadCustomizedParameters_normal(void)
{
	/* read and set RF frequency offset capacitance calibration value from Flash */
	if(!blt_miscParam.ext_cap_en){
		if(flash_sector_calibration){
			unsigned char customed_cap;
			flash_read_page(flash_sector_calibration + CALIB_OFFSET_CAP_INFO, 1, &customed_cap);

			/* customize freq_offset adjust cap value, if not customized, default ana_8a is 0xd0 */
			if( customed_cap != 0xFF ){
				blc_nvParam.cap_frqoffset_en = 1;
				blc_nvParam.cap_frqoffset_value = customed_cap;
				analog_write(0x8a,(analog_read(0x8a)&0x40)|(blc_nvParam.cap_frqoffset_value&0x3f));
			}
		}
	}

	/* read and set ADC V_reference calibration value from OTP */
	user_calib_adc_vref();

    //If the flash is ZG25WD40B, the flash voltage(VDD_F) will be trim to 2.25V(2b'111 the max).
	if(blc_flash_mid == 0x13325e)
	{
		pm_set_vdd_f(FLASH_VOLTAGE_2V25);
	}
}

/**
 * @brief		load customized parameters (from SRAM) when MCU wake_up from deepSleep_retention mode
 * @param[in]	none
 * @return      none
 */
static inline void blc_app_loadCustomizedParameters_deepRetn(void)
{
	/* set RF frequency offset capacitance calibration value with stored variables */
	if(blc_nvParam.cap_frqoffset_en) {
		analog_write(0x8a,(analog_read(0x8a)&0x40)|(blc_nvParam.cap_frqoffset_value&0x3f));
	}

	/* ADC V_reference calibration value is stored in variables on retention area, so no need set again */
	//If the flash is ZG25WD40B, the flash voltage(VDD_F) will be trim to 2.25V(2b'111 the max).
	if(blc_flash_mid == 0x13325e)
	{
		pm_set_vdd_f(FLASH_VOLTAGE_2V25);
	}
}


/**
 * @brief		This function is used to initialize the MAC address
 * @param[in]	flash_addr - flash address for MAC address
 * @param[in]	mac_public - public address
 * @param[in]	mac_random_static - random static MAC address
 * @return      none
 */
void blc_initMacAddress(int flash_addr, u8 *mac_public, u8 *mac_random_static);


/**
 * @brief		This function can automatically recognize the flash size,
 * 				and the system selects different customized sector according
 * 				to different sizes.
 * @param[in]	none
 * @return      none
 */
void blc_readFlashSize_autoConfigCustomFlashSector(void);



#endif /* BLT_COMMON_H_ */
