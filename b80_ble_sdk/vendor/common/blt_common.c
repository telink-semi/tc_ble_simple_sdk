/********************************************************************************************************
 * @file	blt_common.c
 *
 * @brief	This is the source file for BLE SDK
 *
 * @author	BLE GROUP
 * @date	2020.06
 *
 * @par     Copyright (c) 2020, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *          All rights reserved.
 *
 *          Redistribution and use in source and binary forms, with or without
 *          modification, are permitted provided that the following conditions are met:
 *
 *              1. Redistributions of source code must retain the above copyright
 *              notice, this list of conditions and the following disclaimer.
 *
 *              2. Unless for usage inside a TELINK integrated circuit, redistributions
 *              in binary form must reproduce the above copyright notice, this list of
 *              conditions and the following disclaimer in the documentation and/or other
 *              materials provided with the distribution.
 *
 *              3. Neither the name of TELINK, nor the names of its contributors may be
 *              used to endorse or promote products derived from this software without
 *              specific prior written permission.
 *
 *              4. This software, with or without modification, must only be used with a
 *              TELINK integrated circuit. All other usages are subject to written permission
 *              from TELINK and different commercial license may apply.
 *
 *              5. Licensee shall be solely responsible for any claim to the extent arising out of or
 *              relating to such deletion(s), modification(s) or alteration(s).
 *
 *          THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *          ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *          WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *          DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDER BE LIABLE FOR ANY
 *          DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *          (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *          LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *          ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *          (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *          SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *******************************************************************************************************/
#include "tl_common.h"
#include "drivers.h"
#include "blt_common.h"

#if 0//Flash size auto check.

u32 flash_sector_mac_address = CFG_ADR_MAC_128K_FLASH;			//default flash is 128k
u32 flash_sector_calibration = CFG_ADR_CALIBRATION_128K_FLASH;	//default flash is 128k

void blc_readFlashSize_autoConfigCustomFlashSector(void)
{
//	u8 temp_buf[4];
//	flash_read_mid(temp_buf);
//	u8	flash_cap = temp_buf[2];

	u32 flashMid;
	u8 flashUid[16];
	flash_read_mid_uid_with_check(&flashMid, &flashUid[0]);
	u8	flash_cap = (flashMid>>16);

	if(flash_cap == FLASH_SIZE_128K){
		flash_sector_mac_address = CFG_ADR_MAC_128K_FLASH;
		flash_sector_calibration = CFG_ADR_CALIBRATION_128K_FLASH;
	}
	else if(flash_cap == FLASH_SIZE_512K){
		flash_sector_mac_address = CFG_ADR_MAC_512K_FLASH;
		flash_sector_calibration = CFG_ADR_CALIBRATION_512K_FLASH;
	}
	else{
		//This SDK do not support flash size other than 512K/1M
		//If code stop here, please check your Flash
		while(1);
	}


//	flash_set_capacity(flash_cap);
}
#endif

/*
 * VVWWXX38C1A4YYZZ
 * public_mac: 		  VVWWXX 38C1A4
 * random_static_mac: VVWWXXYYZZ C0
 */

void blc_initMacAddress(int flash_addr, u8 *mac_public, u8 *mac_random_static)
{
//	u8  mac_public[6] 		 = {0x00, 0x00, 0x00, 0x38, 0xC1, 0xA4};  //company id: 0xA4C138
//	u8  mac_random_static[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xC0};

	u8 mac_read[8];
	flash_read_page(flash_addr, 8, mac_read);

	u8 value_rand[5];
	generateRandomNum(5, value_rand);

	u8 ff_six_byte[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
	if ( memcmp(mac_read, ff_six_byte, 6) ) {
		memcpy(mac_public, mac_read, 6);  //copy public address from flash
	}
	else{  //no public address on flash
		mac_public[0] = value_rand[0];
		mac_public[1] = value_rand[1];
		mac_public[2] = value_rand[2];
		mac_public[3] = 0x38;             //company id: 0xA4C138
		mac_public[4] = 0xC1;
		mac_public[5] = 0xA4;

		flash_write_page (flash_addr, 6, mac_public);
	}

	mac_random_static[0] = mac_public[0];
	mac_random_static[1] = mac_public[1];
	mac_random_static[2] = mac_public[2];
	mac_random_static[5] = 0xC0; 			//for random static

	u16 high_2_byte = (mac_read[6] | mac_read[7]<<8);
	if(high_2_byte != 0xFFFF){
		memcpy( (u8 *)(mac_random_static + 3), (u8 *)(mac_read + 6), 2);
	}
	else{
		mac_random_static[3] = value_rand[3];
		mac_random_static[4] = value_rand[4];

		flash_write_page (flash_addr + 6, 2, (u8 *)(mac_random_static + 3) );
	}
}

